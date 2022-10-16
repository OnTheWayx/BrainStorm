#ifndef THREAD_H
#define THREAD_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <event2/event_struct.h>
#include <event2/event_compat.h>
#include <event2/event.h>

class Thread
{
public:
    Thread();
    void start();   // 线程创建函数

    struct event_base *getbase();

protected:
    static void *worker(void *);  // 线程工作函数
    static void pipeReader(evutil_socket_t, short, void *);    // 触发事件处理函数
    void run(); // 线程逻辑处理函数

private:
    pthread_t m_threadId;   // 线程ID
    struct event_base *m_base;  // 事件集合
    // 创建管道 记录读端与写端
    int m_pipeReadfd;
    int m_pipeWritefd;
    // 事件集合事件
    struct event m_pipeEvent;
};

#endif // THREAD_H
