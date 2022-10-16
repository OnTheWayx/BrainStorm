#include "login.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("管理员");

    _com = new Communicate();
    connect(_com, SIGNAL(loginResult(QJsonObject)), this, SLOT(loginResultSlots(QJsonObject)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_loginButton_clicked()
{
    QJsonObject json;

    QString userName = ui->userNamelineEdit->text();
    QString passWd = ui->passWdlineEdit->text();

    if (userName != "admin")
    {
        QMessageBox::critical(this, "提示", "请输入管理员账户");
        return;
    }

    json["cmd"] = LOGIN;
    json["userName"] = userName;
    json["passwd"] = passWd;

    _com->writeData(json);
}

void Widget::loginResultSlots(QJsonObject json)
{//
    int result = json["result"].toInt();

    switch (result) {
    case OK:
    {
        mainpage *main = new mainpage(_com);
        this->hide();
        main->show();
        main->setAttribute(Qt::WA_DeleteOnClose);
        break;
    }
    case ERROR:
        QMessageBox::critical(this, "提示", "登录失败，未知错误");
        break;
    case USERLOGIN:
        QMessageBox::critical(this, "提示", "用户在线，不可重复登录");
        break;
    case NAMEORPASSWD:
        QMessageBox::critical(this, "提示", "登录失败，账号或密码错误");
        break;
    default:
        break;
    }
}
