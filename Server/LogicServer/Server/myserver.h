#ifndef MYSERVER_H
#define MYSERVER_H

#include "tcpserver.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "db.h"
#include <json/json.h>
#include <json/reader.h>
#include "../common.h"
#include <string>
#include <stdio.h>
#include <sys/io.h>
#include <map>
#include "user.h"
#include "thread.h"

#include <exception>

#define DEBUG



class MyServer : public Tcpserver
{
public:
    MyServer();

    void connectEvent(TcpSocket *);
    void readEvent(TcpSocket *);
    void writeEvent(TcpSocket *);
    void closeEvent(TcpSocket *, short);

    void writeData(TcpSocket *s, const Json::Value injson);

    // 启动心跳检测
    void heartbeatInit();

private:


    // 用户注册
    void Register(TcpSocket *s, const Json::Value &injson);

    // 用户登录
    void Login(TcpSocket *s, const Json::Value &injson);


    // single
    // 用户获取题目
    void sendSingleQuestion(TcpSocket *s);



    // rank
    // 初始化rank对应段为说明
    void initRankDescribe();

    // 用户匹配
    void rankMatch(TcpSocket *s);

    // 开始对决
    void startRank(TcpSocket *first, TcpSocket *second);

    // 当用户回答一个问题，向对手发送更新信息
    void rankAnswerQuestion(TcpSocket *s, const Json::Value &injson);

    // 客户端结算请求
    void rankSetResult(TcpSocket *s, const Json::Value &injson);


    // 客户端请求获取排行榜数据
    void sendRankSort(TcpSocket *s);


    // admin
    // 管理员请求获取在线用户信息
    void senduserOnlineInfo(TcpSocket *s);

    // 客户端请求上传文件，创建相应文件
    void createUploadFile(TcpSocket *s, const Json::Value &injson);

    // 客户端传输的文件体，接收文件体
    void recvUploadFile(TcpSocket *s, const Json::Value &injson);

    // 客户端传输的最后一个文件块
    void finishUploadFile(TcpSocket *s, const Json::Value &injson);

    // 心跳检测线程函数
    static void *heartbeatHandler(void *arg);

    //
    void recvHeartBeat(TcpSocket *s);

private:
    std::shared_ptr<spdlog::logger> _log;   // 记录日志的句柄
    DB *_db;                                // 数据库操作句柄

    std::mutex _mutex;
    std::map<std::string, User *> _onlineUsers; // 在线用户列表
    pthread_t _heartbeat;               // 心跳检测线程

    // key rank分数
    // 值 段位说明
    std::map<int, std::string> _rankDescribe;   // rank与段位说明

    // 在线匹配用户等待队列
    // 用户队列操作锁
    std::mutex rankQueue_mutex;
    std::map<int, TcpSocket *> rankQueue;
};


#endif // MYSERVER_H
