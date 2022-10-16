#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include "communicate.h"
#include "../common.h"
#include <QMessageBox>

#include <QDebug>

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(Communicate *com, QWidget *parent = 0);
    ~Register();

private slots:
    void on_registerButton_clicked();

    void on_quitButton_clicked();

    // 接收rstResult对应的槽函数
    void rstResultSlots(QJsonObject json);

private:
    Ui::Register *ui;
    Communicate *_com;
};

#endif // REGISTER_H
