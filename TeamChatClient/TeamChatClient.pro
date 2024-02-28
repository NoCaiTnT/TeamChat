QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += \
    $$PWD/TitleBar \
    $$PWD/QFramelessWindow

SOURCES += \
    QFramelessWindow/qframelesswindow.cpp \
    TitleBar/titlebar.cpp \
    TitleBar/titlebarbutton.cpp \
    main.cpp \
    clientwindow.cpp \
    userinfo.cpp

HEADERS += \
    QFramelessWindow/qframelesswindow.h \
    TitleBar/titlebar.h \
    TitleBar/titlebarbutton.h \
    TitleBar/titlebarbuttonprivate.h \
    TitleBar/titlebarprivate.h \
    clientwindow.h \
    userinfo.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc \
    StyleSheet.qrc

include($$PWD/../ThirdPartyLibrary/ThirdPartyLibrary.pri)
