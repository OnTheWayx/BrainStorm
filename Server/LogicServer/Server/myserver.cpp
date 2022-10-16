#include "myserver.h"

MyServer::MyServer() : Tcpserver(THREADPOOL_SIZE)
{
#ifdef DEBUG
    _log = spdlog::stdout_color_mt("console");
#else
    _log = spdlog::rotating_logger_mt("BrainStorm", "BrainStorm", 1024 * 1024 * 5, 3);
    _log->flush_on(spdlog::level::info);
#endif
//    _log->info("1111111111111111");
    _db = new DB(NULL, "C++project", "Xjy0.9.2.6@.", "BrainStorm");

    // 初始化rank分与段位说明
    initRankDescribe();
}

void MyServer::initRankDescribe()
{

    int rank = 0;
    int stars = 0;

    for (int i = 0; i < 100; i++)
    {
        char buf[100] = {0};
        if (i < 9)
        {
            rank = i / 3;
            stars = i % 3;
            sprintf(buf, "青铜%d %d颗星", 3 - rank, stars + 1);
        }
        else if (i >= 9 && i < 18)
        {
            rank = (i - 9) / 3;
            stars = (i - 9) % 3;
            sprintf(buf, "白银%d %d颗星", 3 - rank, stars + 1);
        }
        else if (i >= 18 && i < 34)
        {
            rank = (i - 18) / 4;
            stars = (i - 18) % 4;
            sprintf(buf, "黄金%d %d颗星", 4 - rank, stars + 1);
        }
        else if (i >= 34 && i < 50)
        {
            rank = (i - 34) / 4;
            stars = (i - 34) % 4;
            sprintf(buf, "铂金%d %d颗星", 4 - rank, stars + 1);
        }
        else if (i >= 50 && i < 75)
        {
            rank = (i - 50) / 5;
            stars = (i - 50) % 5;
            sprintf(buf, "钻石%d %d颗星", 5 - rank, stars + 1);
        }
        else if (i >= 75 && i < 100)
        {
            rank = (i - 75) / 5;
            stars = (i - 75) % 5;
            sprintf(buf, "星耀%d %d颗星", 5 - rank, stars + 1);
        }
        _rankDescribe.insert(std::make_pair(i, buf));
    }
}

void MyServer::connectEvent(TcpSocket *s)
{
    _log->info("有一个新的连接[{}:{}]", s->getip(), s->getport());
}

void MyServer::readEvent(TcpSocket *s)
{
    char buf[12400];
    try
    {
        while (1)
        {
            int len = 0;
            s->readData(&len, sizeof(len));
            if (len <= 0)
            {
                break;
            }
            s->readData(buf, len);
            // 数据解析
            Json::Value root;
            Json::Reader reader;    // json解析器
            if (!reader.parse(buf, root))
            {
                _log->error("json 数据解析失败");
                return;
            }
            int cmd = root["cmd"].asInt();
            switch (cmd)
            {
            case REGISTER:
                Register(s, root);
                break;
            case LOGIN:
                Login(s, root);
                break;
            case SINGLE_GETQUESTION:
                sendSingleQuestion(s);
                break;
            case RANK:
                rankMatch(s);
                break;
            case ANSWER:
                rankAnswerQuestion(s, root);
                break;
            case RANKRESULT:
                rankSetResult(s, root);
                break;
            case ADMIN_USERONLINE:
                senduserOnlineInfo(s);
                break;
            case UPLOAD_AD_SF:
                createUploadFile(s, root);
                break;
            case UPLOAD_AD_MF:
                recvUploadFile(s, root);
                break;
            case UPLOAD_AD_EF:
                finishUploadFile(s, root);
                break;
            case RANKSORT:
                _log->info("接收到结果");
                sendRankSort(s);
                break;
            case HEARTBEAT:
                recvHeartBeat(s);
                break;
            default:
                break;
            }
        }
    }catch (std::exception &e)
    {
        e.what();
    }
}

void MyServer::writeEvent(TcpSocket *)
{

}

