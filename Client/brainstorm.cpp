#include "brainstorm.h"
#include "ui_brainstorm.h"

BrainStorm::BrainStorm(Communicate *com, QJsonObject &json, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrainStorm)
{
    ui->setupUi(this);
    _com = com;
    _selfName = json["userName"].toString();
    _selfRank = json["rank"].toString();
    qDebug() << _selfRank;

    // 将信号singleGetQuestion与槽函数singlerecvQuestionSlots关联
    connect(_com, SIGNAL(singleGetQuestion(QJsonObject)), this, SLOT(singlerecvQuestionSlots(QJsonObject)));
    // 将timeout与singlesetLcdNumberSlots关联
    connect(&_singleTimer, SIGNAL(timeout()), this, SLOT(singlesetLcdNumberSlots()));
    // rank
    connect(_com, SIGNAL(rank(QJsonObject)), this, SLOT(rankSlots(QJsonObject)));
    // 将timeout与ranksetLcdNumberSlots关联
    connect(&_rankTimer, SIGNAL(timeout()), this, SLOT(ranksetLcdNumberSlots()));

    // 将信号recvAnswer与recvAnswerSlots绑定
    connect(_com, SIGNAL(recvAnswer(QJsonObject)), this, SLOT(recvAnswerSlots(QJsonObject)));

    //
    connect(_com, SIGNAL(setRankResult(QJsonObject)), this, SLOT(setRankResultSlot(QJsonObject)));

    connect(_com, SIGNAL(DownloadADError()), this, SLOT(DownloadADErrorSlots()));

    connect(_com, SIGNAL(DownloadADSuccess()), this, SLOT(DownloadADSuccessSlots()));

    connect(_com, SIGNAL(recvRankSort(QJsonObject)), this, SLOT(recvRankSortSlots(QJsonObject)));

    connect(_com, SIGNAL(ExitClient()), this, SLOT(ExitClientSlots()));
}

BrainStorm::~BrainStorm()
{
    delete ui;
}

void BrainStorm::on_singleButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->singleready);
}


void BrainStorm::on_singlebackButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->mainpage);
}

void BrainStorm::on_singlestartButton_clicked()
{
    singleGetQuestion();
}

void BrainStorm::singleGetQuestion()
{
    QJsonObject json;

    json["cmd"] = SINGLE_GETQUESTION;

    _com->writeData(json);
}

void BrainStorm::singleSetQuestion()
{
    if (_currentsinglequestion == QUESTION_NUM)
    {
        // 游戏结束，全部答对
        ui->singleResult->setText("恭喜通关，游戏结束！");
        QString score = QString("本次得分 ： %1").arg(_singleScore);
        ui->singleScore->setText(score);
        // 停止计时
        _singleTimer.stop();
        // 跳转到结算界面
        ui->stackedWidget->setCurrentWidget(ui->singleclear);
        return;
    }

    ui->questionlabel->setText(_singlequestions["question"].toArray().at(_currentsinglequestion).toString());
    ui->playOption1Button->setText(_singlequestions["option1"].toArray().at(_currentsinglequestion).toString());
    ui->playOption2Button->setText(_singlequestions["option2"].toArray().at(_currentsinglequestion).toString());
    ui->playOption3Button->setText(_singlequestions["option3"].toArray().at(_currentsinglequestion).toString());
    ui->playOption4Button->setText(_singlequestions["option4"].toArray().at(_currentsinglequestion).toString());
}

void BrainStorm::singlerecvQuestionSlots(QJsonObject json)
{
    // 开始显示题目
    // 初始化游戏记录变量
    _singlequestions = json;
    _currentsinglequestion = 0;
    _singleQuestionSec = SINGLE_QUESTION_SEC;
    _singleScore = 0;

    ui->playlcdNumber->display(_singleQuestionSec);
    singleSetQuestion();
    _singleTimer.start(1000);

    ui->stackedWidget->setCurrentWidget(ui->singleplay);
}

