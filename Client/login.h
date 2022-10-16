#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include "register.h"
#include "communicate.h"
#include <QMessageBox>
#include "brainstorm.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_loginButton_clicked();

    void on_registerButton_clicked();

    // 处理接收到的loginResult信号
    void loginResultSlots(QJsonObject json);

protected:
    void getDownloadAD();

private:
    Ui::Widget *ui;
    Communicate *_com;  // 通信类指针 负责和服务器的通信操作
};

#endif // WIDGET_H
