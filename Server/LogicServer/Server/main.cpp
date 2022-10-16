#include <iostream>
#include "thread.h"
#include "tcpserver.h"
#include "myserver.h"

int main()
{
    MyServer m;
    m.heartbeatInit();
    m.listen(9999);
    m.start();

    return 0;
}
