#include <iostream>
#include "fileserver.h"

using namespace std;

int main()
{
    FileServer server;

    server.init(9998, "192.168.35.142");
    server.start();

    return 0;
}
