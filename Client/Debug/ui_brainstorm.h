/********************************************************************************
** Form generated from reading UI file 'brainstorm.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRAINSTORM_H
#define UI_BRAINSTORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BrainStorm
{
public:
    QVBoxLayout *verticalLayout_8;
    QStackedWidget *stackedWidget;
    QWidget *mainpage;
    QPushButton *matchButton;
    QPushButton *singleButton;
    QLabel *mainlabel;
    QLabel *ADlabel;
    QPushButton *ranksortButton;
    QWidget *ranksortpage;
    QTableWidget *ranksortTableWidget;
    QPushButton *ranksortbackButton;
    QWidget *singleready;
    QVBoxLayout *verticalLayout;
    QSpacerItem *singleverticalSpacer_1;
    QLabel *singlemainlabel;
    QLabel *singlesubheadabel;
    QSpacerItem *singleverticalSpacer_2;
    QPushButton *singlestartButton;
    QPushButton *singlebackButton;
    QWidget *singleplay;
    QVBoxLayout *verticalLayout_3;
    QWidget *timewidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLCDNumber *playlcdNumber;
    QSpacerItem *verticalSpacer_2;
    QLabel *questionlabel;
    QWidget *optionwidget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *playOption1Button;
    QPushButton *playOption2Button;
    QPushButton *playOption3Button;
    QPushButton *playOption4Button;
    QWidget *singleclear;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_3;
    QLabel *singleResult;
    QSpacerItem *verticalSpacer_4;
    QLabel *singleScore;
    QSpacerItem *verticalSpacer_5;
    QWidget *singleclearbackwidget;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_6;
    QPushButton *singlebackButton_clear;
    QWidget *rankwait;
    QLabel *rankwaitlabel;
    QWidget *rankplay;
    QVBoxLayout *verticalLayout_9;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *enemystatuslabel;
    QLabel *selfstatuslabel;
    QLCDNumber *ranklcdNumber;
    QSpacerItem *verticalSpacer_8;
    QLabel *rankQuestionlabel;
    QSpacerItem *verticalSpacer_7;
    QWidget *widget;
    QVBoxLayout *verticalLayout_6;
    QPushButton *rankOption1Button;
    QPushButton *rankOption2Button;
    QPushButton *rankOption3Button;
    QPushButton *rankOption4Button;
    QWidget *rankclear;
    QVBoxLayout *verticalLayout_10;
    QSpacerItem *verticalSpacer_10;
    QLabel *rankwinlabel;
    QLabel *rankdanlabel;
    QSpacerItem *verticalSpacer_9;
    QPushButton *rankbackButton;

    void setupUi(QDialog *BrainStorm)
    {
        if (BrainStorm->objectName().isEmpty())
            BrainStorm->setObjectName(QStringLiteral("BrainStorm"));
        BrainStorm->resize(410, 610);
        verticalLayout_8 = new QVBoxLayout(BrainStorm);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        stackedWidget = new QStackedWidget(BrainStorm);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        mainpage = new QWidget();
        mainpage->setObjectName(QStringLiteral("mainpage"));
        matchButton = new QPushButton(mainpage);
        matchButton->setObjectName(QStringLiteral("matchButton"));
        matchButton->setGeometry(QRect(90, 40, 201, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(14);
        matchButton->setFont(font);
        singleButton = new QPushButton(mainpage);
        singleButton->setObjectName(QStringLiteral("singleButton"));
        singleButton->setGeometry(QRect(90, 130, 201, 71));
        singleButton->setFont(font);
        mainlabel = new QLabel(mainpage);
        mainlabel->setObjectName(QStringLiteral("mainlabel"));
        mainlabel->setGeometry(QRect(60, 510, 291, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("Bahnschrift Condensed"));
        font1.setPointSize(26);
        mainlabel->setFont(font1);
        mainlabel->setAlignment(Qt::AlignCenter);
        ADlabel = new QLabel(mainpage);
        ADlabel->setObjectName(QStringLiteral("ADlabel"));
        ADlabel->setGeometry(QRect(50, 240, 291, 271));
        ADlabel->setAlignment(Qt::AlignCenter);
        ranksortButton = new QPushButton(mainpage);
        ranksortButton->setObjectName(QStringLiteral("ranksortButton"));
        ranksortButton->setGeometry(QRect(302, 0, 81, 31));
        stackedWidget->addWidget(mainpage);
        ranksortpage = new QWidget();
        ranksortpage->setObjectName(QStringLiteral("ranksortpage"));
        ranksortTableWidget = new QTableWidget(ranksortpage);
        ranksortTableWidget->setObjectName(QStringLiteral("ranksortTableWidget"));
        ranksortTableWidget->setGeometry(QRect(0, 0, 391, 182));
        ranksortbackButton = new QPushButton(ranksortpage);
        ranksortbackButton->setObjectName(QStringLiteral("ranksortbackButton"));
        ranksortbackButton->setGeometry(QRect(0, 540, 381, 41));
        stackedWidget->addWidget(ranksortpage);
        singleready = new QWidget();
        singleready->setObjectName(QStringLiteral("singleready"));
        verticalLayout = new QVBoxLayout(singleready);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        singleverticalSpacer_1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(singleverticalSpacer_1);

        singlemainlabel = new QLabel(singleready);
        singlemainlabel->setObjectName(QStringLiteral("singlemainlabel"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\347\220\245\347\217\200"));
        font2.setPointSize(26);
        singlemainlabel->setFont(font2);
        singlemainlabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(singlemainlabel);

        singlesubheadabel = new QLabel(singleready);
        singlesubheadabel->setObjectName(QStringLiteral("singlesubheadabel"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        singlesubheadabel->setFont(font3);
        singlesubheadabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(singlesubheadabel);

        singleverticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(singleverticalSpacer_2);

        singlestartButton = new QPushButton(singleready);
        singlestartButton->setObjectName(QStringLiteral("singlestartButton"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\351\232\266\344\271\246"));
        font4.setPointSize(14);
        singlestartButton->setFont(font4);

        verticalLayout->addWidget(singlestartButton);

        singlebackButton = new QPushButton(singleready);
        singlebackButton->setObjectName(QStringLiteral("singlebackButton"));
        singlebackButton->setFont(font4);

        verticalLayout->addWidget(singlebackButton);

        stackedWidget->addWidget(singleready);
        singleplay = new QWidget();
        singleplay->setObjectName(QStringLiteral("singleplay"));
        verticalLayout_3 = new QVBoxLayout(singleplay);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        timewidget = new QWidget(singleplay);
        timewidget->setObjectName(QStringLiteral("timewidget"));
        horizontalLayout = new QHBoxLayout(timewidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        playlcdNumber = new QLCDNumber(timewidget);
        playlcdNumber->setObjectName(QStringLiteral("playlcdNumber"));
        playlcdNumber->setMinimumSize(QSize(200, 80));
        playlcdNumber->setMaximumSize(QSize(200, 80));

        horizontalLayout->addWidget(playlcdNumber);


        verticalLayout_3->addWidget(timewidget);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        questionlabel = new QLabel(singleplay);
        questionlabel->setObjectName(QStringLiteral("questionlabel"));
        questionlabel->setMinimumSize(QSize(0, 220));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\351\232\266\344\271\246"));
        font5.setPointSize(12);
        questionlabel->setFont(font5);
        questionlabel->setTextFormat(Qt::AutoText);
        questionlabel->setAlignment(Qt::AlignCenter);
        questionlabel->setWordWrap(true);

        verticalLayout_3->addWidget(questionlabel);

        optionwidget = new QWidget(singleplay);
        optionwidget->setObjectName(QStringLiteral("optionwidget"));
        verticalLayout_2 = new QVBoxLayout(optionwidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        playOption1Button = new QPushButton(optionwidget);
        playOption1Button->setObjectName(QStringLiteral("playOption1Button"));

        verticalLayout_2->addWidget(playOption1Button);

        playOption2Button = new QPushButton(optionwidget);
        playOption2Button->setObjectName(QStringLiteral("playOption2Button"));

        verticalLayout_2->addWidget(playOption2Button);

        playOption3Button = new QPushButton(optionwidget);
        playOption3Button->setObjectName(QStringLiteral("playOption3Button"));

        verticalLayout_2->addWidget(playOption3Button);

        playOption4Button = new QPushButton(optionwidget);
        playOption4Button->setObjectName(QStringLiteral("playOption4Button"));

        verticalLayout_2->addWidget(playOption4Button);


        verticalLayout_3->addWidget(optionwidget);

        stackedWidget->addWidget(singleplay);
        singleclear = new QWidget();
        singleclear->setObjectName(QStringLiteral("singleclear"));
        verticalLayout_4 = new QVBoxLayout(singleclear);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        singleResult = new QLabel(singleclear);
        singleResult->setObjectName(QStringLiteral("singleResult"));
        singleResult->setMinimumSize(QSize(0, 200));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\351\232\266\344\271\246"));
        font6.setPointSize(10);
        singleResult->setFont(font6);
        singleResult->setAlignment(Qt::AlignCenter);
        singleResult->setWordWrap(true);

        verticalLayout_4->addWidget(singleResult);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);

        singleScore = new QLabel(singleclear);
        singleScore->setObjectName(QStringLiteral("singleScore"));
        singleScore->setMinimumSize(QSize(0, 100));
        singleScore->setFont(font6);
        singleScore->setAlignment(Qt::AlignCenter);
        singleScore->setWordWrap(true);

        verticalLayout_4->addWidget(singleScore);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);

        singleclearbackwidget = new QWidget(singleclear);
        singleclearbackwidget->setObjectName(QStringLiteral("singleclearbackwidget"));
        singleclearbackwidget->setMinimumSize(QSize(0, 100));
        verticalLayout_5 = new QVBoxLayout(singleclearbackwidget);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_6);

        singlebackButton_clear = new QPushButton(singleclearbackwidget);
        singlebackButton_clear->setObjectName(QStringLiteral("singlebackButton_clear"));
        singlebackButton_clear->setFont(font4);

        verticalLayout_5->addWidget(singlebackButton_clear);


        verticalLayout_4->addWidget(singleclearbackwidget);

        stackedWidget->addWidget(singleclear);
        rankwait = new QWidget();
        rankwait->setObjectName(QStringLiteral("rankwait"));
        rankwaitlabel = new QLabel(rankwait);
        rankwaitlabel->setObjectName(QStringLiteral("rankwaitlabel"));
        rankwaitlabel->setGeometry(QRect(30, 120, 331, 101));
        rankwaitlabel->setFont(font4);
        rankwaitlabel->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(rankwait);
        rankplay = new QWidget();
        rankplay->setObjectName(QStringLiteral("rankplay"));
        verticalLayout_9 = new QVBoxLayout(rankplay);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        widget_3 = new QWidget(rankplay);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMaximumSize(QSize(16777215, 200));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_7 = new QVBoxLayout(widget_2);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        enemystatuslabel = new QLabel(widget_2);
        enemystatuslabel->setObjectName(QStringLiteral("enemystatuslabel"));

        verticalLayout_7->addWidget(enemystatuslabel);

        selfstatuslabel = new QLabel(widget_2);
        selfstatuslabel->setObjectName(QStringLiteral("selfstatuslabel"));

        verticalLayout_7->addWidget(selfstatuslabel);


        horizontalLayout_2->addWidget(widget_2);

        ranklcdNumber = new QLCDNumber(widget_3);
        ranklcdNumber->setObjectName(QStringLiteral("ranklcdNumber"));

        horizontalLayout_2->addWidget(ranklcdNumber);


        verticalLayout_9->addWidget(widget_3);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_8);

        rankQuestionlabel = new QLabel(rankplay);
        rankQuestionlabel->setObjectName(QStringLiteral("rankQuestionlabel"));
        rankQuestionlabel->setMinimumSize(QSize(0, 200));
        rankQuestionlabel->setFont(font5);
        rankQuestionlabel->setAlignment(Qt::AlignCenter);
        rankQuestionlabel->setWordWrap(true);

        verticalLayout_9->addWidget(rankQuestionlabel);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_7);

        widget = new QWidget(rankplay);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(16777215, 300));
        verticalLayout_6 = new QVBoxLayout(widget);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        rankOption1Button = new QPushButton(widget);
        rankOption1Button->setObjectName(QStringLiteral("rankOption1Button"));
        rankOption1Button->setAutoFillBackground(false);

        verticalLayout_6->addWidget(rankOption1Button);

        rankOption2Button = new QPushButton(widget);
        rankOption2Button->setObjectName(QStringLiteral("rankOption2Button"));

        verticalLayout_6->addWidget(rankOption2Button);

        rankOption3Button = new QPushButton(widget);
        rankOption3Button->setObjectName(QStringLiteral("rankOption3Button"));

        verticalLayout_6->addWidget(rankOption3Button);

        rankOption4Button = new QPushButton(widget);
        rankOption4Button->setObjectName(QStringLiteral("rankOption4Button"));

        verticalLayout_6->addWidget(rankOption4Button);


        verticalLayout_9->addWidget(widget);

        stackedWidget->addWidget(rankplay);
        rankclear = new QWidget();
        rankclear->setObjectName(QStringLiteral("rankclear"));
        verticalLayout_10 = new QVBoxLayout(rankclear);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_10->addItem(verticalSpacer_10);

        rankwinlabel = new QLabel(rankclear);
        rankwinlabel->setObjectName(QStringLiteral("rankwinlabel"));
        QFont font7;
        font7.setFamily(QString::fromUtf8("\351\232\266\344\271\246"));
        font7.setPointSize(20);
        rankwinlabel->setFont(font7);
        rankwinlabel->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(rankwinlabel);

        rankdanlabel = new QLabel(rankclear);
        rankdanlabel->setObjectName(QStringLiteral("rankdanlabel"));
        rankdanlabel->setFont(font5);
        rankdanlabel->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(rankdanlabel);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_9);

        rankbackButton = new QPushButton(rankclear);
        rankbackButton->setObjectName(QStringLiteral("rankbackButton"));

        verticalLayout_10->addWidget(rankbackButton);

        stackedWidget->addWidget(rankclear);

        verticalLayout_8->addWidget(stackedWidget);


        retranslateUi(BrainStorm);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(BrainStorm);
    } // setupUi

    void retranslateUi(QDialog *BrainStorm)
    {
        BrainStorm->setWindowTitle(QApplication::translate("BrainStorm", "Dialog", Q_NULLPTR));
        matchButton->setText(QApplication::translate("BrainStorm", "\346\216\222\344\275\215\350\265\233", Q_NULLPTR));
        singleButton->setText(QApplication::translate("BrainStorm", "\344\270\252\344\272\272\350\256\255\347\273\203", Q_NULLPTR));
        mainlabel->setText(QApplication::translate("BrainStorm", "BrainStorm", Q_NULLPTR));
        ADlabel->setText(QString());
        ranksortButton->setText(QApplication::translate("BrainStorm", "\346\216\222\350\241\214\346\246\234", Q_NULLPTR));
        ranksortbackButton->setText(QApplication::translate("BrainStorm", "\350\277\224\345\233\236", Q_NULLPTR));
        singlemainlabel->setText(QApplication::translate("BrainStorm", "\350\277\236\347\273\255\347\255\224\345\257\271\344\272\224\351\201\223\351\242\230", Q_NULLPTR));
        singlesubheadabel->setText(QApplication::translate("BrainStorm", "\347\255\224\345\257\271\347\273\247\347\273\255\357\274\214\347\255\224\351\224\231\351\200\200\345\207\272", Q_NULLPTR));
        singlestartButton->setText(QApplication::translate("BrainStorm", "\345\274\200\345\247\213\347\255\224\351\242\230", Q_NULLPTR));
        singlebackButton->setText(QApplication::translate("BrainStorm", "\350\277\224\345\233\236", Q_NULLPTR));
        questionlabel->setText(QString());
        playOption1Button->setText(QString());
        playOption2Button->setText(QString());
        playOption3Button->setText(QString());
        playOption4Button->setText(QString());
        singleResult->setText(QString());
        singleScore->setText(QString());
        singlebackButton_clear->setText(QApplication::translate("BrainStorm", "\350\277\224\345\233\236", Q_NULLPTR));
        rankwaitlabel->setText(QApplication::translate("BrainStorm", "\346\255\243\345\234\250\345\214\271\351\205\215\345\257\271\346\211\213...", Q_NULLPTR));
        enemystatuslabel->setText(QApplication::translate("BrainStorm", "\345\260\217\346\230\216 \351\273\204\351\207\2211 1\351\242\227\346\230\237 \345\276\227\345\210\206\357\274\232120", Q_NULLPTR));
        selfstatuslabel->setText(QApplication::translate("BrainStorm", "\345\260\217\347\272\242 \347\231\275\351\223\2662 2\351\242\227\346\230\237 \345\276\227\345\210\206\357\274\232140", Q_NULLPTR));
        rankQuestionlabel->setText(QApplication::translate("BrainStorm", "\351\227\256\351\242\230", Q_NULLPTR));
        rankOption1Button->setText(QApplication::translate("BrainStorm", "PushButton", Q_NULLPTR));
        rankOption2Button->setText(QApplication::translate("BrainStorm", "PushButton", Q_NULLPTR));
        rankOption3Button->setText(QApplication::translate("BrainStorm", "PushButton", Q_NULLPTR));
        rankOption4Button->setText(QApplication::translate("BrainStorm", "PushButton", Q_NULLPTR));
        rankwinlabel->setText(QApplication::translate("BrainStorm", "\350\203\234\345\210\251\357\274\201", Q_NULLPTR));
        rankdanlabel->setText(QApplication::translate("BrainStorm", "\351\273\204\351\207\2211 1\351\242\227\346\230\237 ---> \351\273\204\351\207\2211 2\351\242\227\346\230\237", Q_NULLPTR));
        rankbackButton->setText(QApplication::translate("BrainStorm", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BrainStorm: public Ui_BrainStorm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRAINSTORM_H
