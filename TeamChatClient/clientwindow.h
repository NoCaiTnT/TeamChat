#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include "qframelesswindow.h"
class ClientWindow : public QFramelessWindow
{
    Q_OBJECT

public:
    ClientWindow(QWidget *parent = nullptr);
    ~ClientWindow();
};
#endif // CLIENTWINDOW_H
