#ifndef TCPSERVER_H
#define TCPSERVER_H

#include "thread.h"
#include <exception>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>

#include <event2/listener.h>
#include <event2/buffer.h>
#include <event2/bufferevent.h>

#include "tcpsocket.h"

#define THREADPOOL_SIZE 20

class TcpSocket;

class Tcpserver
{
    friend class TcpSocket;
public:
    Tcpserver(int threadNum = 0);

    // 监听客户端的连接请求
    int listen(int port, const char *ip = NULL);
    void start();
    // 监听处理函数
    void listenEvent(evutil_socket_t fd, struct sockaddr_in *clientAdd);

protected:
    // 监听回调函数，有客户端连接的时候会调用这个函数
    static void listenCb(struct evconnlistener *, evutil_socket_t, struct sockaddr *, int socklen, void *);

    // 客户端连接事件
    virtual void connectEvent(TcpSocket *) {}

    // 可读事件
    virtual void readEvent(TcpSocket *) {}

    // 可写事件
    virtual void writeEvent(TcpSocket *) {}

    // 连接关闭事件
    virtual void closeEvent(TcpSocket *, short) {}

private:
    Thread *m_threadPool;   // 线程池
    int m_threadNum;        // 线程个数
    int m_nextThread;       // 下一个该选择的线程

    struct event_base *m_base;  // 监听客户端的连接
    struct evconnlistener *m_listener;  // 监听客户端的请求
};

#endif // TCPSERVER_H