void MyServer::closeEvent(TcpSocket *s, short)
{
    {
        // 将已登录的客户端从在线用户列表中移除
        std::unique_lock<std::mutex> loc(_mutex);
        std::map<std::string, User *>::iterator it = _onlineUsers.begin();
        while (it != _onlineUsers.end())
        {
            if (it->second->getSocket() == s)
            {
                _log->info("{} logout[{}:{}]", it->first.c_str(), s->getip(), s->getport());
                // 释放相应用户空间
                delete it->second;
                _onlineUsers.erase(it);
                // 释放相应的通信类的内存空间

                break;
            }
            it++;
        }
        // 更新用户的rank分
        char sql[100];
        sprintf(sql, "update users set rank = '%d' where name = '%s';", it->second->getRank(), s->getuserName().c_str());
        _db->db_exec(sql);
    }
    {
        // 若是用户正在匹配队列中，但意外掉线或退出，则将用户从匹配队列中移除
        std::unique_lock<std::mutex> loc_queue(rankQueue_mutex);
        auto tmp = rankQueue.begin();
        while (tmp != rankQueue.end())
        {
            if (tmp->second == s)
            {
                rankQueue.erase(tmp);
                break;
            }
            tmp++;
        }
    }

   _log->info("logout[{}:{}]", s->getip(), s->getport());
}

void MyServer::writeData(TcpSocket *s, const Json::Value injson)
{
    std::string data = injson.toStyledString();
    s->writedata(data.c_str(), data.length());
}

void MyServer::Register(TcpSocket *s, const Json::Value &injson)
{
    std::string userName = injson["userName"].asString();
    std::string passWd = injson["passwd"].asString();

    // 检测用户是否存在
    char sql[100] = {0};
    sprintf(sql, "select * from users where name = '%s';", userName.c_str());

    int result = OK;
    Json::Value outJson;
    bool ret = _db->db_select(sql, outJson);
    if (!ret)
    {
        result = ERROR;
        _log->error("Register select users error");
    }
    if (outJson.isMember("name"))   // 用户存在，表明已经注册过了
    {
        result = USEREXIST;
    }
    else
    {
        sprintf(sql, "insert into users(name, passwd, rank) values('%s', '%s', %d);", userName.c_str(), passWd.c_str(), 0);
        bool ret = _db->db_exec(sql);
        if (!ret)
        {
            result = ERROR;
            _log->error("Register insert users error");
        }
        else
        {
            _log->info("Register users = {} succeed", userName);
        }
    }
    Json::Value json;
    json["cmd"] = REGISTER;
    json["result"] = result;

    writeData(s, json);
}

void MyServer::Login(TcpSocket *s, const Json::Value &injson)
{
   // 获取用户名与密码
    std::string userName = injson["userName"].asString();
    std::string passWd = injson["passwd"].asString();

    char sql[100];
    int result = OK;
    int rank;
    Json::Value outJson;

    sprintf(sql, "select * from users where name = '%s' and passwd = '%s';", userName.c_str(), passWd.c_str());
    bool ret = _db->db_select(sql, outJson);
    if (!ret)
    {
        result = ERROR;
        _log->error("Login select users error");
    }
    if (outJson.isMember("name"))   // 账户密码输入正确，查看用户是否已经在线
    {
        // 在线用户列表操作前上锁
        std::unique_lock<std::mutex> loc(_mutex);
        if (_onlineUsers.find(userName) != _onlineUsers.end())
        {// 用户在线
            result = USERLOGIN;
        }
        else
        {// 用户不在线，加入在线用户列表
            int i = 0;
            rank = atoi(outJson["rank"][i].asString().c_str());
            User *user = new User(userName, passWd, rank, s);
            _onlineUsers.insert(std::make_pair(userName, user));
            user->setRank(rank);
            // 设置TcpSocket用户名
            s->setuserName(userName);
        }
    }
    else
    {   // 用户名或密码错误
        result = NAMEORPASSWD;
    }
    Json::Value json;
    json["cmd"] = LOGIN;
    json["result"] = result;
    json["userName"] = userName;
    json["rank"] = _rankDescribe[rank];
    writeData(s, json);
}

void MyServer::sendSingleQuestion(TcpSocket *s)
{
    char sql[100];

    // 随机从数据库获取五条记录
    sprintf(sql, "select * from questions order by rand() limit %d", QUESTION_NUM);
    Json::Value outJson;

    int result = OK;
    int ret = _db->db_select(sql, outJson);
    if (!ret || outJson["question"].size() != QUESTION_NUM)
    {
        result = ERROR;
        _log->error("{} get question error", s->getuserName());
    }

    // 设置向客户端发送的数据
    Json::Value json;

    json["cmd"] = SINGLE_GETQUESTION;
    json["result"] = result;
    json["question"] = outJson;
    _log->info("{} [{}:{}] get question {}", s->getuserName(), s->getip(), s->getport(), outJson.toStyledString());

    writeData(s, json);
}

