#include "userinfo.h"

UserInfo::UserInfo() {
    setWindowFlags(Qt::FramelessWindowHint);    //隐藏标题栏（无边框）
    setAttribute(Qt::WA_TranslucentBackground); //背景透明
    setAttribute(Qt::WA_Hover);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    // this->setMaximumHeight(80);
    initControls();
    initConnects();
    setStyle(":/StyleSheet/UserInfo/style.qss");
    user_status_ = ONLINE;
    setStatus(user_status_);
}

void UserInfo::initConnects() {
    connect(pushbutton_status_choose_, SIGNAL(clicked(bool)), this, SLOT(showStatusMenu()));
    connect(menu_status_choose_, SIGNAL(triggered(QAction*)), this, SLOT(chooseStatus(QAction*)));
    connect(this, SIGNAL(statusChanged(UserStatus)), this, SLOT(handleStatusChanged(UserStatus)));
}

void UserInfo::showStatusMenu() {
    menu_status_choose_->exec(QCursor::pos());
}

void UserInfo::chooseStatus(QAction *action) {
    if (action == action_status_choose_online_) {
        setStatus(ONLINE);
    } else if (action == action_status_choose_offline_) {
        setStatus(OFFLINE);
    } else if (action == action_status_choose_invisible_) {
        setStatus(INVISIBLE);
    }
}

void UserInfo::handleStatusChanged(UserStatus status) {
    switch (status) {
        case ONLINE:
            label_status_->setText("在线");
            setControlsTextColor(label_status_, "#4CBB17");
            break;
        case OFFLINE:
            label_status_->setText("离线");
            setControlsTextColor(label_status_, "#808080");
            break;
        case INVISIBLE:
            label_status_->setText("隐身");
            setControlsTextColor(label_status_, "#DAA520");
            break;
    }
}

void UserInfo::initControls() {
    //控件初始化
    //昵称
    label_nickname_ = new QLabel(this);
    label_nickname_->setObjectName(QStringLiteral("nickname"));
    label_nickname_->setText("NoCai");
    label_nickname_->adjustSize();
    //头像
    label_avatar_ = new QLabel(this);
    label_avatar_->setObjectName(QStringLiteral("avatar"));
    setAvatar(":/Resources/UserInfo/defaultAvatar.svg", 70);
    //用户状态
    label_status_ = new QLabel(this);
    label_status_->setObjectName(QStringLiteral("status"));
    //状态选择
    pushbutton_status_choose_ = new QPushButton(this);
    pushbutton_status_choose_->setObjectName(QStringLiteral("status-choose"));
    pushbutton_status_choose_->setText("﹀");
    //状态选择菜单
    menu_status_choose_ = new QMenu(this);
    menu_status_choose_->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    menu_status_choose_->setAttribute(Qt::WA_TranslucentBackground);
    action_status_choose_online_ = menu_status_choose_->addAction(tr("在线"));
    action_status_choose_offline_ = menu_status_choose_->addAction(tr("离线"));
    action_status_choose_invisible_ = menu_status_choose_->addAction(tr("隐身"));
    action_status_choose_online_->setIcon(QIcon(":/Resources/UserInfo/statusOnline.svg"));
    action_status_choose_offline_->setIcon(QIcon(":/Resources/UserInfo/statusOffline.svg"));
    action_status_choose_invisible_->setIcon(QIcon(":/Resources/UserInfo/statusInvisible.svg"));

    //布局
    QHBoxLayout *name_status_choose = new QHBoxLayout();
    name_status_choose->addWidget(label_nickname_);
    name_status_choose->addWidget(pushbutton_status_choose_);

    QVBoxLayout *name_status = new QVBoxLayout();
    name_status->addLayout(name_status_choose);
    name_status->addWidget(label_status_);


    QHBoxLayout *totalH = new QHBoxLayout();
    totalH->addWidget(label_avatar_);
    totalH->addLayout(name_status);
    totalH->addStretch();

    totalH->setContentsMargins(5,5,5,0);
    this->setLayout(totalH);
}

void UserInfo::setStyle(QString path) {
    QFile qss(path);
    qss.open(QFile::ReadOnly);
    setStyleSheet(qss.readAll());
    qss.close();
}

void UserInfo::setStatus(UserStatus status)
{
    user_status_ = status;
    emit statusChanged(user_status_);
}

void UserInfo::setAvatar(QString url, int size) {
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

template<typename T>
void UserInfo::setControlsTextColor(T *control, QString color) {
    QPalette palette = control->palette();
    palette.setColor(QPalette::WindowText, color);
    control->setPalette(palette);
}
