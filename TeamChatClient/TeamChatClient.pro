QT       += core gui network concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += \
    $$PWD/Widgets/QFramelessWindow \
    $$PWD/Widgets/TitleBar \
    $$PWD/Widgets/Login \
    $$PWD/Widgets/Register \
    $$PWD/Widgets/Retrieve \
    $$PWD/Widgets/ClientWindow \
    $$PWD/Widgets/UserInfo \
    $$PWD/Widgets/FriendInfo \
    $$PWD/Widgets/TopTipBox \
    $$PWD/Widgets/MaskLayer \
    $$PWD/Widgets/WeatherInfo \
    $$PWD/Utils \
    $$PWD/Utils/Weather \
    $$PWD/Utils/Email \
    $$PWD/Global \

SOURCES += \
    main.cpp \
    Global\clientglobal.cpp \
    Widgets/QFramelessWindow/qframelesswindow.cpp \
    Widgets/TitleBar/titlebarbutton.cpp \
    Widgets/TitleBar/titlebar.cpp \
    Widgets/Login/login.cpp \
    Widgets/Register/register.cpp \
    Widgets/Retrieve/retrieve.cpp \
    Widgets/ClientWindow/clientwindow.cpp \
    Widgets/FriendInfo/friendinfo.cpp \
    Widgets/TopTipBox/toptipbox.cpp \
    Widgets/MaskLayer/masklayer.cpp \
    Widgets/UserInfo/userinfoclient.cpp \
    Widgets/WeatherInfo/weatherinfo.cpp \
    Utils/qstringutils.cpp \
    Utils/Weather/requestweatherclient.cpp \
    Utils/Weather/wearthclient.cpp \
    Utils/Email/requestemailclient.cpp \


HEADERS += \
    Global\clientglobal.h \
    Widgets/QFramelessWindow/qframelesswindow.h \
    Widgets/TitleBar/titlebarbuttonprivate.h \
    Widgets/TitleBar/titlebarbutton.h \
    Widgets/TitleBar/titlebarprivate.h \
    Widgets/TitleBar/titlebar.h \
    Widgets/Login/login.h \
    Widgets/Register/register.h \
    Widgets/Retrieve/retrieve.h \
    Widgets/ClientWindow/clientwindow.h \
    Widgets/FriendInfo/friendinfo.h \
    Widgets/TopTipBox/toptipbox.h \
    Widgets/MaskLayer/masklayer.h \
    Widgets/UserInfo/userinfoclient.h \
    Widgets/WeatherInfo/weatherinfo.h \
    Utils/qstringutils.h \
    Utils/Weather/requestweatherclient.h \
    Utils/Weather/wearthclient.h \
    Utils/Email/requestemailclient.h \



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc \
    StyleSheet.qrc

include($$PWD/../ThirdPartyLibrary/ThirdPartyLibrary.pri)

RC_ICONS = $$PWD/Resources/MainWindow/icon.ico
