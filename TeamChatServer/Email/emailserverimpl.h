#ifndef EMAILSERVERIMPL_H
#define EMAILSERVERIMPL_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QSslSocket>
#include <QRandomGenerator>

#include "email.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using email::Email;
using email::UserRegisterEmail;
using email::RegisterEmailReply;
using email::UserRetrieveEmail;
using email::RetrieveEmailReply;

class EmailServerImpl final : public Email::Service {
    grpc::Status postRegisterEmailCode(ServerContext* context, const email::UserRegisterEmail* request, email::RegisterEmailReply* reply) override;
    grpc::Status postRetrieveEmailCode(ServerContext* context, const email::UserRetrieveEmail* request, email::RetrieveEmailReply* reply) override;

private:
    QString sender_email_ = "1154266678@qq.com";        //发送方邮箱
    QString sender_password_ = "dixpjqakhsokiieg";      //发送方密码
    QString sender_email_address_ = "smtp.qq.com";      //发送方的邮箱代理地址
    int sender_email_port_ = 465;                       //发送方的邮箱代理端口
    QString email_title_ = "TeamChat Email Message";    //邮件标题
    QString email_content_ = "";                        //邮件内容
    const QString verification_code_charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";   //验证码字符集

    bool sendEmail(QString senderEmail, QString senderPassword, QString senderEmailAddr, int senderEmailPort,
                   QString receiverEmail, QString emailTitle, QString emailContent);
    QString generateEmailContent(QString verificationCode, QString userEmail, int type);
    QString generateVerificationCode(int length, int mode);
};

#endif // EMAILSERVERIMPL_H
