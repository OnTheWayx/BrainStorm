#ifndef FILESERVER_H
#define FILESERVER_H

#include <exception>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include "common.h"
#include "mydefine.h"

#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <exception>

class FileServer
{//文件传输类
public:
    FileServer();

    // 做好相应的初始化工作
    int init(int port, const char *ip);

    // 开始监听连接工作
    void start();

private:
    static void AcceptClient(void *arg);    // 开始监听连接事件

    static void *ClientHandler(void *arg);    // 处理客户端请求

    static void *sendAD(void *arg);  // 向客户端发送广告图片

    // 随机选择广告图片
    int countAD();

    void sendData(int fd, void *data, int size);

    void sendADHandler(int fd);

private:
    std::shared_ptr<spdlog::logger> _log;   // 记录日志的句柄

    int m_fd;
//    int m_epfd;
    int m_shutdown; // 服务器开启关闭标志

    //填充网络信息结构体，保存服务器信息
    struct sockaddr_in m_server_addr;
    socklen_t m_server_len;
    struct epoll_event m_events[CLIENT_MAXSIZE];
};

// 用于监听到客户端连接时创建相应的线程给线程函数传参
struct clientinfo
{
    void *ptr;
    int fd;
};

#endif // FILESERVER_H
