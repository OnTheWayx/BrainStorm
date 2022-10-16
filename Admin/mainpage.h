#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QDialog>
#include "../common.h"
#include "communicate.h"
#include <QJsonArray>
#include <QFileDialog>
#include <QMessageBox>
#include <stdio.h>

#define UPLOAD_AD_BUF_SIZE 2048

namespace Ui {
class mainpage;
}

class mainpage : public QDialog
{
    Q_OBJECT

public:
    explicit mainpage(Communicate *com, QWidget *parent = 0);
    ~mainpage();

private slots:
    void on_refreshButton_clicked();

    // 处理接收到的更新在线用户信息相关的信号
    void userOnlineInfoSlots(QJsonObject json);

    void on_uploadADButton_clicked();

    // 处理allowToSendFile信号的槽函数
    void allowToSendFileSlots();

    // 处理finishSendFile信号的槽函数
    void finishSendFileSlots();

private:
    void Upload_AD_nameoffile();

private:
    Ui::mainpage *ui;
    Communicate *_com;

    FILE *_fp;
};

#endif // MAINPAGE_H
