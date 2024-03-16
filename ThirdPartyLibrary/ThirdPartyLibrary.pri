#add both windows and linux can use

GRPC_DEBUG_PROTO_WIN = $$PWD/grpc/gRPC_install/grpc_install_debug_win/proto_gen_debug
GRPC_RELEASE_PROTO_WIN = $$PWD/grpc/gRPC_install/grpc_install_release_win/proto_gen_release
GRPC_DEBUG_PROTO_LINUX = $$PWD/grpc/gRPC_install/grpc_install_debug_linux/proto_gen_debug
GRPC_RELEASE_PROTO_LINUX = $$PWD/grpc/gRPC_install/grpc_install_release_linux/proto_gen_release
win32{
    #GRPC
    include($$PWD/grpc/GRPC_Windows.pri)
    #proto
    CONFIG(debug,debug|release){
        INCLUDEPATH += \
            $$GRPC_DEBUG_PROTO_WIN/Weather \
            $$GRPC_DEBUG_PROTO_WIN/Email \

        SOURCES += \
            $$GRPC_DEBUG_PROTO_WIN/Weather/weather.grpc.pb.cc \
            $$GRPC_DEBUG_PROTO_WIN/Weather/weather.pb.cc \
            $$GRPC_DEBUG_PROTO_WIN/Email/email.grpc.pb.cc \
            $$GRPC_DEBUG_PROTO_WIN/Email/email.pb.cc \

        HEADERS += \
            $$GRPC_DEBUG_PROTO_WIN/Weather/weather.grpc.pb.h \
            $$GRPC_DEBUG_PROTO_WIN/Weather/weather.pb.h \
            $$GRPC_DEBUG_PROTO_WIN/Email/email.grpc.pb.h \
            $$GRPC_DEBUG_PROTO_WIN/Email/email.pb.h \

    }else{
        INCLUDEPATH += \
            $$GRPC_RELEASE_PROTO_WIN/Weather \
            $$GRPC_RELEASE_PROTO_WIN/Email \

        SOURCES += \
            $$GRPC_RELEASE_PROTO_WIN/Weather/weather.grpc.pb.cc \
            $$GRPC_RELEASE_PROTO_WIN/Weather/weather.pb.cc \
            $$GRPC_RELEASE_PROTO_WIN/Email/email.grpc.pb.cc \
            $$GRPC_RELEASE_PROTO_WIN/Email/email.pb.cc \

        HEADERS += \
            $$GRPC_RELEASE_PROTO_WIN/Weather/weather.grpc.pb.h \
            $$GRPC_RELEASE_PROTO_WIN/Weather/weather.pb.h \
            $$GRPC_RELEASE_PROTO_WIN/Email/email.grpc.pb.h \
            $$GRPC_RELEASE_PROTO_WIN/Email/email.pb.h \
    }
    #QFramelessWindow
    contains(QT_ARCH, i386) {
        message("32-bit")
    }else {
        message("64-bit")
        CONFIG(debug, debug|release) {
            include("$$PWD\qwindowkit_win\qwindowkit_debug\share\QWindowKit\qmake/QWKWidgets.pri")
        } else {
            include("$$PWD\qwindowkit_win\qwindowkit_release\share\QWindowKit\qmake/QWKWidgets.pri")
        }
    }
}
unix{
    #GRPC
    include(grpc/GRPC_Linux.pri)
    #proto
    CONFIG(debug,debug|release){
        INCLUDEPATH += \
            $$GRPC_DEBUG_PROTO_LINUX/Weather \
            $$GRPC_DEBUG_PROTO_LINUX/Email \

        SOURCES += \
            $$GRPC_DEBUG_PROTO_LINUX/Weather/weather.grpc.pb.cc \
            $$GRPC_DEBUG_PROTO_LINUX/Weather/weather.pb.cc \
            $$GRPC_DEBUG_PROTO_LINUX/Email/email.grpc.pb.cc \
            $$GRPC_DEBUG_PROTO_LINUX/Email/email.pb.cc \

        HEADERS += \
            $$GRPC_DEBUG_PROTO_LINUX/Weather/weather.grpc.pb.h \
            $$GRPC_DEBUG_PROTO_LINUX/Weather/weather.pb.h \
            $$GRPC_DEBUG_PROTO_LINUX/Email/email.grpc.pb.h \
            $$GRPC_DEBUG_PROTO_LINUX/Email/email.pb.h \
    }else{
        INCLUDEPATH += \
            $$GRPC_RELEASE_PROTO_LINUX/Weather \
            $$GRPC_RELEASE_PROTO_LINUX/Email \

        SOURCES += \
            $$GRPC_RELEASE_PROTO_LINUX/Weather/weather.grpc.pb.cc \
            $$GRPC_RELEASE_PROTO_LINUX/Weather/weather.pb.cc \
            $$GRPC_RELEASE_PROTO_LINUX/Email/email.grpc.pb.cc \
            $$GRPC_RELEASE_PROTO_LINUX/Email/email.pb.cc \

        HEADERS += \
            $$GRPC_RELEASE_PROTO_LINUX/Weather/weather.grpc.pb.h \
            $$GRPC_RELEASE_PROTO_LINUX/Weather/weather.pb.h \
            $$GRPC_RELEASE_PROTO_LINUX/Email/email.grpc.pb.h \
            $$GRPC_RELEASE_PROTO_LINUX/Email/email.pb.h \
    }
    #QFramelessWindow
    include(qwindowkit_linux/share/QWindowKit/qmake/QWKWidgets.pri)
}
