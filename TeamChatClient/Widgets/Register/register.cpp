#include "register.h"

Register::Register(QWidget *parent) : QFramelessWindow{parent} {
    this->setAttribute(Qt::WA_DeleteOnClose);
    initTitleBar();
    initControls();
    initConnects();
    this->setMinimumSize(300,550);
    this->resize(300,550);
    setStyle(":/StyleSheet/Register/style.qss");
}

void Register::initTitleBar() {
    this->setIconButton(":/Resources/TitleBar/icon.svg");
    this->setTitleText("TeamChat");
    this->setTheme(QFramelessWindow::LIGHT);
}

void Register::initControls() {
    //欢迎标题
    label_welcome_title_ = new QLabel();
    label_welcome_title_->setObjectName("welcome-title");
    label_welcome_title_->setText("欢迎注册TeamChat");
    //欢迎词
    label_welcome_message_ = new QLabel();
    label_welcome_message_->setText("每一天，乐在沟通");
    label_welcome_message_->setObjectName("welcome-message");
    //昵称输入框
    lineedit_nickname_ = new QLineEdit();
    lineedit_nickname_->setObjectName("nickname");
    lineedit_nickname_->setPlaceholderText(" 昵称");
    lineedit_nickname_->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    lineedit_nickname_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    action_nickname_rightclear_ = new QAction(QIcon(":Resources/Commons/search_clear.svg"), tr("清除输入内容"));
    //密码输入框
    lineedit_password_ = new QLineEdit();
    lineedit_password_->setObjectName("password");
    lineedit_password_->setPlaceholderText(" 密码");
    lineedit_password_->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    lineedit_password_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    action_password_rightclear_ = new QAction(QIcon(":Resources/Commons/search_clear.svg"), tr("清除输入内容"));
    action_password_show_hide_ = new QAction(QIcon(":Resources/Commons/hide_password.svg"), tr("点击显示密码"));
    action_password_tip_ = new QAction(QIcon(":Resources/Commons/tip.svg"), tr(""));
    action_password_tip_->setText(" ৹ 不能含有空格 \n৹ 长度为8-16个字符 \n৹ 必须包含字母、数字、符号中至少两种 \n৹ 符号包括：!@#$%^&*.+-");
    lineedit_password_->addAction(action_password_tip_,  QLineEdit::LeadingPosition);
    lineedit_password_->addAction(action_password_show_hide_,  QLineEdit::TrailingPosition);
    lineedit_password_->setEchoMode(QLineEdit::Password);
    //邮箱输入框
    lineedit_email_ = new QLineEdit();
    lineedit_email_->setObjectName("email");
    lineedit_email_->setPlaceholderText(" 邮箱");
    lineedit_email_->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    lineedit_email_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    action_email_rightclear_ = new QAction(QIcon(":Resources/Commons/search_clear.svg"), tr("清除输入内容"));
    //邮箱验证码
    lineedit_email_verification_code_ = new QLineEdit();
    lineedit_email_verification_code_->setObjectName("email-verification-code");
    lineedit_email_verification_code_->setPlaceholderText(" 验证码");
    lineedit_email_verification_code_->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    lineedit_email_verification_code_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    action_email_verification_code_password_rightclear_ = new QAction(QIcon(":Resources/Commons/search_clear.svg"), tr("清除输入内容"));
    //发送验证码
    pushbutton_email_send_verification_code_ = new QPushButton();
    pushbutton_email_send_verification_code_->setObjectName("email-send-verification-code");
    pushbutton_email_send_verification_code_->setText("发送验证码");
    pushbutton_email_send_verification_code_->setEnabled(false);
    //服务协议
    label_service_agreements_ = new QLabel();
    label_service_agreements_->setObjectName(QStringLiteral("service-agreements"));
    label_service_agreements_->setOpenExternalLinks(true);
    label_service_agreements_->setText("已阅读并同意<a style='color: blue; text-decoration: none' href = https://www.baidu.com>服务协议</a>"
                                       "和<a style='color: blue; text-decoration: none' href = https://www.baidu.com>隐私保护指引</a>");
    //勾选服务协议
    checkbox_service_agreements_ = new QCheckBox();
    //注册按钮
    pushbutton_register_ = new QPushButton();
    pushbutton_register_->setText("立即注册");
    pushbutton_register_->setObjectName(QStringLiteral("register"));
    pushbutton_register_->setEnabled(false);
    //昵称输入错误提示
    label_nickname_error_tip_ = new QLabel();
    label_nickname_error_tip_->setObjectName("nickname-error-tip");
    //密码输入错误提示
    label_password_error_tip_ = new QLabel();
    label_password_error_tip_->setObjectName("password-error-tip");
    //邮箱输入错误提示
    label_email_error_tip_ = new QLabel();
    label_email_error_tip_->setObjectName("email-error-tip");
    //计时器
    timer_send_verification_code_ = new QTimer();
    timer_send_verification_code_->setInterval(1000); // 设置计时器间隔为1秒（1000毫秒）

    //布局
    QHBoxLayout *verification_code = new QHBoxLayout();
    verification_code->addStretch(1);
    verification_code->addWidget(lineedit_email_verification_code_);
    verification_code->setSpacing(9);
    verification_code->addWidget(pushbutton_email_send_verification_code_);
    verification_code->addStretch(1);

    QHBoxLayout *service_agreements = new QHBoxLayout();
    service_agreements->addStretch(1);
    service_agreements->addWidget(checkbox_service_agreements_);
    service_agreements->setSpacing(0);
    service_agreements->addWidget(label_service_agreements_);
    service_agreements->addStretch(1);

    QVBoxLayout *totalV = new QVBoxLayout();
    totalV->addStretch(10);
    totalV->addWidget(label_welcome_title_, 0, Qt::AlignHCenter);
    totalV->addSpacing(20);
    totalV->addWidget(label_welcome_message_, 0, Qt::AlignHCenter);
    totalV->addSpacing(12);
    totalV->addWidget(lineedit_nickname_, 0, Qt::AlignHCenter);
    totalV->addSpacing(1);
    totalV->addWidget(label_nickname_error_tip_, 0, Qt::AlignHCenter);
    totalV->addSpacing(1);
    totalV->addWidget(lineedit_password_, 0, Qt::AlignHCenter);
    totalV->addSpacing(1);
    totalV->addWidget(label_password_error_tip_, 0, Qt::AlignHCenter);
    totalV->addSpacing(1);
    totalV->addWidget(lineedit_email_, 0, Qt::AlignHCenter);
    totalV->addSpacing(1);
    totalV->addWidget(label_email_error_tip_, 0, Qt::AlignHCenter);
    totalV->addSpacing(1);
    totalV->addLayout(verification_code);
    totalV->addSpacing(15);
    totalV->addLayout(service_agreements);
    totalV->addSpacing(22);
    totalV->addWidget(pushbutton_register_, 0, Qt::AlignHCenter);
    totalV->addStretch(10);

    QHBoxLayout *totalH = new QHBoxLayout();
    totalH->addStretch();
    totalH->addLayout(totalV);
    totalH->addStretch();

    QWidget *temp = new QWidget();
    temp->setLayout(totalH);
    this->setCentralWidget(temp);
}

