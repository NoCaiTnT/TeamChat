#ifndef SERVERS_H
#define SERVERS_H

#include <QMainWindow>
// #include <iostream>
// #include <memory>
// #include <string>

// #include "absl/flags/flag.h"
// #include "absl/flags/parse.h"
// #include "absl/strings/str_format.h"

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#include "weatherserverimpl.h"
#include "emailserverimpl.h"

class Servers : public QMainWindow
{
    Q_OBJECT

public:
    Servers(QWidget *parent = nullptr);
    ~Servers();

public:
    WeatherServerImpl weather_server_;
    EmailServerImpl email_server_;
    void runServers();
};
#endif // SERVERS_H
