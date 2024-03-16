#ifndef RETRIEVE_H
#define RETRIEVE_H

#include <QWidget>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QThread>

#include "qframelesswindow.h"
#include "qstringutils.h"
#include "requestemailclient.h"
#include "clientglobal.h"
#include "toptipbox.h"

class Retrieve : public QFramelessWindow
{
    Q_OBJECT
public:
    explicit Retrieve(QWidget *parent = nullptr);

signals:
    void retrieveClosed();                                                          //窗口关闭信号
    void sendRetrieveEmail(QString);                                                //发送找回密码邮件

public slots:
    void clickedRetrieve();                                                         //点击找回
    void clearEmailEditLine(bool);                                                  //清除邮箱
    void clearEmailVerificationCodeEditLine(bool);                                  //清除邮箱验证码
    void clearPasswordEditLine(bool);                                               //清除新密码
    void clearRePasswordEditLine(bool);                                             //清除重复密码
    void emailTextChanged(QString text);                                            //当邮箱文本改变
    void emailVerificationCodeTextChanged(QString text);                            //当验证码文本改变
    void passwordTextChanged(QString text);                                         //当新密码文本改变
    void rePasswordTextChanged(QString text);                                       //当重复密码文本改变
    void clickedEmailSendVerificationCode();                                        //点击发送验证码
    void showHidePasswordEditLine(bool);                                            //显示/隐藏新密码
    void showHideRePasswordEditLine(bool);                                          //显示/隐藏重复密码
    void clickedCommit();                                                           //点击提交
    void handleSendRetrieveEmail(bool reply);                                       //处理发送邮件结果

private:
    //变量
    bool verification_flag_emile_;                                                  //邮箱验证标志位
    bool verification_new_password_[2] = {false, false};                            //新密码验证标志位
    QStringUtils * qsu_ = new QStringUtils();                                       //QString工具类
    QTimer *timer_send_verification_code_;                                          //验证码计时器
    int send_interval_ = 30;                                                        //发送验证码的间隔（s）
    QVBoxLayout *vboxlayout_total_;                                                 //整体纵向布局
    RequestEmailClient *requset_email_client_ = nullptr;                            //请求重置邮件
    QThread *thread_retrieve_send_email_ = nullptr;                                 //发送验证码线程
    bool isclosed = false;                                                          //窗口是否关闭
    TopTipBox toptipbox_verification_code_;                                         //弹窗

    //控件
    QLabel *label_title_;                                                           //标题
    QLabel *label_message_;                                                         //欢迎语
    QLineEdit *lineedit_email_;                                                     //找回邮箱输入
    QLineEdit *lineedit_email_verification_code_;                                   //验证码输入
    QPushButton *pushbutton_email_send_verification_code_;                          //点击发送验证码
    QPushButton *pushbutton_retrieve_;                                              //找回
    QLabel *label_email_error_tip_;                                                 //邮箱输入错误提示
    QLineEdit *lineedit_password_;                                                  //新密码输入
    QLineEdit *lineedit_repassword_;                                                //重复新密码输入
    QLabel *label_password_error_tip_;                                              //密码错误提示
    QLabel *label_repassword_error_tip_;                                            //重复密码错误提示
    QPushButton *pushbutton_commit_;                                                //提交密码

    //动作
    QAction *action_email_rightclear_;                                              //邮箱右边清除
    QAction *action_email_verification_code_password_rightclear_;                   //验证码右边清除
    QAction *action_password_show_hide_;                                            //显示/隐藏密码
    QAction *action_password_tip_;                                                  //密码格式提示
    QAction *action_password_rightclear_;                                           //密码右边清除
    QAction *action_repassword_rightclear_;                                         //密码右边清除
    QAction *action_repassword_show_hide_;

    void initTitleBar();                                                            //初始化标题栏
    void initControls();                                                            //初始化控件
    void initConnects();                                                            //初始化控件与槽函数的连接
    void setStyle(QString path);                                                    //设置样式
    void closeEvent(QCloseEvent *e);                                                //窗口关闭事件

    void passwordVerification();                                                    //密码输入是否合法

};

#endif // RETRIEVE_H
