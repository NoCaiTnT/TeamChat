#include "retrieve.h"

Retrieve::Retrieve(QWidget *parent) : QFramelessWindow{parent} {
    this->setAttribute(Qt::WA_DeleteOnClose);
    initTitleBar();
    initControls();
    initConnects();
    this->setMinimumSize(300,400);
    this->resize(300,450);
    setStyle(":/StyleSheet/Retrieve/style.qss");

}

void Retrieve::initTitleBar() {
    this->setIconButton(":/Resources/TitleBar/icon.svg");
    this->setTitleText("TeamChat");
    this->setTheme(QFramelessWindow::LIGHT);
}

void Retrieve::initControls() {
    //找回标题
    label_title_ = new QLabel();
    label_title_->setObjectName("title");
    label_title_->setText("找回密码");
    //提示语
    label_message_ = new QLabel();
    label_message_->setObjectName("message");
    label_message_->setText("每次遗忘都是为了更好的开始");
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
    //找回
    pushbutton_retrieve_ = new QPushButton();
    pushbutton_retrieve_->setObjectName("retrieve");
    pushbutton_retrieve_->setText("找回");
    pushbutton_retrieve_->setEnabled(false);
    //邮箱输入错误提示
    label_email_error_tip_ = new QLabel();
    label_email_error_tip_->setObjectName("email-error-tip");
    //计时器
    timer_send_verification_code_ = new QTimer();
    timer_send_verification_code_->setInterval(1000); // 设置计时器间隔为1秒（1000毫秒）
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
    //确认密码输入框
    lineedit_repassword_ = new QLineEdit();
    lineedit_repassword_->setObjectName("repassword");
    lineedit_repassword_->setPlaceholderText(" 确认密码");
    lineedit_repassword_->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    lineedit_repassword_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    action_repassword_rightclear_ = new QAction(QIcon(":Resources/Commons/search_clear.svg"), tr("清除输入内容"));
    action_repassword_show_hide_ = new QAction(QIcon(":Resources/Commons/hide_password.svg"), tr("点击显示密码"));
    lineedit_repassword_->addAction(action_repassword_show_hide_,  QLineEdit::TrailingPosition);
    //密码错误提示
    label_password_error_tip_ = new QLabel();
    label_password_error_tip_->setObjectName("password-error-tip");
    //确认密码提示错误
    label_repassword_error_tip_ = new QLabel();
    label_repassword_error_tip_->setObjectName("repassword-error-tip");
    //提交密码
    pushbutton_commit_ = new QPushButton();
    pushbutton_commit_->setObjectName("commit");
    pushbutton_commit_->setText("提交");
    pushbutton_commit_->setEnabled(false);

    //布局
    QHBoxLayout *verification_code = new QHBoxLayout();
    verification_code->addStretch(1);
    verification_code->addWidget(lineedit_email_verification_code_);
    verification_code->setSpacing(9);
    verification_code->addWidget(pushbutton_email_send_verification_code_);
    verification_code->addStretch(1);


    vboxlayout_total_ = new QVBoxLayout();
    vboxlayout_total_->addStretch(0);
    vboxlayout_total_->addWidget(label_title_, 0, Qt::AlignHCenter);
    vboxlayout_total_->addSpacing(20);
    vboxlayout_total_->addWidget(label_message_, 0, Qt::AlignHCenter);
    vboxlayout_total_->addSpacing(40);
    vboxlayout_total_->addWidget(lineedit_email_, 0, Qt::AlignHCenter);
    vboxlayout_total_->addWidget(lineedit_password_, 0, Qt::AlignHCenter);
    vboxlayout_total_->addSpacing(1);
    vboxlayout_total_->addWidget(label_email_error_tip_, 0, Qt::AlignHCenter);
    vboxlayout_total_->addWidget(label_password_error_tip_, 0, Qt::AlignHCenter);
    vboxlayout_total_->addSpacing(1);
    vboxlayout_total_->addLayout(verification_code);
    vboxlayout_total_->addWidget(lineedit_repassword_, 0, Qt::AlignHCenter);
    vboxlayout_total_->addSpacing(1);
    vboxlayout_total_->addWidget(label_repassword_error_tip_, 0, Qt::AlignHCenter);
    vboxlayout_total_->addSpacing(1);
    vboxlayout_total_->addSpacing(35);
    vboxlayout_total_->addWidget(pushbutton_retrieve_, 0, Qt::AlignHCenter);
    vboxlayout_total_->addWidget(pushbutton_commit_, 0, Qt::AlignHCenter);
    vboxlayout_total_->addStretch(0);


    QWidget *temp = new QWidget();
    temp->setLayout(vboxlayout_total_);
    this->setCentralWidget(temp);
    lineedit_password_->hide();
    lineedit_repassword_->hide();
    label_password_error_tip_->hide();
    pushbutton_commit_->hide();
}

