#include "requestweatherclient.h"

void RequestWeatherClient::getLivesWeatherFromServer()
{
    if(ip_ == "") getIP();

    weather::UserInfo userinfo;
    userinfo.set_username(username_.toStdString());
    userinfo.set_userip(ip_.toStdString());

    weather::LivesWeatherReplay reply;
    grpc::ClientContext context;

    grpc::Status status = stub_->getLivesWeather(&context, userinfo, &reply);
    if (status.ok() == false) {
        return;
    }
    auto livesweather_reply = reply.livesweather();
    weather_client_->getLivesWeather()->setAll(QString::fromStdString(livesweather_reply.weather()), QString::fromStdString(livesweather_reply.temperature()),
                                               QString::fromStdString(livesweather_reply.winddirection()), QString::fromStdString(livesweather_reply.windpower()),
                                               QString::fromStdString(livesweather_reply.humidity()), QString::fromStdString(livesweather_reply.reporttime()),
                                               QString::fromStdString(livesweather_reply.temperaturefloat()), QString::fromStdString(livesweather_reply.humidityfloat()));


}

void RequestWeatherClient::getForecastWeatherFromServer() {
    if(ip_ == "") getIP();

    weather::UserInfo userinfo;
    userinfo.set_username(username_.toStdString());
    userinfo.set_userip(ip_.toStdString());

    weather::ForecastWeatherReplay reply;
    grpc::ClientContext context;

    grpc::Status status = stub_->getForecastWeather(&context, userinfo, &reply);
    if (status.ok() == false) {
        return;
    }
    weather_client_->setReporttime(QString::fromStdString(reply.reporttime()));
    weather_client_->clearForecastWeatherClient();
    for (int i = 0; i < reply.forecastweathers_size(); i++){
        auto forecast_weather_i = reply.forecastweathers(i);
        ForecastWeatherClient *forecast_weather_client_i = new ForecastWeatherClient();
        forecast_weather_client_i->setAll(QString::fromStdString(forecast_weather_i.date()), QString::fromStdString(forecast_weather_i.week()),
                                          QString::fromStdString(forecast_weather_i.dayweather()), QString::fromStdString(forecast_weather_i.nightweather()),
                                          QString::fromStdString(forecast_weather_i.daytemp()), QString::fromStdString(forecast_weather_i.nighttemp()),
                                          QString::fromStdString(forecast_weather_i.daywind()), QString::fromStdString(forecast_weather_i.nightwind()),
                                          QString::fromStdString(forecast_weather_i.daypower()), QString::fromStdString(forecast_weather_i.nightpower()));
        weather_client_->addForecastWeatherClient(forecast_weather_client_i);
    }
}

WeatherClient *RequestWeatherClient::getWeathers(){
    return weather_client_;
}

void RequestWeatherClient::getWeatherFromServer(int type) {
    //可以做一个循环，先不获取ip
    //1. 直接向服务器请求，服务器判断context里面是否有ip
    //2. 有ip，返回结果，结束
    //3. 无ip，服务器返回CANCELLED
    //4. 客户端接收CANCELLED，获取ip，循环发送，直至获得数据
    if(type == 0 || type ==2)
        getLivesWeatherFromServer();
    if(type ==1 || type ==2)
        getForecastWeatherFromServer();
    emit getWeatherFinished();
}

void RequestWeatherClient::getIP() {
    QNetworkAccessManager manager;
    QString request = "https://ddns.oray.com/checkip";
    QEventLoop loop;
    QNetworkReply* reply = manager.get(QNetworkRequest(QUrl(request)));
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    QString result = QString::fromUtf8(reply->readAll());
    auto temp = result.split(": ");
    if(temp.size() < 2) return;
    result = temp[1];
    ip_ = result;
}
