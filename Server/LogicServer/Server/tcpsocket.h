#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include "tcpserver.h"
#include <string>

class Tcpserver;

class TcpSocket
{
public:
    TcpSocket(Tcpserver *tcpserver, struct bufferevent *bev, const char *ip, uint16_t port, int fd);

    // 可读事件回调函数
    static void readEventCb(struct bufferevent *bev, void *ctx);

    // 可写事件回调函数
    static void writeEventCb(struct bufferevent *bev, void *ctx);

    // 异常事件回调函数
    static void closeEventCb(struct bufferevent *bev, short what, void *ctx);

    // 获取ip
    const char *getip();
    // 获取端口
    uint16_t getport();

    // 从客户端读数据
    size_t readData(void *data, int size);

    // 向客户端写数据
    int writedata(const void *data, int size);

    // 设置用户名
    void setuserName(std::string name);

    // 获取用户名
    std::string getuserName();

    // 设置文件指针
    void setFp(FILE *fp);

    // 获取文件指针
    FILE *getFp();

    // 更新累计心跳数
    void setHeartCount(int num);

    // 获取心跳计数
    int getHeartCount();

    // 获取客户端的套接字描述符
    int getFd();

private:
    static Tcpserver *m_tcpserver;
    struct bufferevent *m_bev;
    const char *m_ip;
    uint16_t m_port;

    int m_fd;

    std::string m_userName;

    FILE *m_fp;

    int m_heartcount;
};

#endif // TCPSOCKET_H