void BrainStorm::singlesetLcdNumberSlots()
{
    --_singleQuestionSec;
    if (_singleQuestionSec == 0)
    {
        ui->singleResult->setText("回答错误，游戏结束");
        QString score = QString("本次得分 ： %1").arg(_singleScore);
        ui->singleScore->setText(score);
        // 停止计时
        _singleTimer.stop();
        // 跳转到结算界面
        ui->stackedWidget->setCurrentWidget(ui->singleclear);
    }
    ui->playlcdNumber->display(_singleQuestionSec);
}

void BrainStorm::singleAnswerQuestion(int answer)
{
    if (answer == _singlequestions["answer"].toArray().at(_currentsinglequestion).toString().toInt())
    {   // 回答正确
        _singleScore += 20 * _singleQuestionSec;
        _currentsinglequestion++;
        // 停止计时并刷新计时器时间
        _singleTimer.stop();
        _singleQuestionSec = SINGLE_QUESTION_SEC;
        ui->playlcdNumber->display(_singleQuestionSec);
        singleSetQuestion();
        _singleTimer.start(1000);
    }
    else
    {   // 回答错误
        ui->singleResult->setText("回答错误，游戏结束");
        QString score = QString("本次得分 ： %1").arg(_singleScore);
        ui->singleScore->setText(score);
        // 停止计时
        _singleTimer.stop();
        // 跳转到结算界面
        ui->stackedWidget->setCurrentWidget(ui->singleclear);
    }
}

void BrainStorm::on_singlebackButton_clear_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->mainpage);
}

void BrainStorm::on_playOption1Button_clicked()
{
    singleAnswerQuestion(1);
}

void BrainStorm::on_playOption2Button_clicked()
{
    singleAnswerQuestion(2);
}

void BrainStorm::on_playOption3Button_clicked()
{
    singleAnswerQuestion(3);
}

void BrainStorm::on_playOption4Button_clicked()
{
    singleAnswerQuestion(4);
}

void BrainStorm::on_matchButton_clicked()
{
    // 给服务器发送排位请求消息
    QJsonObject json;

    json["cmd"] = RANK;
    _com->writeData(json);

    // 跳转到等待页面
    ui->stackedWidget->setCurrentWidget(ui->rankwait);
}

void BrainStorm::setSelfScore()
{
    QString s = QString("%1 %2 得分：%3").arg(_selfName, -8).arg(_selfRank).arg(_rankScore);
    ui->selfstatuslabel->setText(s);
}

void BrainStorm::setEnemyScore()
{
    QString s = QString("%1 %2 得分：%3").arg(enemyName, -8).arg(enemyRank).arg(enemyScore);
    ui->enemystatuslabel->setText(s);
}

void BrainStorm::rankSetQuestion()
{
    ui->rankQuestionlabel->setText(_rankquestions["question"].toArray().at(_currentrankquestion).toString());
    ui->rankOption1Button->setText(_rankquestions["option1"].toArray().at(_currentrankquestion).toString());
    ui->rankOption2Button->setText(_rankquestions["option2"].toArray().at(_currentrankquestion).toString());
    ui->rankOption3Button->setText(_rankquestions["option3"].toArray().at(_currentrankquestion).toString());
    ui->rankOption4Button->setText(_rankquestions["option4"].toArray().at(_currentrankquestion).toString());

    ui->rankOption1Button->setStyleSheet("");
    ui->rankOption2Button->setStyleSheet("");
    ui->rankOption3Button->setStyleSheet("");
    ui->rankOption4Button->setStyleSheet("");

    ui->rankOption1Button->setEnabled(true);
    ui->rankOption2Button->setEnabled(true);
    ui->rankOption3Button->setEnabled(true);
    ui->rankOption4Button->setEnabled(true);

    // 将结果发送给服务器
    if (_currentrankquestion == QUESTION_NUM)
    {        
        _rankTimer.stop();
        // 发送给服务器
        QJsonObject json;

        json["cmd"] = RANKRESULT;
        json["userScore"] = _rankScore;
        json["enemyName"] = enemyName;
        json["enemyScore"] = enemyScore;

        _com->writeData(json);
    }
}

