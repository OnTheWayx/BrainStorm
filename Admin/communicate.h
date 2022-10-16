#ifndef COMMUNICATE_H
#define COMMUNICATE_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QHostAddress>
#include "../common.h"

class Communicate : public QObject
{
    Q_OBJECT
public:
    explicit Communicate(QObject *parent = nullptr);

    // 向服务器发送数据
    void writeData(const QJsonObject &json);
    // 上传图片
    void writeData(const QJsonObject &json, char *data, int size);

signals:
    // 登录成功发射信号，由login接收
    void loginResult(QJsonObject json);
    // 获取在线用户信息后发射信号userOnlineInfo，由mainpage接收
    void userOnlineInfo(QJsonObject json);

    // 服务器允许继续发送文件信号
    void allowToSendFile();

    // 服务器接收文件完成信号
    void finishSendFile();

public slots:
    // 读取接收到的服务器的数据
    void readData();

private:
    QTcpSocket s;
};

#endif // COMMUNICATE_H
