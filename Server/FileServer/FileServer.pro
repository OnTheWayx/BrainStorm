TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += C++11     #使用spdlog需要使用C++11部分特性

SOURCES += main.cpp \
    fileserver.cpp

HEADERS += \
    fileserver.h common.h \
    mydefine.h

LIBS += -L/usr/local/lib -lpthread -levent -ljsoncpp -lspdlog
