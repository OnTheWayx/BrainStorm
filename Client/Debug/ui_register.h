/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *userNamelabel;
    QLineEdit *userNamelineEdit;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *passWdlabel;
    QLineEdit *passWdlineEdit;
    QPushButton *registerButton;
    QPushButton *quitButton;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(330, 210);
        Register->setMinimumSize(QSize(330, 210));
        Register->setMaximumSize(QSize(330, 210));
        widget_3 = new QWidget(Register);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(10, 10, 311, 189));
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(widget_3);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        userNamelabel = new QLabel(widget);
        userNamelabel->setObjectName(QStringLiteral("userNamelabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(14);
        userNamelabel->setFont(font);
        userNamelabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(userNamelabel);

        userNamelineEdit = new QLineEdit(widget);
        userNamelineEdit->setObjectName(QStringLiteral("userNamelineEdit"));

        horizontalLayout->addWidget(userNamelineEdit);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        passWdlabel = new QLabel(widget_2);
        passWdlabel->setObjectName(QStringLiteral("passWdlabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setWeight(50);
        passWdlabel->setFont(font1);
        passWdlabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(passWdlabel);

        passWdlineEdit = new QLineEdit(widget_2);
        passWdlineEdit->setObjectName(QStringLiteral("passWdlineEdit"));
        passWdlineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(passWdlineEdit);


        verticalLayout->addWidget(widget_2);

        registerButton = new QPushButton(widget_3);
        registerButton->setObjectName(QStringLiteral("registerButton"));

        verticalLayout->addWidget(registerButton);

        quitButton = new QPushButton(widget_3);
        quitButton->setObjectName(QStringLiteral("quitButton"));

        verticalLayout->addWidget(quitButton);


        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Dialog", Q_NULLPTR));
        userNamelabel->setText(QApplication::translate("Register", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        passWdlabel->setText(QApplication::translate("Register", "\345\257\206  \347\240\201", Q_NULLPTR));
        registerButton->setText(QApplication::translate("Register", "\347\253\213\345\215\263\346\263\250\345\206\214", Q_NULLPTR));
        quitButton->setText(QApplication::translate("Register", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
