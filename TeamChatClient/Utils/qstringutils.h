#ifndef QSTRINGUTILS_H
#define QSTRINGUTILS_H

#include <QString>
#include <QRegularExpression>

class QStringUtils : public QObject
{
    Q_OBJECT
public:
    QStringUtils();

public:
    bool lineEditValidation(QString input, int mode);       //判断字符串是否包含空、符合密码规则、符合邮箱规则
};

#endif // QSTRINGUTILS_H
