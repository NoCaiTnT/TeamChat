#ifndef FRIENDINFO_H
#define FRIENDINFO_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QFile>
#include <QListWidget>
#include <QMenu>
#include <QtConcurrent>

class FriendInfo : public QWidget
{
    Q_OBJECT
public:
    explicit FriendInfo(QWidget *parent = nullptr);

signals:
    void signalMainBeforeTask();

private slots:
    void clearSearchEditLine(bool);                                 //清除搜索框内容
    void searchTextChanged(QString text);                           //当搜索栏文本改变
    void searchOldFriend();                                         //搜索老朋友
    void showAddFriendMenu();                                       //显示添加好友选择菜单

private:
    //控件
    QLineEdit *lineedit_searchbar_old_friend_;                      //搜索框
    QPushButton *pushbutton_add_friend_;                            //添加好友按钮
    QListWidget *listwidget_old_friend_list_;                       //好友列表
    QMenu *menu_add_friend_;                                        //添加好友选择菜单

    //动作
    QAction *action_searchbar_old_friend_lefticon_;                 //左边图标
    QAction *action_searchbar_old_friend_rightclear_;               //右边清除
    QAction *action_add_friend_create_group_;                       //建立群聊
    QAction *action_add_friend_search_new_friend_group;             //搜索新好友/群组

    void initControls();                                            //初始化控件
    void initConnects();                                            //初始化信号与槽的连接
    void setStyle(QString path);                                    //设置样式

};

#endif // FRIENDINFO_H