void MyServer::sendRankSort(TcpSocket *s)
{
    Json::Value outjson;
    Json::Value sendjson;

    char sql[300];
    int result = OK;

    sprintf(sql, "select name,rank from users order by rank desc limit %d;", RANKSORT_NUM);
    if (!(_db->db_select(sql, outjson)))
    {   // 获取失败
        result = ERROR;
    }
    else
    {
        _log->info("succ 查询");
        for (int i = 0; i < RANKSORT_NUM; i++)
        {
            sendjson["userName"][i] = outjson["name"][i].asString();
            sendjson["rank"][i] = _rankDescribe[atoi(outjson["rank"][i].asString().c_str())];
        }
        sendjson["size"] = RANKSORT_NUM;
    }
    sendjson["cmd"] = RANKSORT;
    sendjson["result"] = result;
    sendjson["test"] = outjson;
    writeData(s, sendjson);
}

//-------------rank 部分-----------
void MyServer::rankMatch(TcpSocket *s)
{
    TcpSocket *other = NULL;
    int rank;

    {
        std::unique_lock<std::mutex> loc(_mutex);
        rank = _onlineUsers[s->getuserName()]->getRank();
    }
    // 开始查找对手
    // 只有rank分差<=10才可相互对决
    std::unique_lock<std::mutex> loc_queue(rankQueue_mutex);
    for (auto tmp = rankQueue.begin(); tmp != rankQueue.end(); tmp++)
    {
        if (std::abs(tmp->first - rank) < 10)
        {
            other = tmp->second;
            rankQueue.erase(tmp);
            break;
        }
    }

    _log->info("rank 分数 ： {}", rank);
    if (other == NULL)
    {// 没有匹配到对手
        // 加入到等待队列
        rankQueue.insert(std::make_pair(rank, s));
        _log->info("当前等候 rank 人数 ： {}", rankQueue.size());
    }
    else
    {// 开始对决
        startRank(s, other);
    }
}

void MyServer::startRank(TcpSocket *first, TcpSocket *second)
{
    char sql[100];

    // 随机从数据库获取五条记录
    sprintf(sql, "select * from questions order by rand() limit %d", QUESTION_NUM);
    Json::Value outJson;

    int result = OK;
    int ret = _db->db_select(sql, outJson);
    if (!ret || outJson["question"].size() != QUESTION_NUM)
    {
        result = ERROR;
        _log->error("rank get question error");
    }

    Json::Value json;

    // first
    json["cmd"] = RANK;
    json["result"] = result;
    json["question"] = outJson;
    json["enemyName"] = second->getuserName();
    {
        std::unique_lock<std::mutex> loc(_mutex);
        json["enemyRank"] = _rankDescribe[_onlineUsers[second->getuserName()]->getRank()];
    }
    json["enemyScore"] = 0;
    writeData(first, json);

    // second
    json["enemyName"] = first->getuserName();
    {
        std::unique_lock<std::mutex> loc(_mutex);
        json["enemyRank"] = _rankDescribe[_onlineUsers[first->getuserName()]->getRank()];
    }
    writeData(second, json);

    _log->info("rank getQuestion : {}", outJson.toStyledString());
}

void MyServer::rankAnswerQuestion(TcpSocket *, const Json::Value &injson)
{
    Json::Value json;

    std::map<std::string, User *>::iterator user_it = _onlineUsers.find(injson["enemyName"].asString());
    if (user_it == _onlineUsers.end())
    {
        _log->error("{} 掉线 转发answer失败", injson["enemyName"].asString());
        return;
    }
    json["cmd"] = ANSWER;
    json["enemyScore"] = injson["userScore"].asInt();
    json["enemyquestionId"] = injson["questionId"].asInt();
    writeData(user_it->second->getSocket(), json);
}

void MyServer::rankSetResult(TcpSocket *s, const Json::Value &injson)
{
    int rank;
    int userScore = injson["userScore"].asInt();
    int enemyScore = injson["enemyScore"].asInt();
    std::string enemyName = injson["enemyName"].asString();

    {
        std::unique_lock<std::mutex> loc(_mutex);
        auto it = _onlineUsers.find(s->getuserName());
        if (it != _onlineUsers.end())
        {
            if (userScore < enemyScore)
            {
                it->second->setRank(it->second->getRank() - 1);

            }
            else if (userScore > enemyScore)
            {
                it->second->setRank(it->second->getRank() + 1);
            }
        }
        else
        {
            _log->error("{} 掉线 结算段位失败", s->getuserName());
        }
        rank = it->second->getRank();
    }

    Json::Value outjson;
    outjson["cmd"] = RANKRESULT;
    outjson["rankResult"] = _rankDescribe[rank];

    writeData(s, outjson);
}



