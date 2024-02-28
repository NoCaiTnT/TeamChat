#ifndef USERINFO_H
#define USERINFO_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFile>
#include <QPainter>
#include <QPainterPath>
#include <QPixmap>

class UserInfo : public QWidget
{
public:
    UserInfo();

private:
    QLabel *avatar_;
    QLabel *nickname_;
    QLabel *status_;

private:
    void initUserInfo();
    void setStyle(QString path);

public:
    void setAvatar(QString url = ":/Resources/UserInfo/defaultAvatar.svg");
};

#endif // USERINFO_H
