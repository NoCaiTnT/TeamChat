#ifndef QSTRINGUTILS_H
#define QSTRINGUTILS_H

#include <QString>
#include <QRegularExpression>

class QStringUtils
{
public:
    QStringUtils();

public:
    bool lineEditValidation(QString input, int mode);
};

#endif // QSTRINGUTILS_H
