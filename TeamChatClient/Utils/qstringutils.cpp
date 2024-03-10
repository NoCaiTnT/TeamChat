#include "qstringutils.h"

QStringUtils::QStringUtils() {}

bool QStringUtils::lineEditValidation(QString input, int mode) {
    switch(mode){
        //不能含有空格
        case 1:
            return !input.contains(" ");
        //判断密码格式，8-16位且必须为数字、大小写字母或符号中至少2种，不能含有空格
        case 2: {
            QRegularExpression rx("^(?![a-zA-z]+$)(?!\\d+$)(?![!@#$%^&*.+-]+$)[a-zA-Z\\d!@#$%^&*.+-]{8,16}$");
            if (input.contains(rx)) return true;
            else return false;
        }
        //判断邮箱格式
        case 3: {
            QRegularExpression rx("^[A-Za-z0-9]+([_\\.][A-Za-z0-9]+)*@([A-Za-z0-9\\-]+\\.)+[A-Za-z]{2,6}$");
            if (input.contains(rx)) return true;
            else return false;
        }
    }
}
