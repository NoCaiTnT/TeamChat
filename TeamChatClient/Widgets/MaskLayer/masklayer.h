#ifndef MASKLAYER_H
#define MASKLAYER_H

#include <QWidget>
#include <QApplication>

class MaskLayer : public QWidget
{
    Q_OBJECT
public:
    explicit MaskLayer(QWidget *parent = nullptr);

public:
    void setChildWidget(QWidget *widget);   //设置子窗口
    void setParentWidget(QWidget *widget);  //设置父窗口
    void setMaskColor(const QColor &color, float opacity);  //设置遮罩层颜色以及透明度
    void setMaskSize(int leftDiff, int topDiff, int rightDiff, int downDiff);  //设置遮罩层大小

private:
    //变量
    QWidget *widget_child_;
    QWidget *widget_parrent_;
    int leftDiff_ = 0;
    int topDiff_ = 0;
    int rightDiff_ = 0;
    int downDiff_ = 0;

    void showEvent(QShowEvent *event);
    bool eventFilter(QObject *watched, QEvent *event);
};

#endif // MASKLAYER_H
