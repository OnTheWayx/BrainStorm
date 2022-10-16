#include "tcpserver.h"

Tcpserver::Tcpserver(int threadNum) : m_nextThread(0)
{
    if (threadNum <= 0)
    {
        printf("create thread : threadnum <= 0\n");
        exit(-1);
    }
    try
    {
        m_threadNum = threadNum;
        m_threadPool = new Thread[m_threadNum];
    }
    catch (std::bad_alloc &e)
    {
        e.what();
        exit(-1);
    }
    m_base = event_base_new();
    if (m_base == NULL)
    {
        fprintf(stderr, "Could not initialize libevent.\n");
        exit(-1);
    }
}

int Tcpserver::listen(int port, const char *ip)
{
    struct sockaddr_in sin;

    memset(&sin, 0, sizeof(sin));
    sin.sin_port = htons(port);
    sin.sin_family = AF_INET;
    if (ip != NULL)
    {
        inet_aton(ip, &sin.sin_addr);
    }
    m_listener = evconnlistener_new_bind(m_base, listenCb, this, LEV_OPT_CLOSE_ON_FREE | LEV_OPT_REUSEABLE,
                                         -1, (struct sockaddr *)&sin, sizeof(sin));
    if (m_listener == NULL)
    {
        fprintf(stderr, "Could not create a listener.\n");
        return -1;
    }
    // 初始化线程池
    for (int i = 0; i < m_threadNum; i++)
    {
        m_threadPool[i].start();
    }

    return 0;
}

void Tcpserver::listenCb(struct evconnlistener *, evutil_socket_t fd, struct sockaddr *clientAdd, int, void *data)
{
    Tcpserver *p = static_cast<Tcpserver *>(data);
    p->listenEvent(fd, (struct sockaddr_in *)clientAdd);
}

void Tcpserver::listenEvent(int fd, struct sockaddr_in *clientAdd)
{
    const char *ip = inet_ntoa(clientAdd->sin_addr);
    uint16_t port = ntohs(clientAdd->sin_port);

    struct event_base *base = m_threadPool[m_nextThread].getbase();
    m_nextThread = (m_nextThread + 1) % m_threadNum;

    struct bufferevent *bev;

    bev = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);
    if (bev == NULL)
    {
        fprintf(stderr, "Error constructing bufferevent!");
        event_base_loopbreak(base);
        return;
    }

    // 创建一个通信对象
    TcpSocket *s = new TcpSocket(this, bev, ip, port, fd);

    // 单独封装一个类处理和客户端的通信
    bufferevent_setcb(bev, s->readEventCb, s->writeEventCb, s->closeEventCb, s);
    bufferevent_enable(bev, EV_READ);
    bufferevent_enable(bev, EV_WRITE);
    bufferevent_enable(bev, EV_SIGNAL);

    // 调用客户端连接函数
    connectEvent(s);
}

void Tcpserver::start()
{
    event_base_dispatch(m_base);
    evconnlistener_free(m_listener);
    event_base_free(m_base);

    printf("done.\n");
}
