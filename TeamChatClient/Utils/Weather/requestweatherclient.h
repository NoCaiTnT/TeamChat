#ifndef REQUESTWEATHERCLIENT_H
#define REQUESTWEATHERCLIENT_H
#include <memory>
#include <string>

#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QEventLoop>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

#include <grpcpp/grpcpp.h>
#include "weather.grpc.pb.h"
#include "wearthclient.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using weather::Weather;
using weather::UserInfo;
using weather::LivesWeather;
using weather::ForecastWeather;
using weather::LivesWeatherReplay;
using weather::ForecastWeatherReplay;

class RequestWeatherClient : public QObject
{
    Q_OBJECT
public:
    RequestWeatherClient(std::shared_ptr<Channel> channel) : stub_(Weather::NewStub(channel)){ weather_client_ = new WeatherClient(); };
    WeatherClient* getWeathers();

signals:
    void getWeatherFinished();

public slots:
    void getWeatherFromServer(int type);

private:
    QString username_;
    QString ip_ = "";
    WeatherClient *weather_client_;

    void getIP();
    void getLivesWeatherFromServer();
    void getForecastWeatherFromServer();
private:
    std::unique_ptr<weather::Weather::Stub> stub_;
};

#endif // REQUESTWEATHERCLIENT_H
