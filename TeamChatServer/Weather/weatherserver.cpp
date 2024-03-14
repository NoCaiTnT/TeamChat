#include "weatherserver.h"

WeatherServer::WeatherServer()
{

}

void WeatherServer::caluLivesWeatherFromJson(QJsonObject jobj) {
    if (lives_weather_ == nullptr) lives_weather_ = new LivesWeatherServer();
    QJsonValue lives = jobj["lives"].toArray().at(0);
    lives_weather_->setAll(lives["weather"].toString(), lives["temperature"].toString(), lives["winddirection"].toString(),
                           lives["windpower"].toString(), lives["humidity"].toString(), lives["reporttime"].toString(),
                           lives["temperature_float"].toString(), lives["humidity_float"].toString());
}

void WeatherServer::caluForecastWeatherFromJson(QJsonObject jobj) {
    if (forecast_weather_.size() != 0) forecast_weather_.clear();
    QJsonValue forecast = jobj["forecasts"].toArray().at(0);
    reporttime_ = forecast["reporttime"].toString();
    QJsonArray casts = forecast["casts"].toArray();
    for(int i = 0; i < casts.size(); i++){
        QJsonValue tempval = casts.at(i);
        ForecastWeatherServer *temp = new ForecastWeatherServer();
        temp->setAll(tempval["date"].toString(), tempval["week"].toString(), tempval["dayweather"].toString(),
                     tempval["nightweather"].toString(), tempval["daytemp"].toString(), tempval["nighttemp"].toString(),
                     tempval["daywind"].toString(), tempval["nightwind"].toString(), tempval["daypower"].toString(),
                     tempval["nightpower"].toString());
        forecast_weather_.push_back(temp);
    }
}

LivesWeatherServer* WeatherServer::getLivesWeather() {
    return lives_weather_;
}

vector<ForecastWeatherServer *> WeatherServer::getForecastWeather() {
    return forecast_weather_;
}

QString WeatherServer::getReporttime()
{
    return reporttime_;
}

LivesWeatherServer::LivesWeatherServer() {}

QString LivesWeatherServer::getWeather() const { return weather_; }

QString LivesWeatherServer::getTemperature() const { return temperature_; }

QString LivesWeatherServer::getWinddirection() const { return winddirection_; }

QString LivesWeatherServer::getWindpower() const { return windpower_; }

QString LivesWeatherServer::getHumidity() const { return humidity_; }

QString LivesWeatherServer::getReporttime() const { return reporttime_; }

QString LivesWeatherServer::getTemperatureFloat() const { return temperature_float_; }

QString LivesWeatherServer::getHumidityFloat() const { return humidity_float_; }

void LivesWeatherServer::setAll(QString weather, QString temperature, QString winddirection, QString windpower,
                          QString humidity, QString reporttime, QString temperature_float, QString humidity_float) {
    weather_ = weather;
    temperature_ = temperature;
    winddirection_ = winddirection;
    windpower_ = windpower;
    humidity_ = humidity;
    reporttime_ = reporttime;
    temperature_float_ = temperature_float;
    humidity_float_ = humidity_float;
}

ForecastWeatherServer::ForecastWeatherServer() {}

QString ForecastWeatherServer::getDate() const { return date_; }

QString ForecastWeatherServer::getWeek() const { return week_; }

QString ForecastWeatherServer::getDayweather() const { return dayweather_; }

QString ForecastWeatherServer::getNightweather() const { return nightweather_; }

QString ForecastWeatherServer::getDaytemp() const { return daytemp_; }

QString ForecastWeatherServer::getNighttemp() const { return nighttemp_; }

QString ForecastWeatherServer::getDaywind() const { return daywind_; }

QString ForecastWeatherServer::getNightwind() const { return nightwind_; }

QString ForecastWeatherServer::getDaypower() const { return daypower_; }

QString ForecastWeatherServer::getNightpower() const { return nightpower_; }

void ForecastWeatherServer::setAll(QString date, QString week, QString dayweather, QString nightweather, QString daytemp,
                             QString nighttemp, QString daywind, QString nightwind, QString daypower, QString nightpower) {
    date_ = date;
    week_ = week;
    dayweather_ = dayweather;
    nightweather_ = nightweather;
    daytemp_ = daytemp;
    nighttemp_ = nighttemp;
    daywind_ = daywind;
    nightwind_ = nightwind;
    daypower_ = daypower;
    nightpower_ = nightpower;
}
