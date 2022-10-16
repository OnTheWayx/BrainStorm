#include "fileserver.h"


FileServer::FileServer()
{
#ifdef DEBUG
    _log = spdlog::stdout_color_mt("console_file");
#else
    _log = spdlog::rotating_logger_mt("BrainStorm", "BrainStorm", 1024 * 1024 * 5, 3);
    _log->flush_on(spdlog::level::info);
#endif
}

int FileServer::init(int port, const char *ip)
{
    // 初始化启动标志
    m_shutdown = 0;

    // 创建相应套接字
    m_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (m_fd == -1)
    {
        _log->error("create fd error");
        return FAILURE;
    }

    int ret;

    m_server_len = sizeof(m_server_addr);
    memset(&m_server_addr, 0, m_server_len);

    m_server_addr.sin_family = AF_INET;
    m_server_addr.sin_addr.s_addr = inet_addr(ip);
    m_server_addr.sin_port = htons(port);

    //设置地址可以被重复绑定
    int opt = 1;
    ret = setsockopt(m_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    //绑定套接字与网络信息结构体
    ret = bind(m_fd, (struct sockaddr *)&m_server_addr, m_server_len);
    if (-1 == ret)
    {
        _log->error("bind error");
        close(m_fd);

        return FAILURE;
    }

    //设置监听队列
    ret = listen(m_fd, CLIENT_MAXSIZE);
    if (-1 == ret)
    {
        _log->error("listen");
        close(m_fd);

        return FAILURE;
    }

    // 设置套接字为非阻塞
    int flg;

    flg = fcntl(m_fd, F_GETFL);
    flg |= O_NONBLOCK;
    ret = fcntl(m_fd, F_SETFL, flg);
    if (ret == -1)
    {
        _log->error("set fd o_nonblock error.\n");

        return FAILURE;
    }

    return SUCCESS;
}

void FileServer::start()
{
    FileServer::AcceptClient(this);

    return;
}

void FileServer::AcceptClient(void *arg)
{
    FileServer *myserver = static_cast<FileServer *>(arg);

    // 创建相应的线程为new_fd服务
    pthread_t new_pthread_id;

    clientinfo *info;
    struct sockaddr_in client_addr;
    socklen_t client_len;
    struct epoll_event ev;

    int ret;

    while (!myserver->m_shutdown)
    {
        // 处理客户端连接

        int new_fd = accept(myserver->m_fd, (struct sockaddr *)&client_addr, &client_len);
        if (-1 == new_fd)
        {
            if (errno == EAGAIN || errno == EWOULDBLOCK)
            {
                usleep(100000);
                continue;
            }
            myserver->_log->error("accept  error");
        }
        myserver->_log->info("有客户端请求连接");
        myserver->_log->info("accept  [{}:{}]",  inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        try
        {
            info = new clientinfo;
        }
        catch (std::bad_alloc &e)
        {
            e.what();
            // 错误，关闭连接
            close(new_fd);
        }

        info->ptr = arg;
        info->fd = new_fd;
        ret = pthread_create(&new_pthread_id, NULL, FileServer::ClientHandler, info);
        if (ret != 0)
        {
            myserver->_log->error("pthread_create");
        }
    }
}

void *FileServer::ClientHandler(void *arg)
{
    clientinfo *info = static_cast<clientinfo *>(arg);
    FileServer *myserver = static_cast<FileServer *>(info->ptr);

    int flg, ret;

    if (pthread_detach(pthread_self()) != 0)
    {
        myserver->_log->error("set thread:{} detach failed.", pthread_self());
    }
    while (1)
    {
        ret = recv(info->fd, &flg, sizeof(flg), MSG_DONTWAIT);
        if (ret < 0)
        {
            if (errno == EAGAIN || errno == EWOULDBLOCK)
            {
                usleep(300000);
                continue;
            }
            else
            {
                myserver->_log->error("recv error.");
                close(info->fd);
            }
        }
        else if (ret == 0)
        {
//            close(info->fd);
            delete info;
            break;
        }
        else
        {
            switch (flg)
            {
            case DOWNLOAD_AD:
                sendAD(arg);
                break;
            default:
                break;
            }
        }
    }

    return NULL;
}

void *FileServer::sendAD(void *arg)
{
    pthread_detach(pthread_self());
    int result = DOWNLOAD_AD;
    // 获取广告图片文件名
    //与文件一样，读目录前也要先打开目录
    FILE *fp = NULL;
    // 传输图片文件
    char buf[SEND_BUF_SIZE + 1];
    char open_file_buf[256];
    size_t size = 0;
    int tmp;
    int len = 0;

    clientinfo *info = static_cast<clientinfo *>(arg);
    FileServer *server = static_cast<FileServer *>(info->ptr);
    int fd = info->fd;

    do
    {
        sprintf(open_file_buf, "/home/jsetc/xu_code/1-在线答题系统项目/Server/ADs/tmp.jpg");
        fp = fopen(open_file_buf, "rb");
        if (fp == NULL)
        {
            server->_log->error("open AD error 1");
            result = DOWNLOAD_AD_ERROR;
            // 错误处理
            break;
        }
        else
        {   // 客户端获取广告图片成功
            // 开始传送文件大小
            fseek(fp, 0, SEEK_END);
            size = ftell(fp);
            fseek(fp, 0, SEEK_SET);
            // 标志位
            server->sendData(fd, &result, sizeof(result));
            // 文件大小
            server->sendData(fd, &size, sizeof(size));
            // 开始传送文件
            while ((tmp = fread(buf, 1, SEND_BUF_SIZE, fp)) != 0)
            {
                server->sendData(fd, buf, tmp);
                len += tmp;
            }
            server->_log->info("len = {}", len);
            // 传送完毕
            fclose(fp);
            server->_log->info("send AD successs");

            return NULL;
        }
    } while(0);

    server->sendData(fd, &result, sizeof(result));
    server->_log->info("send AD failed");

    return NULL;
}

void FileServer::sendData(int fd, void *data, int size)
{
    if (send(fd, data, size, 0) == -1)
    {
        _log->error("send data failed");
    }
}
