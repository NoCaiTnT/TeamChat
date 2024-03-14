#include "clientwindow.h"

ClientWindow::ClientWindow() {
    initTitleBar();
    initCentralWidget();
    this->setMinimumSize(300,550);
    this->resize(300,550);
}

void ClientWindow::initTitleBar() {
    this->setIconButton(":/Resources/TitleBar/icon.svg");
    this->setTitleText("TeamChat");
    this->setTheme(QFramelessWindow::LIGHT);
}

void ClientWindow::initCentralWidget() {
    QWidget *all_widgets = new QWidget();
    userinfo_ = new UserInfoClient();
    friendinfo_ = new FriendInfo();

    QVBoxLayout *mainwindow = new QVBoxLayout();
    mainwindow->addWidget(userinfo_);
    mainwindow->setSpacing(0);
    mainwindow->addWidget(friendinfo_);
    mainwindow->addStretch(10);

    mainwindow->setContentsMargins(0, 0, 0, 0);
    all_widgets->setLayout(mainwindow);

    this->setCentralWidget(all_widgets);
}


