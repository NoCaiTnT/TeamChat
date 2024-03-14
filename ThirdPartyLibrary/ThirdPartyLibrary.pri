#add both windows and linux can use
win32{
    #GRPC
    include($$PWD/grpc/GRPC_Windows.pri)
    CONFIG(debug,debug|release){
        INCLUDEPATH += $$PWD/grpc/gRPC_install/grpc_install_debug_win/proto_gen_debug

        SOURCES += \
            $$PWD/grpc/gRPC_install/grpc_install_debug_win/proto_gen_debug/helloworld.grpc.pb.cc \
            $$PWD/grpc/gRPC_install/grpc_install_debug_win/proto_gen_debug/helloworld.pb.cc \
            $$PWD/grpc/gRPC_install/grpc_install_debug_win/proto_gen_debug/weather.grpc.pb.cc \
            $$PWD/grpc/gRPC_install/grpc_install_debug_win/proto_gen_debug/weather.pb.cc \

        HEADERS += \
            $$PWD/grpc/gRPC_install/grpc_install_debug_win/proto_gen_debug/helloworld.grpc.pb.h \
            $$PWD/grpc/gRPC_install/grpc_install_debug_win/proto_gen_debug/helloworld.pb.h \
            $$PWD/grpc/gRPC_install/grpc_install_debug_win/proto_gen_debug/weather.grpc.pb.h \
            $$PWD/grpc/gRPC_install/grpc_install_debug_win/proto_gen_debug/weather.pb.h \

    }else{
        INCLUDEPATH += $$PWD/grpc/gRPC_install/grpc_install_release_win/proto_gen_release

        SOURCES += \
            $$PWD/grpc/gRPC_install/grpc_install_release_win/proto_gen_release/helloworld.grpc.pb.cc \
            $$PWD/grpc/gRPC_install/grpc_install_release_win/proto_gen_release/helloworld.pb.cc \
            $$PWD/grpc/gRPC_install/grpc_install_release_win/proto_gen_release/weather.grpc.pb.cc \
            $$PWD/grpc/gRPC_install/grpc_install_release_win/proto_gen_release/weather.pb.cc \

        HEADERS += \
            $$PWD/grpc/gRPC_install/grpc_install_release_win/proto_gen_release/helloworld.grpc.pb.h \
            $$PWD/grpc/gRPC_install/grpc_install_release_win/proto_gen_release/helloworld.pb.h \
            $$PWD/grpc/gRPC_install/grpc_install_release_win/proto_gen_release/weather.grpc.pb.h \
            $$PWD/grpc/gRPC_install/grpc_install_release_win/proto_gen_release/weather.pb.h \
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
    CONFIG(debug,debug|release){
        INCLUDEPATH += $$PWD/grpc/gRPC_install/grpc_install_debug_linux/proto_gen_debug

        SOURCES += \
            $$PWD/grpc/gRPC_install/grpc_install_debug_linux/proto_gen_debug/helloworld.grpc.pb.cc \
            $$PWD/grpc/gRPC_install/grpc_install_debug_linux/proto_gen_debug/helloworld.pb.cc \

        HEADERS += \
            $$PWD/grpc/gRPC_install/grpc_install_debug_linux/proto_gen_debug/helloworld.grpc.pb.h \
            $$PWD/grpc/gRPC_install/grpc_install_debug_linux/proto_gen_debug/helloworld.pb.h \
    }else{
        INCLUDEPATH += $$PWD/grpc/gRPC_install/grpc_install_release_linux/proto_gen_release

        SOURCES += \
            $$PWD/grpc/gRPC_install/grpc_install_release_linux/proto_gen_release/helloworld.grpc.pb.cc \
            $$PWD/grpc/gRPC_install/grpc_install_release_linux/proto_gen_release/helloworld.pb.cc \

        HEADERS += \
            $$PWD/grpc/gRPC_install/grpc_install_release_linux/proto_gen_release/helloworld.grpc.pb.h \
            $$PWD/grpc/gRPC_install/grpc_install_release_linux/proto_gen_release/helloworld.pb.h \
    }
    #QFramelessWindow
    include(qwindowkit_linux/share/QWindowKit/qmake/QWKWidgets.pri)
}
