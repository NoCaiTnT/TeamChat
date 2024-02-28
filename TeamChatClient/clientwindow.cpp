#include "clientwindow.h"

ClientWindow::ClientWindow() {
    this->setMinimumSize(250,500);
    initTitleBar();
    initUserInfo();
}

void ClientWindow::initTitleBar() {
    this->setIconButton(":/Resources/TitleBar/icon.svg");
    this->setTitleText("TeamChat");
    this->setTheme(QFramelessWindow::Light);
    this->resize(250,500);
}

void ClientWindow::initUserInfo() {
    userinfo_ = new UserInfo();
    this->setCentralWidget(userinfo_);
}

