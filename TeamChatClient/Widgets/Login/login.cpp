#include "login.h"

Login::Login() : QFramelessWindow() {
    this->setIconButton(":/Resources/TitleBar/icon.svg");
    this->setTitleText("TeamChat");
    this->setTheme(QFramelessWindow::LIGHT);
    // this->setMinimumSize(250,400);
    this->resize(300,500);
    initControls();
    initConnects();
    setStyle(":/StyleSheet/Login/style.qss");
}

void Login::initControls() {
    //头像
    label_avatar_ = new QLabel();
    label_avatar_->setObjectName(QStringLiteral("avatar"));
    setAvatar(":/Resources/UserInfo/defaultAvatar.svg", 100);
    label_avatar_->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    //登录按钮
    pushbutton_login_ = new QPushButton();
    pushbutton_login_->setText("登录");
    pushbutton_login_->setObjectName(QStringLiteral("login"));
    pushbutton_login_->setEnabled(false);
    //账号
    lineedit_username_ = new QLineEdit();
    lineedit_username_->setObjectName("username");
    lineedit_username_->setPlaceholderText(" 请输入TeamChat账号");
    lineedit_username_->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    lineedit_username_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    action_username_rightclear_ = new QAction(QIcon(":Resources/Commons/search_clear.svg"), tr("清除输入内容"));
    //密码
    lineedit_password_ = new QLineEdit();
    lineedit_password_->setObjectName("password");
    lineedit_password_->setPlaceholderText(" 请输入TeamChat密码");
    lineedit_password_->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    lineedit_password_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    lineedit_password_->setEchoMode(QLineEdit::Password);
    action_password_rightclear_ = new QAction(QIcon(":Resources/Commons/search_clear.svg"), tr("清除输入内容"));
    action_password_show_hide_ = new QAction(QIcon(":Resources/Commons/hide_password.svg"), tr("点击显示密码"));
    lineedit_password_->addAction(action_password_show_hide_,  QLineEdit::TrailingPosition);
    //服务协议
    label_service_agreements_ = new QLabel();
    label_service_agreements_->setObjectName(QStringLiteral("service-agreements"));
    label_service_agreements_->setOpenExternalLinks(true);
    label_service_agreements_->setText("已阅读并同意<a style='color: blue; text-decoration: none' href = https://www.baidu.com>服务协议</a>"
                                       "和<a style='color: blue; text-decoration: none' href = https://www.baidu.com>隐私保护指引</a>");
    //勾选服务协议
    checkbox_service_agreements_ = new QCheckBox();
    //注册
    label_register_ = new QLabel();
    label_register_->setObjectName("register");
    label_register_->setText("注册账号");
    label_register_->setCursor(QCursor(Qt::PointingHandCursor));
    label_register_->installEventFilter(this);
    //找回密码
    label_retrieve_ = new QLabel();
    label_retrieve_->setObjectName("retrieve");
    label_retrieve_->setText("找回密码");
    label_retrieve_->setCursor(QCursor(Qt::PointingHandCursor));
    label_retrieve_->installEventFilter(this);

    //布局
    QHBoxLayout *service_agreements = new QHBoxLayout();
    service_agreements->addStretch(4);
    service_agreements->addWidget(checkbox_service_agreements_);
    service_agreements->setSpacing(0);
    service_agreements->addWidget(label_service_agreements_);
    service_agreements->addStretch(4);

    QHBoxLayout *register_retrieve = new QHBoxLayout();
    register_retrieve->addStretch(4);
    register_retrieve->addWidget(label_register_, 0, Qt::AlignHCenter);
    register_retrieve->addStretch(1);
    register_retrieve->addWidget(label_retrieve_, 0, Qt::AlignHCenter);
    register_retrieve->addStretch(4);

    QVBoxLayout *totalV = new QVBoxLayout();
    totalV->addStretch(10);
    totalV->addWidget(label_avatar_, 0, Qt::AlignHCenter);
    totalV->addSpacing(20);
    totalV->addWidget(lineedit_username_, 0, Qt::AlignHCenter);
    totalV->addSpacing(12);
    totalV->addWidget(lineedit_password_, 0, Qt::AlignHCenter);
    totalV->addSpacing(15);
    totalV->addLayout(service_agreements);
    totalV->addSpacing(22);
    totalV->addWidget(pushbutton_login_, 0, Qt::AlignHCenter);
    totalV->addSpacing(40);
    totalV->addLayout(register_retrieve);
    totalV->addStretch(10);

    QHBoxLayout *totalH = new QHBoxLayout();
    totalH->addStretch();
    totalH->addLayout(totalV);
    totalH->addStretch();

    QWidget *temp = new QWidget();
    temp->setLayout(totalH);
    this->setCentralWidget(temp);
}

