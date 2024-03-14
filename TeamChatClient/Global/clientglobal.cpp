#include "clientglobal.h"

ClientGlobal::ClientGlobal() { }

ClientGlobal *ClientGlobal::getInstance() {
    static ClientGlobal instance;
    return &instance;
}

QString ClientGlobal::getUserName() {
    return username_;
}

void ClientGlobal::setUserName(const QString &username) {
    username_ = username;
}

QString ClientGlobal::getServerAddress() {
    return server_ip + ":" + server_port;
}

