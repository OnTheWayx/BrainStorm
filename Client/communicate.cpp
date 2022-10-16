#include "communicate.h"

Communicate::Communicate(QObject *parent) : QObject(parent)
{
    // 连接服务器
    s.connectToHost(QHostAddress("192.168.35.142"), 9999);
    s_file.setReadBufferSize(1024 * 1024 * 6);
    s_file.connectToHost(QHostAddress("192.168.35.142"), 9998);

    connect(&s, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(&s, SIGNAL(disconnected()), this, SLOT(Exit()));
    connect(&s_file, SIGNAL(readyRead()), this, SLOT(bufferData()));
    connect(&m_timer,SIGNAL(timeout()), this, SLOT(readDataFromFile()));
    m_buffer.clear();
}

void Communicate::bufferData()
{
    m_timer.start(100);
    m_buffer.append(s_file.readAll());
}

void Communicate::readData()
{
    QByteArray data;
    // 判断数据是否读完
    while (s.bytesAvailable())
    {
        data += s.readAll();
    }

    // 数据解析
    QJsonDocument dt = QJsonDocument::fromJson(data);
    // 如果没有数据，则直接返回
    if (dt.isNull())
    {
        return;
    }
    QJsonObject root = dt.object();

    // 具体的逻辑处理
    int cmd = root["cmd"].toInt();
    switch (cmd)
    {
    case REGISTER:
        emit rstResult(root);
        break;
    case LOGIN:
        emit loginResult(root);
        break;
    case SINGLE_GETQUESTION:
        emit singleGetQuestion(root["question"].toObject());
        break;
    case RANK:
        emit rank(root);
        break;
    case ANSWER:
        emit recvAnswer(root);
        break;
    case RANKRESULT:
        emit setRankResult(root);
        break;
    case RANKSORT:
        emit recvRankSort(root);
        break;
    case HEARTBEAT:
        sendHeartBeat();
        break;
    default:
        break;
    };
}

void Communicate::readDataFromFile()
{
    m_timer.stop();
    int cmd;
    int size = m_buffer.size();
    char *recvdata = m_buffer.data();

    memcpy(&cmd, recvdata, sizeof(cmd));

    switch (cmd)
    {
    case DOWNLOAD_AD_ERROR:
    {
        emit DownloadADError();
        break;
    }
    case DOWNLOAD_AD:
    {
        // 先接收图片
        recvAD(recvdata, size);
        emit DownloadADSuccess();
        break;
    }
    default:
        break;
    };

    m_buffer.clear();
}

void Communicate::recvAD(char *data, int size)
{
    // 先接收文件名   暂时无用  新传的文件均命名为tmp.jpg
    char name_buf[50 + 1];
    size_t file_size;
    FILE *fp;

    int len = 0;
    // 接收文件大小
    memcpy(&file_size, data + RECV_BUFFER_FLG, RECV_BUFFER_SIZE);
    fp = fopen("D:/QT_Workspace/QT_BrainStorm/ADs/tmp.jpg", "wb");
    if (fp == NULL)
    {
        printf("recv failed\n");
        goto recvAD_ERROR;
    }
    len += fwrite(data + RECV_BUFFER_FLG + RECV_BUFFER_SIZE, 1,
                  size - (RECV_BUFFER_FLG + RECV_BUFFER_SIZE), fp);
    fclose(fp);
    printf("len = %d\n", len);
    s_file.close();
    return;

recvAD_ERROR:
    s_file.readAll();
}

void Communicate::writeData(const QJsonObject &json)
{
    QJsonDocument d(json);
    QByteArray sendData = d.toJson();

    int len = sendData.size();
    // 先发送数据的长度
    s.write((char *)&len, sizeof(int));
    // 再发送数据
    s.write(sendData);
}

void Communicate::writeDataFile(void *data, int size)
{
    s_file.write((char *)data, size);
}

void Communicate::Exit()
{
    emit ExitClient();
}

void Communicate::sendHeartBeat()
{
    QJsonObject outjson;

    outjson["cmd"] = HEARTBEAT;
    writeData(outjson);
}
