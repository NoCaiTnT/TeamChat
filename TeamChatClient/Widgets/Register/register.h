#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "qframelesswindow.h"
#include "qstringutils.h"

class Register : public QFramelessWindow
{
    Q_OBJECT
public:
    explicit Register(QWidget *parent = nullptr);

signals:
    void registerClosed();                                                          //窗口关闭信号

private slots:
    void clearNicknameEditLine(bool);                                               //清除账号
    void clearPasswordEditLine(bool);                                               //清除密码
    void clearEmailEditLine(bool);                                                  //清除邮箱
    void clearEmailVerificationCodeEditLine(bool);                                  //清除邮箱验证码
    void nicknameeTextChanged(QString text);                                        //当账号文本改变
    void passwordTextChanged(QString text);                                         //当密码文本改变
    void emailTextChanged(QString text);                                            //当邮箱文本改变
    void emailVerificationCodeTextChanged(QString text);                            //当验证码文本改变
    void clickedCheckbox(int status);                                               //点击复选框
    void clickedRegister();                                                         //点击注册
    void clickedEmailSendVerificationCode();                                        //点击发送验证码
    void showHidePasswordEditLine(bool);                                            //显示/隐藏密码

private:
    //变量
    bool verification_flags_[5] = { false, false, false, false };                   //验证标志位(昵称、密码、邮箱、服务协议)
    QStringUtils * qsu_ = new QStringUtils();                                       //QString工具类
    QTimer *timer_send_verification_code_;                                          //验证码计时器
    int send_interval_ = 30;                                                        //发送验证码的间隔（s）
    //控件
    QLabel *label_welcome_title_;                                                   //欢迎标题
    QLabel *label_welcome_message_;                                                 //欢迎词
    QLineEdit *lineedit_nickname_;                                                  //昵称输入
    QLineEdit *lineedit_password_;                                                  //密码输入
    QLineEdit *lineedit_email_;                                                     //邮箱输入
    QLineEdit *lineedit_email_verification_code_;                                   //验证码输入
    QPushButton *pushbutton_email_send_verification_code_;                          //点击发送验证码
    QLabel *label_service_agreements_;                                              //服务协议
    QCheckBox *checkbox_service_agreements_;                                        //是否勾选服务协议
    QPushButton *pushbutton_register_;                                              //注册按钮
    QLabel *label_nickname_error_tip_;                                              //昵称输入错误提示
    QLabel *label_password_error_tip_;                                              //密码输入错误提示
    QLabel *label_email_error_tip_;                                                 //邮箱输入错误提示

    //动作
    QAction *action_nickname_rightclear_;                                           //账号右边清除
    QAction *action_password_rightclear_;                                           //密码右边清除
    QAction *action_email_rightclear_;                                              //邮箱右边清除
    QAction *action_email_verification_code_password_rightclear_;                   //验证码右边清除
    QAction *action_password_show_hide_;                                            //显示/隐藏密码
    QAction *action_password_tip_;                                                  //密码格式提示


    void initTitleBar();                                                            //初始化标题栏
    void initControls();                                                            //初始化控件
    void initConnects();                                                            //初始化控件与槽函数的连接
    void setStyle(QString path);                                                    //设置样式
    void closeEvent(QCloseEvent *e);                                                //窗口关闭事件

    void allInputVerification();                                                    //是否全部输入正确


};

#endif // REGISTER_H