void Retrieve::initConnects() {
    //LineEdit文本改变
    connect(lineedit_email_, SIGNAL(textChanged(QString)), this, SLOT(emailTextChanged(QString)));
    connect(lineedit_email_verification_code_, SIGNAL(textChanged(QString)), this, SLOT(emailVerificationCodeTextChanged(QString)));
    connect(lineedit_password_, SIGNAL(textChanged(QString)), this, SLOT(passwordTextChanged(QString)));
    connect(lineedit_repassword_, SIGNAL(textChanged(QString)), this, SLOT(rePasswordTextChanged(QString)));
    //LineEdit清空
    connect(action_email_rightclear_, SIGNAL(triggered(bool)), this, SLOT(clearEmailEditLine(bool)));
    connect(action_email_verification_code_password_rightclear_, SIGNAL(triggered(bool)), this, SLOT(clearEmailVerificationCodeEditLine(bool)));
    connect(action_password_rightclear_, SIGNAL(triggered(bool)), this, SLOT(clearPasswordEditLine(bool)));
    connect(action_repassword_rightclear_, SIGNAL(triggered(bool)), this, SLOT(clearRePasswordEditLine(bool)));
    //点击按钮 找回、发送验证码、提交
    connect(pushbutton_retrieve_, SIGNAL(clicked()), this, SLOT(clickedRetrieve()));
    connect(pushbutton_email_send_verification_code_, SIGNAL(clicked(bool)), this, SLOT(clickedEmailSendVerificationCode()));
    connect(pushbutton_commit_, SIGNAL(clicked(bool)), this, SLOT(clickedCommit()));
    //LinEdit显示密码
    connect(action_password_show_hide_, SIGNAL(triggered(bool)), this, SLOT(showHidePasswordEditLine(bool)));
    connect(action_repassword_show_hide_, SIGNAL(triggered(bool)), this, SLOT(showHideRePasswordEditLine(bool)));
    //计时器
    connect(timer_send_verification_code_, &QTimer::timeout, this, [=](){
        send_interval_--; // 倒计时减1
        if (send_interval_ > 0) {
            pushbutton_email_send_verification_code_->setText(QString::number(send_interval_)); // 更新按钮上的倒计时数字
        } else {
            pushbutton_email_send_verification_code_->setEnabled(true); // 启用按钮
            pushbutton_retrieve_->setCursor(QCursor(Qt::PointingHandCursor));
            pushbutton_email_send_verification_code_->setText("发送验证码");
            timer_send_verification_code_->stop(); // 停止计时器
            send_interval_ = 30; // 重置倒计时初始值
        }
    });
}

void Retrieve::clickedRetrieve() {
    if (true) {
        lineedit_password_->show();
        lineedit_email_->hide();
        lineedit_repassword_->show();
        lineedit_email_verification_code_->hide();
        pushbutton_email_send_verification_code_->hide();
        label_password_error_tip_->show();
        label_email_error_tip_->hide();
        pushbutton_commit_->show();
        pushbutton_retrieve_->hide();
    } else {
        return;
    }
}

void Retrieve::clearEmailEditLine(bool) {
    lineedit_email_->clear();
}

void Retrieve::clearEmailVerificationCodeEditLine(bool) {
    lineedit_email_verification_code_->clear();
}

void Retrieve::clearPasswordEditLine(bool) {
    lineedit_password_->clear();
}

void Retrieve::clearRePasswordEditLine(bool) {
    lineedit_repassword_->clear();
}

void Retrieve::emailTextChanged(QString text) {
    if (text != ""){
        lineedit_email_->addAction(action_email_rightclear_, QLineEdit::TrailingPosition);
        if (qsu_->lineEditValidation(text, 3) == false){
            verification_flag_emile_ = false;
            pushbutton_email_send_verification_code_->setEnabled(false);
            label_email_error_tip_->setText("(¬_¬ )  邮箱格式输入有误");
        } else {
            verification_flag_emile_ = true;
            label_email_error_tip_->clear();
            if (send_interval_ == 30) {
                pushbutton_email_send_verification_code_->setEnabled(true);
                pushbutton_email_send_verification_code_->setCursor(QCursor(Qt::PointingHandCursor));
            }
        }
    }else{
        verification_flag_emile_ = false;
        pushbutton_email_send_verification_code_->setEnabled(false);
        label_email_error_tip_->clear();
        lineedit_email_->removeAction(action_email_rightclear_);
    }
    if (verification_flag_emile_ == true) {
        pushbutton_retrieve_->setEnabled(true);
        pushbutton_retrieve_->setCursor(QCursor(Qt::PointingHandCursor));
    }
    else
        pushbutton_retrieve_->setEnabled(false);
}

void Retrieve::emailVerificationCodeTextChanged(QString text) {
    if (text != "") {
        lineedit_email_verification_code_->addAction(action_email_verification_code_password_rightclear_, QLineEdit::TrailingPosition);
    } else {
        lineedit_email_verification_code_->removeAction(action_email_verification_code_password_rightclear_);
    }
}

