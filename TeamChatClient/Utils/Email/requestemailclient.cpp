#include "requestemailclient.h"

void RequestEmailClient::sendRegisterEmailFromServer(QString email) {
    bool reply = sendRegisterVerificationCode(email);
    emit sendRegisterEmailFinished(reply);
}

void RequestEmailClient::sendRetrieveEmailFromServer(QString email) {
    bool reply = sendRetrieveVerificationCode(email);
    emit sendRetrieveEmailFinished(reply);
}

bool RequestEmailClient::sendRegisterVerificationCode(QString reveiveEmail) {
    email::UserRegisterEmail user_email;
    user_email.set_useremail(reveiveEmail.toStdString());

    email::RegisterEmailReply reply;
    grpc::ClientContext context;

    grpc::Status status = stub_->postRegisterEmailCode(&context, user_email, &reply);
    if (status.ok() == false) {
        //发送失败
        return false;
    }
    if (reply.sendstate() == 0) return false;
    return true;
}

bool RequestEmailClient::sendRetrieveVerificationCode(QString reveiveEmail) {
    email::UserRetrieveEmail user_email;
    user_email.set_useremail(reveiveEmail.toStdString());

    email::RetrieveEmailReply reply;
    grpc::ClientContext context;

    grpc::Status status = stub_->postRetrieveEmailCode(&context, user_email, &reply);
    if (status.ok() == false) {
        //发送失败
        return false;
    }
    if (reply.sendstate() == 0) return false;
    return true;
}