void BrainStorm::ranksetLcdNumberSlots()
{
    _rankQuestionSec--;
    if (_rankQuestionSec == 0)
    {
        _rankQuestionSec = RANK_QUESTION_SEC;
        if (ui->rankOption1Button->isEnabled())
        {// 若此时该按钮是有效的，则说明此时没有答题
            // 将题号加一，并刷新题目
            _currentrankquestion++;
        }
        rankSetQuestion();
    }
    ui->ranklcdNumber->display(_rankQuestionSec);
}

void BrainStorm::rankSlots(QJsonObject json)
{
    enemyName = json["enemyName"].toString();
    enemyRank = json["enemyRank"].toString();
    enemyScore = json["enemyScore"].toInt();

    _rankquestions = json["question"].toObject();
    _rankScore = 0;
    _currentrankquestion = 0;
    _enemyrankquestion = 0;
    _rankQuestionSec = RANK_QUESTION_SEC;
    ui->ranklcdNumber->display(_rankQuestionSec);
    _rankTimer.start(1000);
    setSelfScore();
    setEnemyScore();

    rankSetQuestion();

    ui->stackedWidget->setCurrentWidget(ui->rankplay);
}

void BrainStorm::rankAnswerQuestion(int answer)
{
    if (answer == _rankquestions["answer"].toArray().at(_currentrankquestion).toString().toInt())
    {
        _rankScore += _rankQuestionSec * 20;
    }
    setSelfScore();
    _currentrankquestion++;

    // 判断是否跳到下一题
    if (_currentrankquestion == _enemyrankquestion)
    {
        _rankQuestionSec = RANK_QUESTION_SEC;
        _rankTimer.stop();
        ui->ranklcdNumber->display(_rankQuestionSec);
        _rankTimer.start(1000);
        setEnemyScore();
        rankSetQuestion();
    }
    // 向服务器发送本次做题结果
    QJsonObject json;
    json["cmd"] = ANSWER;
    json["enemyName"] = enemyName;
    json["userScore"] = _rankScore;
    json["questionId"] = _currentrankquestion;

    _com->writeData(json);
}

void BrainStorm::on_rankOption1Button_clicked()
{
    ui->rankOption1Button->setStyleSheet("background-color: rgb(73, 100, 255)");
    ui->rankOption1Button->setEnabled(false);
    ui->rankOption2Button->setEnabled(false);
    ui->rankOption3Button->setEnabled(false);
    ui->rankOption4Button->setEnabled(false);
    rankAnswerQuestion(1);
}

void BrainStorm::on_rankOption2Button_clicked()
{
    ui->rankOption2Button->setStyleSheet("background-color: rgb(73, 100, 255)");
    ui->rankOption1Button->setEnabled(false);
    ui->rankOption2Button->setEnabled(false);
    ui->rankOption3Button->setEnabled(false);
    ui->rankOption4Button->setEnabled(false);
    rankAnswerQuestion(2);
}

void BrainStorm::on_rankOption3Button_clicked()
{
    ui->rankOption3Button->setStyleSheet("background-color: rgb(73, 100, 255)");
    ui->rankOption1Button->setEnabled(false);
    ui->rankOption2Button->setEnabled(false);
    ui->rankOption3Button->setEnabled(false);
    ui->rankOption4Button->setEnabled(false);
    rankAnswerQuestion(3);
}

void BrainStorm::on_rankOption4Button_clicked()
{
    ui->rankOption4Button->setStyleSheet("background-color: rgb(73, 100, 255)");
    ui->rankOption1Button->setEnabled(false);
    ui->rankOption2Button->setEnabled(false);
    ui->rankOption3Button->setEnabled(false);
    ui->rankOption4Button->setEnabled(false);
    rankAnswerQuestion(4);
}

