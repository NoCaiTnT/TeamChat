#include "clientwindow.h"

ClientWindow::ClientWindow(QWidget *parent)
    : QFramelessWindow(parent)
{
    this->setTitleText("This is title text!");
    this->setIconButton();
    this->setTheme(QFramelessWindow::Dark);
    resize(900,700);
}

ClientWindow::~ClientWindow() {}
