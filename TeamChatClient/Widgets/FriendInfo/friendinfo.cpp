#include "friendinfo.h"

FriendInfo::FriendInfo(QWidget *parent) : QWidget{parent} {
    setWindowFlags(Qt::FramelessWindowHint);    //隐藏标题栏（无边框）
    setAttribute(Qt::WA_TranslucentBackground); //背景透明
    setAttribute(Qt::WA_Hover);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    initControls();
    initConnects();
    setStyle(":/StyleSheet/FriendInfo/style.qss");
}

void FriendInfo::initControls() {
    //控件初始化
    //搜索栏
    lineedit_searchbar_old_friend_ = new QLineEdit(this);
    lineedit_searchbar_old_friend_->setObjectName("searchbar");
    lineedit_searchbar_old_friend_->setPlaceholderText(" 搜索好友");
    lineedit_searchbar_old_friend_->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    lineedit_searchbar_old_friend_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    action_searchbar_old_friend_lefticon_ = new QAction(QIcon(":Resources/FriendInfo/search.svg"), "");
    lineedit_searchbar_old_friend_->addAction(action_searchbar_old_friend_lefticon_, QLineEdit::LeadingPosition);
    action_searchbar_old_friend_rightclear_ = new QAction(QIcon(":Resources/Commons/search_clear.svg"), tr("清除输入内容"));
    //添加好友菜单
    menu_add_friend_ = new QMenu(this);
    menu_add_friend_->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    menu_add_friend_->setAttribute(Qt::WA_TranslucentBackground);
    action_add_friend_create_group_ = menu_add_friend_->addAction(tr("发起群聊"));
    action_add_friend_search_new_friend_group = menu_add_friend_->addAction(tr("添加好友/群"));
    action_add_friend_create_group_->setIcon(QIcon(":/Resources/FriendInfo/creat_group.svg"));
    action_add_friend_search_new_friend_group->setIcon(QIcon(":/Resources/FriendInfo/add_friend.svg"));
    //添加好友按钮
    pushbutton_add_friend_ = new QPushButton(this);
    pushbutton_add_friend_->setObjectName("add-friend");
    pushbutton_add_friend_->setIconSize(QSize(14, 14));
    pushbutton_add_friend_->setIcon(QIcon(":Resources/FriendInfo/add.svg"));
    pushbutton_add_friend_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //好友列表
    listwidget_old_friend_list_ = new QListWidget(this);

    //布局
    QHBoxLayout *search_bars = new QHBoxLayout();
    search_bars->addWidget(lineedit_searchbar_old_friend_);
    search_bars->setSpacing(10);
    search_bars->addWidget(pushbutton_add_friend_);


    QVBoxLayout *all_friend_controls = new QVBoxLayout();
    all_friend_controls->addLayout(search_bars);
    all_friend_controls->addWidget(listwidget_old_friend_list_);
    all_friend_controls->setContentsMargins(5,5,5,0);
    this->setLayout(all_friend_controls);
}

void FriendInfo::initConnects() {
    connect(action_searchbar_old_friend_rightclear_, SIGNAL(triggered(bool)), this, SLOT(clearSearchEditLine(bool)));
    connect(lineedit_searchbar_old_friend_, SIGNAL(textChanged(QString)), this, SLOT(searchTextChanged(QString)));
    connect(lineedit_searchbar_old_friend_, SIGNAL(returnPressed()), this, SLOT(searchOldFriend()));
    connect(pushbutton_add_friend_, SIGNAL(clicked()), this, SLOT(showAddFriendMenu()));
}

void FriendInfo::setStyle(QString path)
{
    QFile qss(path);
    qss.open(QFile::ReadOnly);
    setStyleSheet(qss.readAll());
    qss.close();
}

void FriendInfo::clearSearchEditLine(bool) {
    lineedit_searchbar_old_friend_->clear();
}

void FriendInfo::searchTextChanged(QString text) {
    if (text != "") {
        lineedit_searchbar_old_friend_->addAction(action_searchbar_old_friend_rightclear_, QLineEdit::TrailingPosition);
    } else {
        lineedit_searchbar_old_friend_->removeAction(action_searchbar_old_friend_rightclear_);
    }
}

void FriendInfo::searchOldFriend() {
    listwidget_old_friend_list_->addItem("你按回车了！");
}

void FriendInfo::showAddFriendMenu() {
    menu_add_friend_->exec(QCursor::pos());
}

