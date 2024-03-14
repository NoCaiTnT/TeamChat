#ifndef WEATHERSERVER_H
#define WEATHERSERVER_H

#include <QObject>
#include <QString>
#include <vector>
#include <QJsonObject>
#include <QJsonArray>
using namespace std;


class LivesWeatherServer : public QObject
{
    Q_OBJECT
public:
    LivesWeatherServer();

    QString getWeather() const;                                     //获得天气描述
    QString getTemperature() const;                                 //获得温度
    QString getWinddirection() const;                               //获得风向
    QString getWindpower() const;                                   //获得风力
    QString getHumidity() const;                                    //获得湿度
    QString getReporttime() const;                                  //获得预报时间
    QString getTemperatureFloat() const;                            //获得浮点型温度
    QString getHumidityFloat() const;                               //获得浮点型适度
    void setAll(QString weather, QString temperature, QString winddirection, QString windpower,
                QString humidity, QString reporttime, QString temperature_float, QString humidity_float);   //设置全部属性

private:
    QString weather_;                                               //天气现象
    QString temperature_;                                           //实时温度（摄氏度）
    QString winddirection_;                                         //风向描述
    QString windpower_;                                             //风力级别，单位：级
    QString humidity_;                                              //空气湿度
    QString reporttime_;                                            //数据发布的时间
    QString temperature_float_;                                     //实时温度（摄氏度）浮点型
    QString humidity_float_;                                        //空气湿度 浮点型
};

class ForecastWeatherServer : public QObject
{
    Q_OBJECT
public:
    ForecastWeatherServer();

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
    void setAll(QString date, QString week, QString dayweather, QString nightweather, QString daytemp,
                QString nighttemp, QString daywind, QString nightwind, QString daypower, QString nightpower);   //设置全部属性

private:
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

class WeatherServer : public QObject
{
    Q_OBJECT
public:
    WeatherServer();

    void caluLivesWeatherFromJson(QJsonObject jobj);                //根据API返回值，设置当前天气
    void caluForecastWeatherFromJson(QJsonObject jobj);             //根据API返回值，设置预报天气

    LivesWeatherServer* getLivesWeather();                                //返回当前天气
    vector<ForecastWeatherServer*> getForecastWeather();                  //返回预报天气
    QString getReporttime();

private:
    QString reporttime_;                                            //预报发布时间
    LivesWeatherServer *lives_weather_ = nullptr;                         //当前天气
    vector<ForecastWeatherServer*> forecast_weather_ = {};                //预报天气
};



#endif // WEATHERSERVER_H
