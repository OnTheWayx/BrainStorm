#include "communicate.h"

Communicate::Communicate(QObject *parent) : QObject(parent)
{
    // 连接服务器
    s.connectToHost(QHostAddress("192.168.35.142"), 9999);

    connect(&s, SIGNAL(readyRead()), this, SLOT(readData()));
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
    case LOGIN:
    {
        emit loginResult(root);
        break;
    }
    case ADMIN_USERONLINE:
    {
        emit userOnlineInfo(root);
        break;
    }
    case UPLOAD_AD_ACK:
    {
        emit allowToSendFile();
        break;
    }
    case UPLOAD_AD_SUCCESS:
    {
        emit finishSendFile();
        break;
    }
    default:
        break;
    };
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

void Communicate::writeData(const QJsonObject &json, char *data, int size)
{
    QJsonDocument d(json);
    QByteArray sendData = d.toJson();
    int len = sendData.size();

    s.write((char *)&len, sizeof(int));
    s.write(sendData);
    // 发送数据
    s.write(data, size);
}
