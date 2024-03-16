#ifndef WEARTHCLIENT_H
#define WEARTHCLIENT_H

#include <QObject>
#include <QObject>
#include <QString>
#include <vector>
#include <QJsonObject>
#include <QJsonArray>
using namespace std;

enum WeatherTypeClient{
    SUNNY,                                                      //晴、热
    CLOUDY,                                                     //多云、阴、平静、冷
    WINDY,                                                      //风、风暴
    FOGGY,                                                      //雾
    HAZY,                                                       //霾
    RAINY,                                                      //雨
    SNOWY,                                                      //雪、雨夹雪
    SANDSTORM,                                                  //沙尘
    UNKNOW                                                      //未知
};
WeatherTypeClient getWeatherTypeFromWeather(QString weather);         //根据天气描述获得天气状态

class LivesWeatherClient : public QObject
{
    Q_OBJECT
public:
    LivesWeatherClient();

    QString getWeather() const;                                     //获得天气描述
    QString getTemperature() const;                                 //获得温度
    QString getWinddirection() const;                               //获得风向
    QString getWindpower() const;                                   //获得风力
    QString getHumidity() const;                                    //获得湿度
    QString getReporttime() const;                                  //获得预报时间
    QString getTemperatureFloat() const;                            //获得浮点型温度
    QString getHumidityFloat() const;                               //获得浮点型适度
    WeatherTypeClient getWeatherType() const;                       //获得天气类型
    void setAll(QString weather, QString temperature, QString winddirection, QString windpower,
                QString humidity, QString reporttime, QString temperature_float, QString humidity_float);   //设置全部属性

private:
    WeatherTypeClient weather_type_;                             //天气类别
    QString weather_;                                               //天气现象
    QString temperature_;                                           //实时温度（摄氏度）
    QString winddirection_;                                         //风向描述
    QString windpower_;                                             //风力级别，单位：级
    QString humidity_;                                              //空气湿度
    QString reporttime_;                                            //数据发布的时间
    QString temperature_float_;                                     //实时温度（摄氏度）浮点型
    QString humidity_float_;                                        //空气湿度 浮点型
};

class ForecastWeatherClient : public QObject
{
    Q_OBJECT
public:
    ForecastWeatherClient();

    QString getDate() const;                                        //获得这天的日期
    QString getWeek() const;                                        //获得这天是星期几
    QString getDayweather() const;                                  //获得白天天气描述
    QString getNightweather() const;                                //获得晚上天气描述
    QString getDaytemp() const;                                     //获得白天温度
    QString getNighttemp() const;                                   //获得晚上温度
    QString getDaywind() const;                                     //获得白天风向
    QString getNightwind() const;                                   //获得晚上风向
    QString getDaypower() const;                                    //获得白天风力
    QString getNightpower() const;                                  //获得晚上风力
    WeatherTypeClient getWeatherType() const;                    //获得天气类型
    void setAll(QString date, QString week, QString dayweather, QString nightweather, QString daytemp,
                QString nighttemp, QString daywind, QString nightwind, QString daypower, QString nightpower);   //设置全部属性

private:
    WeatherTypeClient weather_type_;                             //天气类别
    QString date_;                                                  //日期
    QString week_;                                                  //星期几
    QString dayweather_;                                            //白天天气现象
    QString nightweather_;                                          //晚上天气现象
    QString daytemp_;                                               //白天温度
    QString nighttemp_;                                             //晚上温度
    QString daywind_;                                               //白天风向
    QString nightwind_;                                             //晚上风向
    QString daypower_;                                              //白天风力
    QString nightpower_;                                            //晚上风力
};

class WeatherClient : public QObject
{
    Q_OBJECT
public:
    WeatherClient();

    LivesWeatherClient* getLivesWeather();                                //返回当前天气
    vector<ForecastWeatherClient*> getForecastWeather();                  //返回预报天气
    QString getReporttime();
    void setReporttime(QString time);

    void addForecastWeatherClient(ForecastWeatherClient* forecast_weather_client);
    void clearForecastWeatherClient();

private:
    QString reporttime_;                                            //预报发布时间
    LivesWeatherClient *lives_weather_;                         //当前天气
    vector<ForecastWeatherClient*> forecast_weather_ = {new ForecastWeatherClient};                //预报天气

};

#endif // WEARTHCLIENT_H