void Login::initConnects() {
    connect(lineedit_username_, SIGNAL(textChanged(QString)), this, SLOT(usernameTextChanged(QString)));
    connect(lineedit_password_, SIGNAL(textChanged(QString)), this, SLOT(passwordTextChanged(QString)));
    connect(action_username_rightclear_, SIGNAL(triggered(bool)), this, SLOT(clearUsernameEditLine(bool)));
    connect(action_password_rightclear_, SIGNAL(triggered(bool)), this, SLOT(clearPasswordEditLine(bool)));
    connect(checkbox_service_agreements_, SIGNAL(stateChanged(int)), this, SLOT(clickedCheckbox(int)));
    connect(pushbutton_login_, SIGNAL(clicked()), this, SLOT(clickedLogin()));
    connect(action_password_show_hide_, SIGNAL(triggered(bool)), this, SLOT(showHidePasswordEditLine(bool)));
}

void Login::setStyle(QString path) {
    QFile qss(path);
    qss.open(QFile::ReadOnly);
    setStyleSheet(qss.readAll());
    qss.close();
}

void Login::setAvatar(QString url, int size) {
    QPixmap avatar = QPixmap(url);
    QPixmap pixmap(size,size);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    QPainterPath path;
    path.addEllipse(0,0,size,size);
    painter.setClipPath(path);
    painter.drawPixmap(0,0,size,size,avatar);
    label_avatar_->setFixedSize(size,size);
    label_avatar_->setScaledContents(true);
    label_avatar_->setPixmap(pixmap);
}

bool Login::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::MouseButtonPress){
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if(mouseEvent->button() == Qt::LeftButton){
            if(obj == label_register_){
                clickedRegister();
                return true;
            }else if (obj == label_retrieve_) {
                clickedRetrieve();
                return true;
            }
        }else{
            return false;
        }
    }else{
        return QObject::eventFilter(obj, event);
    }
}

void Login::clearUsernameEditLine(bool) {
    lineedit_username_->clear();
}

void Login::usernameTextChanged(QString text) {
    if (text != "") {
        lineedit_username_->addAction(action_username_rightclear_, QLineEdit::TrailingPosition);
    } else {
        lineedit_username_->removeAction(action_username_rightclear_);
    }
}

void Login::clearPasswordEditLine(bool) {
    lineedit_password_->clear();
}

void Login::passwordTextChanged(QString text) {
    if (text != "") {
        lineedit_password_->addAction(action_password_rightclear_, QLineEdit::TrailingPosition);
    } else {
        lineedit_password_->removeAction(action_password_rightclear_);
    }
}

void Login::clickedLogin() {
    if (lineedit_username_->text() == "") {
        qDebug()<< "账号不可以为空";
    }
    if (lineedit_password_->text() == "") {
        qDebug()<< "密码不可以为空";
    }

    this->close();
    ClientWindow *w = new ClientWindow();
    w->show();
}

void Login::clickedCheckbox(int status) {
    if (status == Qt::Unchecked){
        pushbutton_login_->setEnabled(false);
    } else if (status == Qt::Checked){
        pushbutton_login_->setEnabled(true);
        pushbutton_login_->setCursor(QCursor(Qt::PointingHandCursor));
    }
}

void Login::clickedRegister() {
    if (!register_) {
        register_ = new Register;
        connect(register_, &Register::registerClosed, this, &Login::onRegisterClose);
    }
    register_->show();
    hide();
}

void Login::clickedRetrieve() {
    if (!retrieve_) {
        retrieve_ = new Retrieve;
        connect(retrieve_, &Retrieve::retrieveClosed, this, &Login::onRetrieveClose);
    }
    retrieve_->show();
    hide();
}

void Login::onRegisterClose() {
    register_ = nullptr;
    show();
}

void Login::onRetrieveClose() {
    retrieve_ = nullptr;
    show();
}

void Login::showHidePasswordEditLine(bool) {
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
