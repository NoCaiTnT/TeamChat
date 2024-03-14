#include "wearthclient.h"

WeatherClient::WeatherClient()
{
    lives_weather_ = new LivesWeatherClient();
}

LivesWeatherClient* WeatherClient::getLivesWeather() {
    return lives_weather_;
}

vector<ForecastWeatherClient *> WeatherClient::getForecastWeather() {
    return forecast_weather_;
}

QString WeatherClient::getReporttime()
{
    return reporttime_;
}

void WeatherClient::setReporttime(QString time){
    reporttime_ = time;
}

void WeatherClient::addForecastWeatherClient(ForecastWeatherClient *forecast_weather_client) {
    forecast_weather_.push_back(forecast_weather_client);
}

void WeatherClient::clearForecastWeatherClient() {
    forecast_weather_.clear();
}

LivesWeatherClient::LivesWeatherClient() {}

QString LivesWeatherClient::getWeather() const { return weather_; }

QString LivesWeatherClient::getTemperature() const { return temperature_; }

QString LivesWeatherClient::getWinddirection() const { return winddirection_; }

QString LivesWeatherClient::getWindpower() const { return windpower_; }

QString LivesWeatherClient::getHumidity() const { return humidity_; }

QString LivesWeatherClient::getReporttime() const { return reporttime_; }

QString LivesWeatherClient::getTemperatureFloat() const { return temperature_float_; }

QString LivesWeatherClient::getHumidityFloat() const { return humidity_float_; }

WeatherTypeClient LivesWeatherClient::getWeatherType() const { return weather_type_; }

void LivesWeatherClient::setAll(QString weather, QString temperature, QString winddirection, QString windpower,
                          QString humidity, QString reporttime, QString temperature_float, QString humidity_float) {
    weather_ = weather;
    temperature_ = temperature;
    winddirection_ = winddirection;
    windpower_ = windpower;
    humidity_ = humidity;
    reporttime_ = reporttime;
    temperature_float_ = temperature_float;
    humidity_float_ = humidity_float;
    weather_type_ = getWeatherTypeFromWeather(weather_);
}

ForecastWeatherClient::ForecastWeatherClient() {}

QString ForecastWeatherClient::getDate() const { return date_; }

QString ForecastWeatherClient::getWeek() const { return week_; }

QString ForecastWeatherClient::getDayweather() const { return dayweather_; }

QString ForecastWeatherClient::getNightweather() const { return nightweather_; }

QString ForecastWeatherClient::getDaytemp() const { return daytemp_; }

QString ForecastWeatherClient::getNighttemp() const { return nighttemp_; }

QString ForecastWeatherClient::getDaywind() const { return daywind_; }

QString ForecastWeatherClient::getNightwind() const { return nightwind_; }

QString ForecastWeatherClient::getDaypower() const { return daypower_; }

QString ForecastWeatherClient::getNightpower() const { return nightpower_; }

void ForecastWeatherClient::setAll(QString date, QString week, QString dayweather, QString nightweather, QString daytemp,
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
    weather_type_ = getWeatherTypeFromWeather(dayweather_);
}

WeatherTypeClient getWeatherTypeFromWeather(QString weather) {
    if (weather.contains("晴") == true || weather.contains("热") == true)
        return SUNNY;
    else if (weather.contains("云") || weather.contains("阴") || weather.contains("静") || weather.contains("冷"))
        return CLOUDY;
    else if (weather.contains("风"))
        return WINDY;
    else if (weather.contains("霾"))
        return HAZY;
    else if (weather.contains("雾"))
        return FOGGY;
    else if (weather.contains("雪"))
        return SNOWY;
    else if (weather.contains("雨"))
        return RAINY;
    else if (weather.contains("尘") || weather.contains("沙"))
        return SANDSTORM;
    else
        return UNKNOW;
}
