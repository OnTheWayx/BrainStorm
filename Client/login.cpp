#include "login.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("登录");

    _com = new Communicate;
    connect(_com, SIGNAL(loginResult(QJsonObject)), this, SLOT(loginResultSlots(QJsonObject)));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_loginButton_clicked()
{
    // 获取用户名和密码
    QString userName = ui->userNamelineEdit->text();
    QString passWd = ui->passWdlineEdit->text();

    if (userName == "admin")
    {
        QMessageBox::warning(this, "警告", "禁止登录管理员账户");
        return;
    }
    // 开始登录操作
    QJsonObject json;
    json["cmd"] = LOGIN;
    json["userName"] = userName;
    json["passwd"] = passWd;

    // 将登录信息发送给服务器
    _com->writeData(json);
}

void Widget::loginResultSlots(QJsonObject json)
{
    int result = json["result"].toInt();

    switch (result)
    {
    case OK:
    {
        {
            // 加载广告图片
            int cmd = DOWNLOAD_AD;
            _com->writeDataFile(&cmd, sizeof(cmd));
        }
        BrainStorm *bs = new BrainStorm(_com, json);
        this->hide();
        bs->show();
        bs->setAttribute(Qt::WA_DeleteOnClose);
        break;
    }
    case ERROR:
    {
        QMessageBox::critical(this, "登录", "登录失败，未知错误");
        break;
    }
    case NAMEORPASSWD:
    {
        QMessageBox::critical(this, "登录", "用户名或密码错误");
        break;
    }
    case USERLOGIN:
    {
        QMessageBox::critical(this, "登录", "用户在线，不可重复登录");
        break;
    }
    default:
        break;
    }
}

void Widget::on_registerButton_clicked()
{
    this->hide();
    Register *r = new Register(_com);
    r->exec();
    this->show();
}

void Widget::getDownloadAD()
{
    QJsonObject json;
    json["cmd"] = DOWNLOAD_AD;

    _com->writeData(json);
}
