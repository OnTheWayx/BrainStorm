#ifndef USER_H
#define USER_H

#include "tcpsocket.h"
#include <string>

class User
{
public:
    User(std::string u, std::string p, int r, TcpSocket *s);

    // 获取TcpSocket指针
    TcpSocket *getSocket();

    // 获取rank分数
    int getRank();

    // 设置rank分数
    void setRank(int rank);

private:
    std::string _userName;
    std::string _passWd;
    int _rank;
    TcpSocket *_s;
};

#endif // USER_H