void Register::initConnects() {
    //LineEdit文本改变
    connect(lineedit_nickname_, SIGNAL(textChanged(QString)), this, SLOT(nicknameeTextChanged(QString)));
    connect(lineedit_password_, SIGNAL(textChanged(QString)), this, SLOT(passwordTextChanged(QString)));
    connect(lineedit_email_, SIGNAL(textChanged(QString)), this, SLOT(emailTextChanged(QString)));
    connect(lineedit_email_verification_code_, SIGNAL(textChanged(QString)), this, SLOT(emailVerificationCodeTextChanged(QString)));
    //LineEdit动作（清空、是否显示密码）
    connect(action_nickname_rightclear_, SIGNAL(triggered(bool)), this, SLOT(clearNicknameEditLine(bool)));
    connect(action_password_rightclear_, SIGNAL(triggered(bool)), this, SLOT(clearPasswordEditLine(bool)));
    connect(action_email_rightclear_, SIGNAL(triggered(bool)), this, SLOT(clearEmailEditLine(bool)));
    connect(action_email_verification_code_password_rightclear_, SIGNAL(triggered(bool)), this, SLOT(clearEmailVerificationCodeEditLine(bool)));
    connect(action_password_show_hide_, SIGNAL(triggered(bool)), this, SLOT(showHidePasswordEditLine(bool)));
    //复选框状态改变
    connect(checkbox_service_agreements_, SIGNAL(stateChanged(int)), this, SLOT(clickedCheckbox(int)));
    //点击按钮 注册、发送验证码
    connect(pushbutton_register_, SIGNAL(clicked()), this, SLOT(clickedRegister()));
    connect(pushbutton_email_send_verification_code_, SIGNAL(clicked()), this, SLOT(clickedEmailSendVerificationCode()));
    //计时器
    connect(timer_send_verification_code_, &QTimer::timeout, this, [=](){
        send_interval_--; // 倒计时减1
        if (send_interval_ > 0) {
            pushbutton_email_send_verification_code_->setText(QString::number(send_interval_)); // 更新按钮上的倒计时数字
        } else {
            pushbutton_email_send_verification_code_->setEnabled(true); // 启用按钮
            pushbutton_register_->setCursor(QCursor(Qt::PointingHandCursor));
            pushbutton_email_send_verification_code_->setText("发送验证码");
            timer_send_verification_code_->stop(); // 停止计时器
            send_interval_ = 30; // 重置倒计时初始值
        }
    });
}

void Register::clearNicknameEditLine(bool) {
    lineedit_nickname_->clear();
}

