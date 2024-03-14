#ifndef USERINFOCLIENT_H
#define USERINFOCLIENT_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFile>
#include <QPainter>
#include <QPainterPath>
#include <QPixmap>
#include <QPushButton>
#include <QMenu>
#include <QThread>

#include "requestweatherclient.h"
#include "clientglobal.h"

class UserInfoClient : public QWidget
{
    Q_OBJECT
public:
    UserInfoClient();

    enum UserStatus{
        ONLINE,
        OFFLINE,
        INVISIBLE
    };

signals:
    void statusChanged(UserStatus status);                                      //用户状态改变信号
    void getWeathers(int type);

private slots:
    void showStatusMenu();                                                      //显示状态选择菜单
    void chooseStatus(QAction *action);                                         //选择状态
    void handleStatusChanged(UserStatus status);                                //处理用户状态改变
    void setWeather();

private:
    //控件
    QLabel *label_avatar_;                                                      //头像
    QLabel *label_nickname_;                                                    //昵称
    QLabel *label_status_;                                                      //状态
    QPushButton *pushbutton_status_choose_;                                     //状态选择
    QMenu *menu_status_choose_;                                                 //状态选择菜单

    //天气
    QLabel *label_weather_icon_;                                                //天气图标

    //动作
    QAction *action_status_choose_online_;                                      //选择在线
    QAction *action_status_choose_offline_;                                     //选择离线
    QAction *action_status_choose_invisible_;                                   //选择隐身

    //变量
    UserStatus user_status_;                                                    //用户状态
    QThread *thread_weather_;
    RequestWeatherClient *requset_weather_client_;

    void initControls();                                                        //初始化控件
    void initConnects();                                                        //初始化控件与槽函数的连接
    void setStyle(QString path);                                                //设置样式
    void setStatus(UserStatus status);                                          //设置用户状态
    template <typename T>
    void setControlsTextColor(T *control, QString color);                       //设置控件文字颜色
    void setAvatar(QString url = ":/Resources/UserInfo/defaultAvatar.svg", int size = 80);     //设置头像
    void setWeatherIcon(QString url, int size);                                 //设置天气图标
};

#endif // USERINFOCLIENT_H
