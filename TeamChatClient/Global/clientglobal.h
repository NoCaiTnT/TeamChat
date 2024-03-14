#ifndef CLIENTGLOBAL_H
#define CLIENTGLOBAL_H

#include <QObject>

class ClientGlobal : public QObject
{
    Q_OBJECT
public:
    static ClientGlobal* getInstance();

    QString getUserName();
    void setUserName(const QString& username);

    QString getServerAddress();

private:
    ClientGlobal(); // Private constructor to prevent instantiation
    ClientGlobal(const ClientGlobal&) = delete; // Delete copy constructor
    ClientGlobal& operator=(const ClientGlobal&) = delete; // Delete assignment operator

    QString username_;
    QString server_ip = "127.0.0.1";
    QString server_port = "5000";
};

#endif // CLIENTGLOBAL_H
