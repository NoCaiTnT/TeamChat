#ifndef REQUESTEMAILCLIENT_H
#define REQUESTEMAILCLIENT_H

#include <QObject>

#include <grpcpp/grpcpp.h>
#include "email.grpc.pb.h"
using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using email::Email;
using email::UserRegisterEmail;
using email::RegisterEmailReply;
using email::UserRetrieveEmail;
using email::RetrieveEmailReply;

class RequestEmailClient : public QObject
{
    Q_OBJECT

signals:
    void sendRegisterEmailFinished(bool);
    void sendRetrieveEmailFinished(bool);

public slots:
    void sendRegisterEmailFromServer(QString email);
    void sendRetrieveEmailFromServer(QString email);

public:
    explicit RequestEmailClient(std::shared_ptr<Channel> channel) : stub_(email::Email::NewStub(channel)){};

private:
    bool sendRegisterVerificationCode(QString reveiveEmail);                                                    //让服务器发注册验证码邮件
    bool sendRetrieveVerificationCode(QString reveiveEmail);                                                    //让服务器发重置验证码邮件
private:
    std::unique_ptr<email::Email::Stub> stub_;
};

#endif // REQUESTEMAILCLIENT_H
