/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *userNamelabel;
    QLabel *passWdlabel;
    QLineEdit *userNamelineEdit;
    QLineEdit *passWdlineEdit;
    QPushButton *loginButton;
    QPushButton *registerButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(570, 465);
        Widget->setMinimumSize(QSize(570, 465));
        Widget->setMaximumSize(QSize(570, 465));
        userNamelabel = new QLabel(Widget);
        userNamelabel->setObjectName(QStringLiteral("userNamelabel"));
        userNamelabel->setGeometry(QRect(90, 110, 72, 15));
        passWdlabel = new QLabel(Widget);
        passWdlabel->setObjectName(QStringLiteral("passWdlabel"));
        passWdlabel->setGeometry(QRect(110, 190, 72, 15));
        userNamelineEdit = new QLineEdit(Widget);
        userNamelineEdit->setObjectName(QStringLiteral("userNamelineEdit"));
        userNamelineEdit->setGeometry(QRect(240, 110, 113, 21));
        passWdlineEdit = new QLineEdit(Widget);
        passWdlineEdit->setObjectName(QStringLiteral("passWdlineEdit"));
        passWdlineEdit->setGeometry(QRect(230, 180, 113, 21));
        loginButton = new QPushButton(Widget);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(110, 270, 93, 28));
        registerButton = new QPushButton(Widget);
        registerButton->setObjectName(QStringLiteral("registerButton"));
        registerButton->setGeometry(QRect(250, 270, 93, 28));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        userNamelabel->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        passWdlabel->setText(QApplication::translate("Widget", "\345\257\206\347\240\201", Q_NULLPTR));
        loginButton->setText(QApplication::translate("Widget", "\347\231\273\345\275\225", Q_NULLPTR));
        registerButton->setText(QApplication::translate("Widget", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
