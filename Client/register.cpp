#include "register.h"
#include "ui_register.h"

Register::Register(Communicate *com, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    this->setWindowTitle("注册");
    _com = com;

    connect(_com, SIGNAL(rstResult(QJsonObject)), this, SLOT(rstResultSlots(QJsonObject)));
}

Register::~Register()
{
    delete ui;
}

void Register::on_registerButton_clicked()
{
    // 获取用户名和密码
    QString userID = ui->userNamelineEdit->text();
    QString passWd = ui->passWdlineEdit->text();

    // 开始注册操作
    QJsonObject json;
    json["cmd"] = REGISTER;
    json["userName"] = userID;
    json["passwd"] = passWd;

    // 给服务器发送数据
    _com->writeData(json);
}

void Register::rstResultSlots(QJsonObject json)
{
    int result = json["result"].toInt();
    switch (result)
    {
    case OK:
    {
        QMessageBox::information(this, "注册", "注册成功");
        break;
    }
    case ERROR:
    {
        QMessageBox::critical(this, "注册", "注册失败，未知错误");
        break;
    }
    case USEREXIST:
    {
        QMessageBox::critical(this, "注册", "注册失败，用户已存在");
        break;
    }
    default:
        break;
    };
}

void Register::on_quitButton_clicked()
{
    this->close();
}
