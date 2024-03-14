#ifndef REQUESTWEATHERSERVER_H
#define REQUESTWEATHERSERVER_H

#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QEventLoop>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

#include "weatherserver.h"

class RequestWeatherServer : public QObject
{
    Q_OBJECT
public:
    RequestWeatherServer();

    WeatherServer *getWeatherServer();              //获得调用API后的天气

public:
    void getWeather(int type);                          //获得天气，实际调用API
    void setIP(QString ip);

private:
    QString key_;                                       //高德地图key
    QString ip_ = "";                                   //ip地址
    QString adcode_ = "";                               //地区编码
    QString province_ = "";                             //省份
    QString city_ = "";                                 //城市
    WeatherServer *weather_ = new WeatherServer();      //天气，包括当前天气 今天天气 和三天预报
    void getRegionalInfo();                             //获得地区编码
};

#endif // REQUESTWEATHERSERVER_H
