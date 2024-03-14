#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QPushButton>
#include <QCheckBox>
#include <QTimer>

#include "clientwindow.h"
#include "qframelesswindow.h"
#include "register.h"
#include "retrieve.h"
#include "clientglobal.h"

class Login : public QFramelessWindow
{
    Q_OBJECT
public:
    Login();

signals:

private slots:
    void clearUsernameEditLine(bool);                                                       //清除账号内容
    void clearPasswordEditLine(bool);                                                       //清除密码内容
    void usernameTextChanged(QString text);                                                 //当账号文本改变
    void passwordTextChanged(QString text);                                                 //当密码文本改变
    void clickedLogin();                                                                    //点击登录
    void clickedCheckbox(int status);                                                       //点击复选框
    void clickedRegister();                                                                 //点击注册
    void clickedRetrieve();                                                                 //点击重置
    void onRegisterClose();                                                                 //注册窗口关闭响应函数
    void onRetrieveClose();                                                                 //重置窗口关闭响应函数
    void showHidePasswordEditLine(bool);                                                    //显示/隐藏密码

private:
    //控件
    QLabel *label_avatar_;                                                                  //头像
    QPushButton *pushbutton_login_;                                                         //登录按钮
    QLineEdit *lineedit_username_;                                                          //账号
    QLineEdit *lineedit_password_;                                                          //密码
    QLabel *label_service_agreements_;                                                      //服务协议
    QCheckBox *checkbox_service_agreements_;                                                //是否勾选服务协议
    QLabel *label_register_;                                                                //注册
    QLabel *label_retrieve_;                                                                //找回

    //窗口指针
    Register *register_ = nullptr;                                                          //注册窗口指针
    Retrieve *retrieve_ = nullptr;                                                          //重置窗口指针

    //动作
    QAction *action_username_rightclear_;                                                   //账号右边清除
    QAction *action_password_rightclear_;                                                   //密码右边清除
    QAction *action_password_show_hide_;                                                    //显示/隐藏密码

    //方法
    void initControls();                                                                    //初始化控件
    void initConnects();                                                                    //初始化控件与槽函数的连接
    void setStyle(QString path);                                                            //设置样式
    void setAvatar(QString url = ":/Resources/UserInfo/defaultAvatar.svg", int size = 80);  //设置头像
    bool eventFilter(QObject *obj, QEvent *event);                                          //事件过滤器

};

#endif // LOGIN_H