void Register::clearPasswordEditLine(bool) {
    lineedit_password_->clear();
}

void Register::clearEmailEditLine(bool) {
    lineedit_email_->clear();
}

void Register::clearEmailVerificationCodeEditLine(bool) {
    lineedit_email_verification_code_->clear();
}

void Register::nicknameeTextChanged(QString text) {
    if (text != "") {
        lineedit_nickname_->addAction(action_nickname_rightclear_, QLineEdit::TrailingPosition);
        if (qsu_->lineEditValidation(text, 1) == false) {
            verification_flags_[0] = false;
            label_nickname_error_tip_->setText("(o_ _)ﾉ   昵称不可以含空格");
        } else {
            verification_flags_[0] = true;
            label_nickname_error_tip_->clear();
        }
    } else {
        verification_flags_[0] = false;
        label_nickname_error_tip_->clear();
        lineedit_nickname_->removeAction(action_nickname_rightclear_);
    }
    allInputVerification();
}

void Register::passwordTextChanged(QString text) {
    if (text != "") {
        lineedit_password_->addAction(action_password_rightclear_, QLineEdit::TrailingPosition);
        if (qsu_->lineEditValidation(text, 2) == false) {
            verification_flags_[1] = false;
            label_password_error_tip_->setText("(⊙ˍ⊙)?  密码格式输入有误");
        } else {
            verification_flags_[1] = true;
            label_password_error_tip_->clear();
        }
    } else {
        verification_flags_[1] = false;
        label_password_error_tip_->clear();
        lineedit_password_->removeAction(action_password_rightclear_);
    }
    allInputVerification();
}

void Register::emailTextChanged(QString text) {
    if (text != "") {
        lineedit_email_->addAction(action_email_rightclear_, QLineEdit::TrailingPosition);
        if (qsu_->lineEditValidation(text, 3) == false) {
            verification_flags_[2] = false;
            pushbutton_email_send_verification_code_->setEnabled(false);
            label_email_error_tip_->setText("(¬_¬ )  邮箱格式输入有误");
        } else {
            verification_flags_[2] = true;
            label_email_error_tip_->clear();
            pushbutton_email_send_verification_code_->setEnabled(true);
            pushbutton_email_send_verification_code_->setCursor(QCursor(Qt::PointingHandCursor));
        }
    } else {
        verification_flags_[2] = false;
        pushbutton_email_send_verification_code_->setEnabled(false);
        label_email_error_tip_->clear();
        lineedit_email_->removeAction(action_email_rightclear_);
    }
    allInputVerification();
}

void Register::emailVerificationCodeTextChanged(QString text) {
    if (text != "") {
        lineedit_email_verification_code_->addAction(action_email_verification_code_password_rightclear_, QLineEdit::TrailingPosition);
    } else {
        lineedit_email_verification_code_->removeAction(action_email_verification_code_password_rightclear_);
    }
}

void Register::clickedRegister() {
    //拿到用户输入的数据
    lineedit_email_verification_code_->text();
    //从数据库拿数据
    //对比
}

void Register::clickedEmailSendVerificationCode() {
    //发送验证码
    //30s倒计时
    pushbutton_email_send_verification_code_->setEnabled(false); // 禁用按钮
    timer_send_verification_code_->start(); // 启动计时器
    pushbutton_email_send_verification_code_->setText(QString::number(send_interval_)); // 显示倒计时初始值

}

void Register::clickedCheckbox(int status) {
    if (status == Qt::Checked) verification_flags_[3] = true;
    else verification_flags_[3] = false;
    allInputVerification();
}

void Register::showHidePasswordEditLine(bool) {
    if(action_password_show_hide_->text() == "点击显示密码"){
        action_password_show_hide_->setText("点击隐藏密码");
        action_password_show_hide_->setIcon(QIcon(":Resources/Commons/show_password.svg"));
        lineedit_password_->setEchoMode(QLineEdit::Normal);
    } else if (action_password_show_hide_->text() == "点击隐藏密码") {
        action_password_show_hide_->setText("点击显示密码");
        action_password_show_hide_->setIcon(QIcon(":Resources/Commons/hide_password.svg"));
        lineedit_password_->setEchoMode(QLineEdit::Password);
    }
}

void Register::setStyle(QString path) {
    QFile qss(path);
    qss.open(QFile::ReadOnly);
    setStyleSheet(qss.readAll());
    qss.close();
}

void Register::closeEvent(QCloseEvent *e) {
    emit registerClosed();
    this->close();
}

void Register::allInputVerification() {
    bool res = true;
    for(int i = 0; i < 4; i++) {
        if (verification_flags_[i] == false){
            res = false;
            break;
        }
    }
    if (res == true) {
        pushbutton_register_->setEnabled(true);
        pushbutton_register_->setCursor(QCursor(Qt::PointingHandCursor));
    } else {
        pushbutton_register_->setEnabled(false);
    }
}
