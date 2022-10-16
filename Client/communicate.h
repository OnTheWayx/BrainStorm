#ifndef COMMUNICATE_H
#define COMMUNICATE_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QHostAddress>
#include <QThread>
#include <QTimer>
#include "../common.h"

#define RECV_BUF_SIZE 1024
#define RECV_BUFFER_FLG 4
#define RECV_BUFFER_NAME 50
#define RECV_BUFFER_SIZE 8

class Communicate : public QObject
{
    Q_OBJECT
public:
    explicit Communicate(QObject *parent = nullptr);

    // 向服务器发送数据
    void writeData(const QJsonObject &json);

    // 向服务器发送文件数据
    void writeDataFile(void *data, int size);

signals:
    // 注册成功发射信号，由register接收
    void rstResult(QJsonObject json);

    // 登录成功发射信号，由login接收
    void loginResult(QJsonObject json);

    // 接收到服务器发送的题目时发射信号，由brainstorm接收
    void singleGetQuestion(QJsonObject json);

    // 发送接受rank信号
    void rank(QJsonObject json);

    // 收到服务器发送的更新对手信息时发射的信号
    void recvAnswer(QJsonObject json);

    // 收到服务器发送的rank结果是发射的信号
    void setRankResult(QJsonObject json);

    // 加载广告失败信号
    void DownloadADError();

    // 加载广告成功信号
    void DownloadADSuccess();

    // 接收到排行榜数据信号
    void recvRankSort(QJsonObject json);

    void ExitClient();

public slots:
    // 缓冲读取数据
    void bufferData();

    // 读取接收到的服务器的逻辑数据
    void readData();

    // 读取接收到的服务器的文件数据
    void readDataFromFile();

    void Exit();

    // 发送心跳回应包
    void sendHeartBeat();
private:
    // 接受图片
    void recvAD(char *data, int size);

private:
    QTcpSocket s;
    QTcpSocket s_file;

    QByteArray m_buffer;
    QTimer m_timer;
};

#endif // COMMUNICATE_H
