/********************************************************************************
** Form generated from reading UI file 'mainpage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGE_H
#define UI_MAINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_mainpage
{
public:
    QPushButton *refreshButton;
    QPushButton *uploadADButton;
    QListWidget *onlineusersInfo;
    QLabel *onlineusernumlabel;

    void setupUi(QDialog *mainpage)
    {
        if (mainpage->objectName().isEmpty())
            mainpage->setObjectName(QStringLiteral("mainpage"));
        mainpage->resize(470, 400);
        mainpage->setMinimumSize(QSize(470, 400));
        mainpage->setMaximumSize(QSize(470, 400));
        refreshButton = new QPushButton(mainpage);
        refreshButton->setObjectName(QStringLiteral("refreshButton"));
        refreshButton->setGeometry(QRect(60, 340, 131, 31));
        uploadADButton = new QPushButton(mainpage);
        uploadADButton->setObjectName(QStringLiteral("uploadADButton"));
        uploadADButton->setGeometry(QRect(280, 340, 131, 31));
        onlineusersInfo = new QListWidget(mainpage);
        onlineusersInfo->setObjectName(QStringLiteral("onlineusersInfo"));
        onlineusersInfo->setGeometry(QRect(60, 40, 351, 281));
        onlineusernumlabel = new QLabel(mainpage);
        onlineusernumlabel->setObjectName(QStringLiteral("onlineusernumlabel"));
        onlineusernumlabel->setGeometry(QRect(10, 10, 91, 16));

        retranslateUi(mainpage);

        QMetaObject::connectSlotsByName(mainpage);
    } // setupUi

    void retranslateUi(QDialog *mainpage)
    {
        mainpage->setWindowTitle(QApplication::translate("mainpage", "Dialog", Q_NULLPTR));
        refreshButton->setText(QApplication::translate("mainpage", "\345\210\267\346\226\260\346\225\260\346\215\256", Q_NULLPTR));
        uploadADButton->setText(QApplication::translate("mainpage", "\344\270\212\344\274\240\345\271\277\345\221\212\345\233\276\347\211\207", Q_NULLPTR));
        onlineusernumlabel->setText(QApplication::translate("mainpage", "\345\234\250\347\272\277\344\272\272\346\225\260\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mainpage: public Ui_mainpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGE_H
