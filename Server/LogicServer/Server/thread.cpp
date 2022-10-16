#include "thread.h"

Thread::Thread()
{
    // 创建事件集合
    m_base = event_base_new();
    if (!m_base)
    {
        fprintf(stderr, "Could not initialize libevent!\n");
        exit (-1);
    }
    // 创建管道
    int fd[2];
    if (pipe(fd) != 0)
    {
        fprintf(stderr, "Create pipe failed.\n");
        exit(-1);
    }
    // 记录下管道的读端与写端
    m_pipeReadfd = fd[0];
    m_pipeWritefd = fd[1];

    // 将管道可读与事件集合绑定
    // 如果监听到  管道的读端有数据可读
    event_set(&m_pipeEvent, m_pipeReadfd, EV_PERSIST | EV_READ, pipeReader, this);

    // 向事件集合中添加事件
    event_base_set(m_base, &m_pipeEvent);

    // 开启事件的监听
    event_add(&m_pipeEvent, 0);
}

void Thread::start()
{
    int result = pthread_create(&m_threadId, NULL, worker, this);
    if (result != 0)
    {
        fprintf(stderr, "Could not create a thread!\n");
    }
}

void *Thread::worker(void *arg)
{
    Thread *p = static_cast<Thread *>(arg);
    p->run();

    return NULL;
}

void Thread::pipeReader(evutil_socket_t, short, void *)
{

}

void Thread::run()
{
//    while (1)
//    {
//        printf("Thread : %ld\n", m_threadId);
//        sleep(2);
//    }
    // 死循环  用来处理事件   类似于Qt的exec()
    // 如果m_base事件集合内部都是空的话，则event_base_dispatch会立马返回
    // 初始化的时候需要给m_base添加一个事件，让它不空
    printf("%ld : start listening.\n", m_threadId);
    event_base_dispatch(m_base);
    event_base_free(m_base);
    printf("%ld : end listening.\n", m_threadId);
}

struct event_base *Thread::getbase()
{
    return m_base;
}