// -----------admin 部分------------
void MyServer::senduserOnlineInfo(TcpSocket *s)
{
    Json::Value json;
    Json::Value userInfo;

    {
        std::unique_lock<std::mutex> loc(_mutex);
        json["cmd"] = ADMIN_USERONLINE;
        json["num"] = _onlineUsers.size();
        for (auto tmp = _onlineUsers.begin(); tmp != _onlineUsers.end(); tmp++)
        {
            userInfo["userName"].append(tmp->first);
            userInfo["rank"].append(_rankDescribe[tmp->second->getRank()]);
        }
    }
    json["info"] = userInfo;
    _log->info("admin get useronline");

    writeData(s, json);
}

void MyServer::createUploadFile(TcpSocket *s, const Json::Value &injson)
{
    _log->info("createUploadFile");
    std::string filename = injson["filename"].asString();
    char buf[200] = {0};

    sprintf(buf, "../ADs/%s", filename.c_str());
    _log->info("{}", filename);
    s->setFp(fopen(buf, "wb"));
    if (s->getFp() == NULL)
    {
        _log->error("create file error : {}", s->getuserName());
    }
    Json::Value outjson;

    outjson["cmd"] = UPLOAD_AD_ACK;
    writeData(s, outjson);
    _log->info("create success");
}

void MyServer::recvUploadFile(TcpSocket *s, const Json::Value &injson)
{
    _log->info("recvUploadFile");
    size_t size = injson["size"].asUInt64();
    char buf[UPLOAD_AD_BUF_SIZE + 1] = { 0 };
    size_t result;

    if (s->readData(buf, size) == size)
    {
        _log->info("write to file {}", size);
    }
    result = fwrite(buf, 1, size, s->getFp());

    Json::Value outjson;
    outjson["cmd"] = UPLOAD_AD_ACK;
    writeData(s, outjson);
}

void MyServer::finishUploadFile(TcpSocket *s, const Json::Value &injson)
{
    _log->info("finishUploadFile");
    size_t size = injson["size"].asUInt64();
    char buf[UPLOAD_AD_BUF_SIZE + 1] = { 0 };
    size_t result;

    if (s->readData(buf, size) == size)
    {
        _log->info("write to file {}", size);
    }
    result = fwrite(buf, 1, size, s->getFp());

    // 文件传输完成
    fclose(s->getFp());
    s->setFp(NULL);

    Json::Value outjson;
    outjson["cmd"] = UPLOAD_AD_SUCCESS;
    writeData(s, outjson);
}

void MyServer::heartbeatInit()
{
    // 创建心跳线程
    if (pthread_create(&_heartbeat, NULL, MyServer::heartbeatHandler, this) != 0)
    {
        _log->error("心跳线程启动失败...");
    }
    else
    {
        _log->info("心跳线程启动成功...");
    }
}

void *MyServer::heartbeatHandler(void *arg)
{
    MyServer *server = (MyServer *)arg;
    std::map<std::string, User *>::iterator it, tmp;
    Json::Value outjson;
    int heartcount_tmp;
    TcpSocket *s;

    outjson["cmd"] = HEARTBEAT;
    pthread_detach(pthread_self());
    while (1)
    {
        {
            std::unique_lock<std::mutex> lock(server->_mutex);
            it = server->_onlineUsers.begin();
            tmp = it;
        }
        while (it != server->_onlineUsers.end())
        {
            std::unique_lock<std::mutex> lock(server->_mutex);
            s = it->second->getSocket();
            heartcount_tmp = s->getHeartCount();
            if (heartcount_tmp < 5)
            {
                // 发送心跳包
                server->writeData(s, outjson);
                s->setHeartCount(heartcount_tmp + 1);
                server->_log->info("send heartbeat:{}", s->getuserName());
                it++;
            }
            else if (heartcount_tmp == 5)
            {
                tmp = it;
                tmp++;
                lock.unlock();
                close(s->getFd());
                server->closeEvent(s, 0);
                delete s;
                lock.lock();
                it = tmp;
            }
            else
            {
                it++;
            }
        }
        server->_log->info("heartbeat check");
        sleep(3);
    }
}

void MyServer::recvHeartBeat(TcpSocket *s)
{
    s->setHeartCount(0);
    _log->info("recv HeartBeat{}:{}", s->getFd(), s->getuserName());
}
