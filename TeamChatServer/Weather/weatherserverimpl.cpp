#include "weatherserverimpl.h"

grpc::Status WeatherServerImpl::getLivesWeather(ServerContext *context, const UserInfo *request, LivesWeatherReplay *reply) {
    RequestWeatherServer *request_weather = new RequestWeatherServer();
    if (QString(request->userip().c_str()) == "") {
        auto ipv4orv6 = QString::fromStdString(context->peer());
        if (ipv4orv6.contains("ipv4")) {
            auto ipv4orv6Array = ipv4orv6.split(":");
            auto ipv4 = ipv4orv6Array[1];
            request_weather->setIP(ipv4);
        } else {
            //用户不给ip，上下文也没有ipv4
            return Status::CANCELLED;
        }
    }
    else request_weather->setIP(QString(request->userip().c_str()));

    request_weather->getWeather(0);
    reply->set_allocated_livesweather(convertLivesWeatherFormat(request_weather->getWeatherServer()->getLivesWeather()));
    return Status::OK;
    qDebug()<< "lives weather return!";
}

grpc::Status WeatherServerImpl::getForecastWeather(ServerContext *context, const UserInfo *request, ForecastWeatherReplay *reply) {
    RequestWeatherServer *request_weather = new RequestWeatherServer();
    if (QString(request->userip().c_str()) == "") {
        auto ipv4orv6 = QString::fromStdString(context->peer());
        if (ipv4orv6.contains("ipv4")) {
            auto ipv4orv6Array = ipv4orv6.split(":");
            auto ipv4 = ipv4orv6Array[1];
            request_weather->setIP(ipv4);
        } else {
            //用户不给ip，上下文也没有ipv4
            return Status::CANCELLED;
        }
    }
    else request_weather->setIP(QString(request->userip().c_str()));

    request_weather->getWeather(1);
    auto forecast_weather = request_weather->getWeatherServer()->getForecastWeather();
    reply->set_reporttime(request_weather->getWeatherServer()->getReporttime().toStdString());
    for(int i = 0; i < forecast_weather.size(); i++){
        auto temp = reply->add_forecastweathers();
        convertForecastWeatherFormat(forecast_weather[i], temp);
    }
    return Status::OK;
    qDebug()<< "forecast weather return!";
}

LivesWeather *WeatherServerImpl::convertLivesWeatherFormat(LivesWeatherServer *lives_weather_server) {
    LivesWeather *replay = new LivesWeather();
    replay->set_weather(lives_weather_server->getWeather().toStdString());
    replay->set_temperature(lives_weather_server->getTemperature().toStdString());
    replay->set_winddirection(lives_weather_server->getWinddirection().toStdString());
    replay->set_windpower(lives_weather_server->getWindpower().toStdString());
    replay->set_humidity(lives_weather_server->getHumidity().toStdString());
    replay->set_reporttime(lives_weather_server->getReporttime().toStdString());
    replay->set_temperaturefloat(lives_weather_server->getTemperatureFloat().toStdString());
    replay->set_humidityfloat(lives_weather_server->getHumidityFloat().toStdString());
    return replay;
}

void WeatherServerImpl::convertForecastWeatherFormat(ForecastWeatherServer* forecast_weather_server, weather::ForecastWeather* forecast_weather) {
    forecast_weather->set_date(forecast_weather_server->getDate().toStdString());
    forecast_weather->set_week(forecast_weather_server->getWeek().toStdString());
    forecast_weather->set_dayweather(forecast_weather_server->getDayweather().toStdString());
    forecast_weather->set_nightweather(forecast_weather_server->getNightweather().toStdString());
    forecast_weather->set_daytemp(forecast_weather_server->getDaytemp().toStdString());
    forecast_weather->set_nighttemp(forecast_weather_server->getNighttemp().toStdString());
    forecast_weather->set_daywind(forecast_weather_server->getDaywind().toStdString());
    forecast_weather->set_nightwind(forecast_weather_server->getNightwind().toStdString());
    forecast_weather->set_daypower(forecast_weather_server->getDaypower().toStdString());
    forecast_weather->set_nightpower(forecast_weather_server->getNightpower().toStdString());
}
