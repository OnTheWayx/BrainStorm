#include "user.h"

User::User(std::string u, std::string p, int r, TcpSocket *s)
    : _userName(u), _passWd(p), _rank(r), _s(s)
{

}

TcpSocket *User::getSocket()
{
    return _s;
}

int User::getRank()
{
    return _rank;
}

void User::setRank(int rank)
{
    if (rank <= 0)
    {
        rank = 0;
    }
    else if (rank >= 99)
    {
        rank = 99;
    }
    _rank = rank;
}
