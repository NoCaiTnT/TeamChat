#ifndef QFRAMELESSWINDOW_H
#define QFRAMELESSWINDOW_H

#include <QMainWindow>

#include <QWKWidgets/widgetwindowagent.h>
#include "titlebar.h"
#include "titlebarbutton.h"

#include <QTimer>
#include <QCoreApplication>
#include <QGuiApplication>
#include <QStyle>

class QFramelessWindow : public QMainWindow{
    Q_OBJECT

public:
    QFramelessWindow(QWidget *parent = nullptr);
    ~QFramelessWindow();

    //主题
    enum Theme{
        DARK,
        LIGHT
    };

signals:

public slots:
    void clickIconButton();                                                     //点击系统图标
    void clickMaxButton(bool max);                                              //点击最大化按钮

private:
    Theme theme_;                                                               //窗口主题
    QWK::WidgetWindowAgent *window_agent_;                                      //窗口代理
    //标题栏
    TitleBar *title_bar_;                                                       //标题栏
    QLabel *title_text_;                                                        //标题栏文字
    TitleBarButton *icon_button_;                                               //系统图标按钮
    TitleBarButton *min_button_;                                                //标题栏最小化按钮
    TitleBarButton *max_button_;                                                //标题栏最大化按钮
    TitleBarButton *close_button_;                                              //标题栏关闭按钮

    void initTitleBar();                                                        //初始化标题栏
    void initWindow();                                                          //初始化窗口
    void initConnect();                                                         //初始化信号与槽的连接

    static void emulateLeaveEvent(QWidget *widget);
    bool event(QEvent *event) override;                                         //当前窗口是否处于激活状态

public:
    void setTitleBar(QWidget *widget);                                          //设置标题栏
    void setIconButton(QString path = ":/Resources/TitleBar/appIcon.png");      //设置系统图标
    void setTitleText(QString text);                                            //设置标题栏文字
    void setStyle(QString path);                                                //设置样式
    void setTheme(Theme theme);                                                 //设置主题

};
#endif // QFRAMELESSWINDOW_H
