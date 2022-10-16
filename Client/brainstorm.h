#ifndef BRAINSTORM_H
#define BRAINSTORM_H

#include <QDialog>
#include <QJsonObject>
#include <QJsonDocument>
#include "communicate.h"
#include <QJsonArray>
#include <QTimer>
#include <string>
#include <QMessageBox>

#define SINGLE_QUESTION_SEC 10
#define RANK_QUESTION_SEC 10;

namespace Ui {
class BrainStorm;
}

class BrainStorm : public QDialog
{
    Q_OBJECT

public:
    explicit BrainStorm(Communicate *com, QJsonObject &json, QWidget *parent = 0);
    ~BrainStorm();

private slots:
    void on_singleButton_clicked();

    void on_singlebackButton_clicked();

    void on_singlestartButton_clicked();

    // 接收singleGetQuestion信号
    void singlerecvQuestionSlots(QJsonObject json);

    // 相应的计时器timeout信号处理槽函数
    void singlesetLcdNumberSlots();

    void on_singlebackButton_clear_clicked();

    void on_playOption1Button_clicked();

    void on_playOption2Button_clicked();

    void on_playOption3Button_clicked();

    void on_playOption4Button_clicked();

    void on_matchButton_clicked();

    // --rank----
    // 接收rank信号槽函数
    void rankSlots(QJsonObject json);

    // 相应的rank计时器timeout信号处理槽函数
    void ranksetLcdNumberSlots();

    void on_rankOption1Button_clicked();

    void on_rankOption3Button_clicked();

    void on_rankOption4Button_clicked();

    void on_rankOption2Button_clicked();

    // recvAnswer信号对应的槽函数
    void recvAnswerSlots(QJsonObject json);

    // setRankResult信号对应的槽函数
    void setRankResultSlot(QJsonObject json);

    void on_rankbackButton_clicked();

    // ------
    // 加载广告失败相应处理槽函数
    void DownloadADErrorSlots();

    // 加载广告成功相应处理槽函数
    void DownloadADSuccessSlots();

    void on_ranksortButton_clicked();

    // 接收排行榜数据信号相应处理槽函数
    void recvRankSortSlots(QJsonObject json);

    void on_ranksortbackButton_clicked();

    void ExitClientSlots();

private:
    // single
    // 从服务器获取题目
    void singleGetQuestion();

    // 根据_singlequestions和_currentsinglequestion设置当前显示题目
    void singleSetQuestion();

    // 点击答案选项逻辑函数
    void singleAnswerQuestion(int answer);

    // rank
    // 设置自己和对手的对手
    void setSelfScore();
    void setEnemyScore();

    // 设置当前显示题目
    void rankSetQuestion();

    // rank点击答案选项逻辑函数
    void rankAnswerQuestion(int answer);


    //

private:
    Ui::BrainStorm *ui;
    Communicate *_com;

    QString _selfRank;
    QString _selfName;

    // single
    QJsonObject _singlequestions;   // 个人训练-从服务器获取的题目
    int _currentsinglequestion;     // 当前页面显示的题目下标
    QTimer _singleTimer;            //个人训练答题计时器
    int _singleQuestionSec;         // 个人训练答题计时时间
    int _singleScore;               // 个人训练得分

    // rank
    QJsonObject _rankquestions;     // rank-从服务器获取的题目
    int _currentrankquestion;       // 当前页面显示的题目下标
    int _enemyrankquestion;         // 当前对手的题目下标

    QTimer _rankTimer;              // rank答题计时器
    int _rankQuestionSec;           // rank答题计时时间
    int _rankScore;                 // rank训练得分

    QString enemyName;          // 对手的用户名
    QString enemyRank;          // 对手的段位描述
    int enemyScore;                 // 对手的分数
};

#endif // BRAINSTORM_H
