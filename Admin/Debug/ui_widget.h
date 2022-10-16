/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *userNamelabel;
    QLineEdit *userNamelineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *passWdlabel;
    QLineEdit *passWdlineEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *loginButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(470, 370);
        Widget->setMinimumSize(QSize(470, 370));
        Widget->setMaximumSize(QSize(470, 370));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 90, 341, 191));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        userNamelabel = new QLabel(layoutWidget);
        userNamelabel->setObjectName(QStringLiteral("userNamelabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(14);
        userNamelabel->setFont(font);
        userNamelabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(userNamelabel);

        userNamelineEdit = new QLineEdit(layoutWidget);
        userNamelineEdit->setObjectName(QStringLiteral("userNamelineEdit"));

        horizontalLayout->addWidget(userNamelineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        passWdlabel = new QLabel(layoutWidget);
        passWdlabel->setObjectName(QStringLiteral("passWdlabel"));
        passWdlabel->setFont(font);
        passWdlabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(passWdlabel);

        passWdlineEdit = new QLineEdit(layoutWidget);
        passWdlineEdit->setObjectName(QStringLiteral("passWdlineEdit"));
        passWdlineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(passWdlineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        loginButton = new QPushButton(layoutWidget);
        loginButton->setObjectName(QStringLiteral("loginButton"));

        horizontalLayout_3->addWidget(loginButton);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        userNamelabel->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        userNamelineEdit->setText(QApplication::translate("Widget", "admin", Q_NULLPTR));
        passWdlabel->setText(QApplication::translate("Widget", "\345\257\206  \347\240\201", Q_NULLPTR));
        passWdlineEdit->setText(QApplication::translate("Widget", "123456", Q_NULLPTR));
        loginButton->setText(QApplication::translate("Widget", "\347\231\273\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
