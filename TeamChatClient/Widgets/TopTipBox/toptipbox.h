#ifndef TOPTIPBOX_H
#define TOPTIPBOX_H

#include <QWidget>
#include <QLabel>
#include <QEvent>
#include <QTimer>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QGraphicsEffect>
#include <QHBoxLayout>
#include <QPainter>
#include <QPainterPath>
#include <QFile>
#include <QResizeEvent>
enum TopTipBoxType {
    INFOTIP,
    WARNINGTIP,
    ERRORTIP
};
class TopTipBox : public QWidget
{
    Q_OBJECT

public:
    TopTipBox();

    void showInformationTopTipBox(QWidget *parent, const QString &text);
    void showWarningTopTipBox(QWidget *parent, const QString &text);
    void showErrorTopTipBox(QWidget *parent, const QString &text);

    void setTopTipBoxSize(QSize size = QSize(350,58));
    void setTopTipBoxAutoSize(bool autosize = true);
    void closeAll();

private:
    TopTipBox(QWidget *parent);
    //控件
    QWidget *widget_this_;              //当前窗口
    QWidget *widget_parent_;            //父窗口
    QLabel *label_icon_;                //图标
    QLabel *label_text_;                //内容
    //变量
    QTimer *timer_show_timeout_;        //动画演出时间控制器
    static TopTipBox* toptipbox_instance_;
    bool auto_size_;                    //窗口大小是否随文本改变
    //方法
    void initControls();                //初始化控件
    void initConnects();            //初始化信号与槽的连接
    void showTopTipBox(QWidget *parent, TopTipBoxType type, const QString &text);      //显示提示框
    void beginAnimation();          //开始动画
    void endAnimation();                //结束动画
    void updateUI(TopTipBoxType type, const QString &text);
    void setIcon(QString url, int size);
    void setStyle(QString path);                                                    //设置样式
    QWidget* getRootWidget(QWidget*);

    bool eventFilter(QObject *watched, QEvent *event);  //调整父窗口放缩后提示框的大小

};

#endif // TOPTIPBOX_H
