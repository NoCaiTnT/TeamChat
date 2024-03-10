#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include "qframelesswindow.h"
#include "userinfo.h"
#include "friendinfo.h"

class ClientWindow : public QFramelessWindow
{
    Q_OBJECT

public:
    ClientWindow();

private:
    UserInfo *userinfo_;                //用户信息窗口
    FriendInfo *friendinfo_;            //好友信息窗口

private:
    void initTitleBar();                //初始化标题栏
    void initCentralWidget();           //初始化窗口内容

};
#endif // CLIENTWINDOW_H