void BrainStorm::recvAnswerSlots(QJsonObject json)
{
    enemyScore = json["enemyScore"].toInt();
    _enemyrankquestion = json["enemyquestionId"].toInt();

    setEnemyScore();
    if (_enemyrankquestion == _currentrankquestion)
    {// 更新到下一题
        _rankQuestionSec = RANK_QUESTION_SEC;
        _rankTimer.stop();
        ui->ranklcdNumber->display(_rankQuestionSec);
        _rankTimer.start(1000);
        rankSetQuestion();
    }
}

void BrainStorm::setRankResultSlot(QJsonObject json)
{
    if (_rankScore == enemyScore)
    {
        ui->rankwinlabel->setText("平局");
    }
    else if (_rankScore > enemyScore)
    {
        ui->rankwinlabel->setText("胜利");
    }
    else
    {
        ui->rankwinlabel->setText("失败");
    }
    QString newRank = json["rankResult"].toString();
    QString result = QString("%1 ---> %2").arg(_selfRank).arg(newRank);
    _selfRank = newRank;
    ui->rankdanlabel->setText(result);
    ui->stackedWidget->setCurrentWidget(ui->rankclear);
}

void BrainStorm::on_rankbackButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->mainpage);
}

void BrainStorm::DownloadADErrorSlots()
{
    ui->ADlabel->setText("加载图片失败");
}

void BrainStorm::DownloadADSuccessSlots()
{
    ui->ADlabel->setPixmap(QPixmap("D:/QT_Workspace/QT_BrainStorm/ADs/tmp.jpg"));
}

void BrainStorm::on_ranksortButton_clicked()
{
    QJsonObject json;

    json["cmd"] = RANKSORT;
    _com->writeData(json);
}

void BrainStorm::recvRankSortSlots(QJsonObject json)
{
    int result = json["result"].toInt();
    QJsonArray namearray = json["userName"].toArray();
    QJsonArray rankarray = json["rank"].toArray();

    if (result == OK)
    {
        int size = json["size"].toInt();
        // 设置行数和列数
        ui->ranksortTableWidget->setRowCount(size);
        ui->ranksortTableWidget->setColumnCount(2);
        // 设置不可编辑
        ui->ranksortTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        // 设置每列宽度
        ui->ranksortTableWidget->setColumnWidth(0, 185);
        ui->ranksortTableWidget->setColumnWidth(1, 185);
        // 设置列头
        QList<QString> setVer_name;
        setVer_name.push_back("昵称");
        setVer_name.push_back("段位");
        QStringList s(setVer_name);
        // 字体
        QFont f1("隶书", 12);
        QFont f2("隶书", 12);
        f1.setBold(true);
        f2.setBold(true);
        ui->ranksortTableWidget->setHorizontalHeaderLabels(s);

        for (int i = 0; i < size; i++)
        {
            ui->ranksortTableWidget->setRowHeight(i, 30);
            QTableWidgetItem *name = new  QTableWidgetItem(namearray[i].toString());
            QTableWidgetItem *rank = new  QTableWidgetItem(rankarray[i].toString());
            // 设置对齐方式
            name->setTextAlignment(Qt::AlignCenter);
            rank->setTextAlignment(Qt::AlignCenter);
            //设置背景
            name->setBackgroundColor(QColor(120, 173, 238));
            name->setTextColor(QColor(174, 232, 235));
            name->setFont(f1); //设置字体
            rank->setBackgroundColor(QColor(120, 173, 238));
            rank->setTextColor(QColor(174, 232, 235));
            rank->setFont(f2);
            ui->ranksortTableWidget->setItem(i, 0, name);
            ui->ranksortTableWidget->setItem(i, 1, rank);
        }
        ui->stackedWidget->setCurrentWidget(ui->ranksortpage);
    }
    else if (result == ERROR)
    {
        QMessageBox::critical(this, "提示", "加载失败");
    }
}

void BrainStorm::on_ranksortbackButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->mainpage);
}

void BrainStorm::ExitClientSlots()
{
    QMessageBox::critical(this, "提示", "已与服务器断开连接");
    this->close();
}
