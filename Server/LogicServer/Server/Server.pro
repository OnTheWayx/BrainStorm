TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += C++11     #使用spdlog需要使用C++11部分特性

SOURCES += main.cpp \
    thread.cpp \
    tcpserver.cpp \
    tcpsocket.cpp \
    myserver.cpp \
    db.cpp \
    user.cpp

HEADERS += \
    thread.h \
    tcpserver.h \
    tcpsocket.h \
    myserver.h \
    db.h \
    user.h

LIBS += -L/usr/local/lib -lpthread -levent -lmysqlclient -ljsoncpp -lspdlog
