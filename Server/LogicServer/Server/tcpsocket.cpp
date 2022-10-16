#include "tcpsocket.h"

Tcpserver *TcpSocket::m_tcpserver = NULL;

TcpSocket::TcpSocket(Tcpserver *tcpserver, bufferevent *bev, const char *ip, uint16_t port, int fd)
{
    m_tcpserver = tcpserver;
    m_bev = bev;
    m_ip = ip;
    m_port = port;
    m_fp = NULL;
    m_heartcount = 0;
    m_fd = fd;
}

void TcpSocket::readEventCb(struct bufferevent *, void *ctx)
{
    TcpSocket *s = (TcpSocket *)ctx;
    m_tcpserver->readEvent(s);
}

void TcpSocket::writeEventCb(struct bufferevent *, void *ctx)
{
    TcpSocket *s = (TcpSocket *)ctx;
    m_tcpserver->writeEvent(s);
}

void TcpSocket::closeEventCb(struct bufferevent *, short what, void *ctx)
{
    TcpSocket *s = (TcpSocket *)ctx;
    m_tcpserver->closeEvent(s, what);

    delete s;
}

const char *TcpSocket::getip()
{
    return m_ip;
}

uint16_t TcpSocket::getport()
{
    return m_port;
}

size_t TcpSocket::readData(void *data, int size)
{
    return bufferevent_read(m_bev, data, size);
}

int TcpSocket::writedata(const void *data, int size)
{
    return bufferevent_write(m_bev, data, size);
}

void TcpSocket::setuserName(std::string name)
{
    m_userName = name;
}

std::string TcpSocket::getuserName()
{
    return m_userName;
}

void TcpSocket::setFp(FILE *fp)
{
    m_fp = fp;
}

FILE *TcpSocket::getFp()
{
    return m_fp;
}

void TcpSocket::setHeartCount(int num)
{
    m_heartcount = num;
}

int TcpSocket::getHeartCount()
{
    return m_heartcount;
}

int TcpSocket::getFd()
{
    return m_fd;
}
