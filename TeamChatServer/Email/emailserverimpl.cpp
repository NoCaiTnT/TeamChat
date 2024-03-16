#include "emailserverimpl.h"

grpc::Status EmailServerImpl::postRegisterEmailCode(ServerContext *context, const UserRegisterEmail *request, RegisterEmailReply *reply) {
    // 随机生成验证码
    QString verificationCode = generateVerificationCode(7,2);
    // 生成文本内容
    QString content = generateEmailContent(verificationCode, QString::fromStdString(request->useremail()), 1);
    bool sendstatus = sendEmail(sender_email_, sender_password_, sender_email_address_, sender_email_port_,
                                QString::fromStdString(request->useremail()), email_title_, content);
    if (sendstatus == false) {
        reply->set_sendstate(0);
        return Status::CANCELLED;
    }
    //执行数据库操作
    reply->set_sendstate(1);
    return Status::OK;
}

grpc::Status EmailServerImpl::postRetrieveEmailCode(ServerContext *context, const UserRetrieveEmail *request, RetrieveEmailReply *reply) {
    // 随机生成验证码
    QString verificationCode = generateVerificationCode(7,2);
    // 生成文本内容
    QString content = generateEmailContent(verificationCode, QString::fromStdString(request->useremail()), 2);
    bool sendstatus = sendEmail(sender_email_, sender_password_, sender_email_address_, sender_email_port_,
                                QString::fromStdString(request->useremail()), email_title_, content);
    if (sendstatus == false) {
        reply->set_sendstate(0);
        return Status::CANCELLED;
    }
    //执行数据库操作
    reply->set_sendstate(1);
    return Status::OK;
}

bool EmailServerImpl::sendEmail(QString senderEmail, QString senderPassword, QString senderEmailAddr, int senderEmailPort,
                                QString receiverEmail, QString emailTitle, QString emailContent) {
    // 创建 SMTP 客户端
    QSslSocket socket;
    socket.connectToHostEncrypted(senderEmailAddr, senderEmailPort); // 使用 SSL 加密的端口 465 发送方相关

    if (!socket.waitForConnected()) {
        qDebug() << "Failed to connect to the SMTP server.";
        return false;
    }

    // 读取连接信息
    if (!socket.waitForReadyRead()) {
        qDebug() << "Failed to read connection information from the server.";
        return false;
    }

    // 发送 EHLO 命令
    socket.write("EHLO localhost\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Failed to send EHLO command.";
        return false;
    }

    // 发送登录命令
    socket.write("AUTH LOGIN\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Failed to send login command.";
        return false;
    }

    // 发送邮箱和密码进行登录
    socket.write(QByteArray().append(senderEmail.toUtf8().toBase64()).append("\r\n"));
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Failed to send email.";
        return false;
    }
    socket.write(QByteArray().append(senderPassword.toUtf8().toBase64()).append("\r\n"));
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Failed to send password.";
        return false;
    }

    // 发送邮件内容
    socket.write(QString("MAIL FROM:<%1>\r\n").arg(senderEmail).toUtf8());
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Failed to send MAIL FROM command.";
        return false;
    }
    socket.write(QString("RCPT TO:<%1>\r\n").arg(receiverEmail).toUtf8());
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Failed to send RCPT TO command.";
        return false;
    }
    socket.write("DATA\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Failed to send DATA command.";
        return false;
    }
    socket.write(QString("Subject: %1\r\n").arg(emailTitle).toUtf8());
    socket.write(QString("From: %1\r\n").arg(senderEmail).toUtf8());
    socket.write(QString("To: %1\r\n").arg(receiverEmail).toUtf8());
    socket.write("Content-Type: text/html; charset=UTF-8\r\n");
    socket.write("\r\n");
    socket.write(emailContent.toUtf8());
    socket.write("\r\n.\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Failed to send email body.";
        return false;
    }

    // 发送 QUIT 命令并关闭连接
    socket.write("QUIT\r\n");
    if (!socket.waitForBytesWritten()) {
        qDebug() << "Failed to send QUIT command.";
        return false;
    }
    socket.close();

    qDebug() << "Email sent successfully.";

    return true;
}

QString EmailServerImpl::generateEmailContent(QString verificationCode, QString userEmail, int type) {
    // 创建 HTML 格式的邮件内容，包含验证码
    QString userOperate = "";
    switch (type){
        case 1: {
            userOperate = " 注册 ";
            break;
        }
        case 2: {
            userOperate = " 找回密码 ";
            break;
        }
    }
    QString html = "<html lang='en'>";
    html += "<head>";
    html += "<meta charset='UTF-8'> <meta name='viewport' content='width=device-width, initial-scale=1.0'>";
    html += "<title>验证码邮件</title>";
    html += "<style>";
    html += "body { font-family: Arial, sans-serif; background-color: #f4f4f4; padding: 20px; }";
    html += ".container { max-width: 600px; margin: 0 auto; background-color: #fff; border-radius: 8px; padding: 20px; box-shadow: 0 0 10px rgba(0, 0, 0, 0.1); }";
    html += "h1 { color: #333; text-align: center; }";
    html += ".code { text-align: center; font-size: 24px; margin-bottom: 30px; color: blue}";
    html += "</style>";
    html += "</head>";
    html += "<body>";
    html += "<div class='container'>";
    html += "<h1>验证码邮件</h1>";
    html += "<p>尊敬的" + userEmail + "用户：</p>";
    html += "<p>您的" + userOperate + "验证码为：</p>";
    html += "<div class='code'>" + verificationCode + "</div>";
    html += "<p>此验证码将在5分钟内有效，请及时使用。</p>";
    html += "<p>如果您未进行此操作，请忽略此邮件。</p>";
    html += "<p>谢谢，<br>您的服务团队TeamChat</p>";
    html += "</div>";
    html += "</body>";
    html += "</html>";
    return html;
}

QString EmailServerImpl::generateVerificationCode(int length, int mode) {
    int charsetLen = 0;
    switch (mode) {
        //纯字母
        case 1: {
            charsetLen = 26;
            break;
        }
        //字母加数字
        case 2: {
            charsetLen = 36;
            break;
        }
    }
    QString verificationCode = "";
    for (int i = 0; i < length; i++){
        int index = QRandomGenerator::global()->bounded(charsetLen);
        verificationCode.append(verification_code_charset.at(index));
    }
    return verificationCode;
}
