#include "userinfo.h"

UserInfo::UserInfo() {
    setWindowFlags(Qt::FramelessWindowHint);    //隐藏标题栏（无边框）
    setAttribute(Qt::WA_TranslucentBackground); //背景透明
    setAttribute(Qt::WA_Hover);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setMaximumHeight(80);
    initUserInfo();
    setStyle(":/StyleSheet/UserInfo/style.qss");
}

void UserInfo::initUserInfo() {
    nickname_ = new QLabel(this);
    nickname_->setObjectName(QStringLiteral("nickname"));
    nickname_->setText("NoCai");

    avatar_ = new QLabel(this);
    avatar_->setObjectName(QStringLiteral("avatar"));
    setAvatar(":/Resources/UserInfo/defaultAvatar.svg");

    status_ = new QLabel(this);
    status_->setObjectName("status");
    status_->setText("在线");

    QVBoxLayout *name_status = new QVBoxLayout();
    name_status->addWidget(nickname_);
    name_status->addWidget(status_);

    name_status->setContentsMargins(0,10,0,10);

    QHBoxLayout *totalH = new QHBoxLayout();
    totalH->addWidget(avatar_);
    totalH->addLayout(name_status);
    this->setLayout(totalH);
}

void UserInfo::setStyle(QString path) {
    QFile qss(path);
    qss.open(QFile::ReadOnly);
    setStyleSheet(qss.readAll());
    qss.close();
}

void UserInfo::setAvatar(QString url) {
    QPixmap avatar = QPixmap(url);
    QPixmap pixmap(50,50);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    QPainterPath path;
    path.addEllipse(0,0,50,50);
    painter.setClipPath(path);
    painter.drawPixmap(0,0,50,50,avatar);
    avatar_->setFixedSize(50,50);
    avatar_->setScaledContents(true);
    avatar_->setPixmap(pixmap);
}
