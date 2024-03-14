#ifndef SERVERS_H
#define SERVERS_H

#include <QMainWindow>
#include <iostream>
#include <memory>
#include <string>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/strings/str_format.h"

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#include "weather.grpc.pb.h"
#include "requestweatherserver.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using weather::Weather;
using weather::UserInfo;
using weather::LivesWeather;
using weather::ForecastWeather;
using weather::LivesWeatherReplay;
using weather::ForecastWeatherReplay;

// ABSL_FLAG(uint16_t, port, 50051, "Server port for the service");

class WeatherServiceImpl final : public Weather::Service {
    Status getLivesWeather(ServerContext* context, const weather::UserInfo* request, weather::LivesWeatherReplay* reply) override;
    Status getForecastWeather(ServerContext* context, const weather::UserInfo* request, weather::ForecastWeatherReplay* reply) override;
    weather::LivesWeather* convertLivesWeatherFormat(LivesWeatherServer* lives_weather_server);
    void convertForecastWeatherFormat(ForecastWeatherServer* forecast_weather_server, weather::ForecastWeather* forecast_weather);
};

class Servers : public QMainWindow
{
    Q_OBJECT

public:
    Servers(QWidget *parent = nullptr);
    ~Servers();

public:
    void runServers();
};
#endif // SERVERS_H
