#ifndef WEATHERSERVERIMPL_H
#define WEATHERSERVERIMPL_H

#include <QObject>
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

class WeatherServerImpl final : public Weather::Service {
    grpc::Status getLivesWeather(ServerContext* context, const weather::UserInfo* request, weather::LivesWeatherReplay* reply) override;
    grpc::Status getForecastWeather(ServerContext* context, const weather::UserInfo* request, weather::ForecastWeatherReplay* reply) override;
private:
    weather::LivesWeather* convertLivesWeatherFormat(LivesWeatherServer* lives_weather_server);
    void convertForecastWeatherFormat(ForecastWeatherServer* forecast_weather_server, weather::ForecastWeather* forecast_weather);
};

#endif // WEATHERSERVERIMPL_H
