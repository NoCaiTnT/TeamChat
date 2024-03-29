QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += \
    $$PWD\Weather \
    $$PWD\Email \

SOURCES += \
    main.cpp \
    servers.cpp \
    Weather/weatherserverimpl.cpp \
    Weather\requestweatherserver.cpp \
    Weather\weatherserver.cpp \
    Email/emailserverimpl.cpp \

HEADERS += \
    servers.h \
    Weather/weatherserverimpl.h \
    Weather\requestweatherserver.h \
    Weather\weatherserver.h \
    Email/emailserverimpl.h \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

include($$PWD/../ThirdPartyLibrary/ThirdPartyLibrary.pri)
