#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QJsonObject>
#include "communicate.h"
#include <QMessageBox>
#include "mainpage.h"
#include "../common.h"
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

    void loginResultSlots(QJsonObject json);

private:
    Ui::Widget *ui;
    Communicate *_com;
};

#endif // WIDGET_H
