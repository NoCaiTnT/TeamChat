#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include "qframelesswindow.h"
#include "userinfo.h"

class ClientWindow : public QFramelessWindow
{
    Q_OBJECT

public:
    ClientWindow();

private:
    UserInfo *userinfo_;

private:
    void initTitleBar();
    void initUserInfo();
};
#endif // CLIENTWINDOW_H
