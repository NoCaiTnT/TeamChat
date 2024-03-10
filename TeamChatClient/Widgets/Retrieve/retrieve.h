#ifndef RETRIEVE_H
#define RETRIEVE_H

#include <QWidget>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedLayout>

#include "qframelesswindow.h"
#include "qstringutils.h"

class Retrieve : public QFramelessWindow
{
    Q_OBJECT
public:
    explicit Retrieve(QWidget *parent = nullptr);

signals:
    void retrieveClosed();                                      //窗口关闭信号

public slots:
    void clickedRetrieve();                                     //点击找回
    void clearEmailEditLine(bool);                                                  //清除邮箱
    void clearEmailVerificationCodeEditLine(bool);                                  //清除邮箱验证码
    void clearPasswordEditLine(bool);
    void clearRePasswordEditLine(bool);
    void emailTextChanged(QString text);                                            //当邮箱文本改变
    void emailVerificationCodeTextChanged(QString text);                            //当验证码文本改变
    void passwordTextChanged(QString text);
    void rePasswordTextChanged(QString text);
    void clickedEmailSendVerificationCode();                                        //点击发送验证码
    void showHidePasswordEditLine(bool);
    void showHideRePasswordEditLine(bool);
    void clickedCommit();

private:
    //变量
    bool verification_flag_emile_;                                      //邮箱验证标志位
    bool verification_new_password_[2] = {false, false};

    QStringUtils * qsu_ = new QStringUtils();                                       //QString工具类

    QTimer *timer_send_verification_code_;                           //验证码计时器
    int send_interval_ = 30;                                                        //发送验证码的间隔（s）

    QVBoxLayout *vboxlayout_total_;                                    //整体纵向布局

    //控件
    QLabel *label_title_;                                       //标题
    QLabel *label_message_;                                     //欢迎语
    QLineEdit *lineedit_email_;                                 //找回邮箱输入
    QLineEdit *lineedit_email_verification_code_;               //验证码输入
    QPushButton *pushbutton_email_send_verification_code_;      //点击发送验证码
    QPushButton *pushbutton_retrieve_;                          //找回
    QLabel *label_email_error_tip_;                                                 //邮箱输入错误提示
    QLineEdit *lineedit_password_;
    QLineEdit *lineedit_repassword_;
    QLabel *label_repassword_error_tip_;
    QLabel *label_password_error_tip_;
    QPushButton *pushbutton_commit_;                                    //提交密码
    //动作
    QAction *action_email_rightclear_;                                              //邮箱右边清除
    QAction *action_email_verification_code_password_rightclear_;                   //验证码右边清除
    QAction *action_password_show_hide_;                                            //显示/隐藏密码
    QAction *action_password_tip_;                                                  //密码格式提示
    QAction *action_password_rightclear_;                                           //密码右边清除
    QAction *action_repassword_rightclear_;                                           //密码右边清除
    QAction *action_repassword_show_hide_;

    void initTitleBar();                                        //初始化标题栏
    void initControls();                                        //初始化控件
    void initConnects();                                        //初始化控件与槽函数的连接
    void setStyle(QString path);                                //设置样式
    void closeEvent(QCloseEvent *e);                            //窗口关闭事件

    void passwordVerification();                        //密码输入是否合法

};

#endif // RETRIEVE_H
