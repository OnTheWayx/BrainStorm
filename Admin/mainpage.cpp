#include "mainpage.h"
#include "ui_mainpage.h"

mainpage::mainpage(Communicate *com, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainpage)
{
    ui->setupUi(this);
    _com = com;
    _fp = NULL;

    // 将信号userOnlineInfo与槽函数userOnlineInfoSlots绑定
    connect(_com, SIGNAL(userOnlineInfo(QJsonObject)), this, SLOT(userOnlineInfoSlots(QJsonObject)));

    // 将信号allowToSendFile与槽函数allowToSendFileSlots绑定
    connect(_com, SIGNAL(allowToSendFile()), this, SLOT(allowToSendFileSlots()));

    // 将信号finishSendFile与槽函数finishSendFileSlots绑定
    connect(_com, SIGNAL(finishSendFile()), this, SLOT(finishSendFileSlots()));
}

mainpage::~mainpage()
{
    delete ui;
}

void mainpage::on_refreshButton_clicked()
{
    QJsonObject json;

    json["cmd"] = ADMIN_USERONLINE;
    _com->writeData(json);
}

void mainpage::userOnlineInfoSlots(QJsonObject json)
{
    int num = json["num"].toInt();
    QJsonObject userInfo = json["info"].toObject();
    QJsonArray userName = userInfo["userName"].toArray();
    QJsonArray rank = userInfo["rank"].toArray();

    ui->onlineusernumlabel->setText(QString("在线人数：%1").arg(num - 1));   // 除去管理员自己
    ui->onlineusersInfo->clear();
    ui->onlineusersInfo->addItem(QString("user\t\t\trank"));

    for (int i = 0; i < num; i++)
    {
        if (userName.at(i).toString() != "admin")
        {   // 不将管理员自身添加进在线用户列表中
            QString tmp = QString("%1\t\t\t%2").arg(userName.at(i).toString()).arg(rank.at(i).toString());
            ui->onlineusersInfo->addItem(new QListWidgetItem(tmp));
        }
    }
}

void mainpage::on_uploadADButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("打开文件"), QCoreApplication::applicationFilePath(), "*.*");

    if (filename.isEmpty())
    {
        QMessageBox::information(this, "提示", "请选择一个文件");
    }
    else
    {
        _fp = fopen(filename.toStdString().c_str(), "rb");
        if (_fp == NULL)
        {
            QMessageBox::critical(this, "错误", "读取文件失败");
            return;
        }
        QJsonObject sf_json;
        int begin = filename.lastIndexOf('/');
        QString name(filename.begin() + begin + 1);

        sf_json["cmd"] = UPLOAD_AD_SF;
        sf_json["filename"] = "tmp.jpg";

        _com->writeData(sf_json);
    }
}

void mainpage::allowToSendFileSlots()
{
    QJsonObject json;
    char buf[UPLOAD_AD_BUF_SIZE] = { 0 };
    int tmp;

    if ((tmp = fread(buf, 1, UPLOAD_AD_BUF_SIZE, _fp)) == UPLOAD_AD_BUF_SIZE)
    {// 文件体
        json["cmd"] = UPLOAD_AD_MF;
        json["size"] = UPLOAD_AD_BUF_SIZE;
        _com->writeData(json, buf, UPLOAD_AD_BUF_SIZE);
    }
    else
    {// 文件尾
        json["cmd"] = UPLOAD_AD_EF;
        json["size"] = tmp;
        _com->writeData(json, buf, tmp);

        fclose(_fp);
        _fp = NULL;
    }
}

void mainpage::finishSendFileSlots()
{
    QMessageBox::information(this, "提示", "图片上传成功");
}