void Retrieve::passwordTextChanged(QString text) {
    if (text != ""){
        lineedit_password_->addAction(action_password_rightclear_, QLineEdit::TrailingPosition);
        if (qsu_->lineEditValidation(text, 2) == false) {
            verification_new_password_[0] = false;
            label_password_error_tip_->setText("(⊙ˍ⊙)?  密码格式输入有误");
        } else {
            verification_new_password_[0] = true;
            label_password_error_tip_->clear();
        }
    } else {
        verification_new_password_[0] = false;
        label_password_error_tip_->clear();
        lineedit_password_->removeAction(action_password_rightclear_);
    }
    rePasswordTextChanged(lineedit_repassword_->text());
}

void Retrieve::rePasswordTextChanged(QString text) {
    if (text != "") {
        lineedit_repassword_->addAction(action_repassword_rightclear_, QLineEdit::TrailingPosition);
        if (text != lineedit_password_->text()) {
            verification_new_password_[1] = false;
            label_repassword_error_tip_->setText("(；′⌒`)  密码输入不一致");
        } else {
            verification_new_password_[1] = true;
            label_repassword_error_tip_->clear();
        }
    } else {
        verification_new_password_[1] = false;
        label_repassword_error_tip_->clear();
        lineedit_repassword_->removeAction(action_repassword_rightclear_);
    }
    passwordVerification();

}

void Retrieve::clickedEmailSendVerificationCode() {
    //发送验证码
    ClientGlobal *client_global = ClientGlobal::getInstance();
    requset_email_client_ = new RequestEmailClient(grpc::CreateChannel(client_global->getServerAddress().toStdString(),grpc::InsecureChannelCredentials()));
    thread_retrieve_send_email_ = new QThread(this);
    requset_email_client_->moveToThread(thread_retrieve_send_email_);

    connect(this, &Retrieve::sendRetrieveEmail, requset_email_client_, &RequestEmailClient::sendRetrieveEmailFromServer);
    connect(thread_retrieve_send_email_, &QThread::finished, requset_email_client_, &QObject::deleteLater);
    connect(requset_email_client_, &RequestEmailClient::sendRetrieveEmailFinished, this, &Retrieve::handleSendRetrieveEmail);

    thread_retrieve_send_email_->start();
    emit sendRetrieveEmail(lineedit_email_->text());

    //30s倒计时
    pushbutton_email_send_verification_code_->setEnabled(false); // 禁用按钮
    timer_send_verification_code_->start(); // 启动计时器
    pushbutton_email_send_verification_code_->setText(QString::number(send_interval_)); // 显示倒计时初始值
}

void Retrieve::showHideRePasswordEditLine(bool) {
    if(action_repassword_show_hide_->text() == "点击显示密码"){
        action_repassword_show_hide_->setText("点击隐藏密码");
        action_repassword_show_hide_->setIcon(QIcon(":Resources/Commons/show_password.svg"));
        lineedit_repassword_->setEchoMode(QLineEdit::Normal);
    } else if (action_repassword_show_hide_->text() == "点击隐藏密码") {
        action_repassword_show_hide_->setText("点击显示密码");
        action_repassword_show_hide_->setIcon(QIcon(":Resources/Commons/hide_password.svg"));
        lineedit_repassword_->setEchoMode(QLineEdit::Password);
    }
}

void Retrieve::clickedCommit() {
    //向服务器修改密码

    //弹框
    close();
}

void Retrieve::handleSendRetrieveEmail(bool reply) {
    if (isclosed == true) return;
    //弹框
    if (reply == false) toptipbox_verification_code_.showErrorTopTipBox(this, "验证码发送失败，请稍后重试！");
    else if (reply == true) toptipbox_verification_code_.showInformationTopTipBox(this, "验证码发送成功，请注意查收！");
    thread_retrieve_send_email_->quit();
    thread_retrieve_send_email_->wait();
    thread_retrieve_send_email_ = nullptr;
    requset_email_client_ = nullptr;
}

void Retrieve::showHidePasswordEditLine(bool) {
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

void Retrieve::setStyle(QString path) {
    QFile qss(path);
    qss.open(QFile::ReadOnly);
    setStyleSheet(qss.readAll());
    qss.close();
}

void Retrieve::closeEvent(QCloseEvent *e) {
    if (thread_retrieve_send_email_ != nullptr) {
        thread_retrieve_send_email_->quit();
        thread_retrieve_send_email_->wait();
        thread_retrieve_send_email_ = nullptr;
        requset_email_client_ = nullptr;
    }
    isclosed = true;
    emit retrieveClosed();
    this->close();
}

void Retrieve::passwordVerification() {
    bool res = true;
    for(int i = 0; i < 2; i++) {
        if (verification_new_password_[i] == false){
            res = false;
            break;
        }
    }
    if (res == true) {
        pushbutton_commit_->setEnabled(true);
        pushbutton_commit_->setCursor(QCursor(Qt::PointingHandCursor));
    } else {
        pushbutton_commit_->setEnabled(false);
    }
}
