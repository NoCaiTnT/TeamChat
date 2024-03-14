#include "requestweatherserver.h"


RequestWeatherServer::RequestWeatherServer() {
    key_ = "0275235fedfcd08233affe9d42dcfb68";
}

WeatherServer *RequestWeatherServer::getWeatherServer() {
    return weather_;
}

void RequestWeatherServer::getRegionalInfo() {
    if (ip_ == "") return;
    QNetworkAccessManager manager;
    QString request = "https://restapi.amap.com/v3/ip?ip=" + ip_ +"&key=" + key_;
    QEventLoop loop;
    QNetworkReply* reply = manager.get(QNetworkRequest(QUrl(request)));
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    QString result = QString::fromUtf8(reply->readAll());
    QByteArray json_result = result.toUtf8();
    QJsonDocument json_doc = QJsonDocument::fromJson(json_result);
    if (json_doc.isNull()) {
        qDebug() << "[getRegionalInfo] Failed to parse JSON document.";
        return;
    }
    if (json_doc.isObject()) {
        QJsonObject parsed_object = json_doc.object();
        province_ = parsed_object["province"].toString();
        city_ = parsed_object["city"].toString();
        adcode_ = parsed_object["adcode"].toString();
    } else {
        qDebug() << "[getRegionalInfo] Parsed JSON document is not an object.";
        return;
    }
}

void RequestWeatherServer::setIP(QString ip)
{
    ip_ = ip;
}

void RequestWeatherServer::getWeather(int type) {
    if (adcode_ == "") getRegionalInfo();
    QNetworkAccessManager manager;
    QString extensions;
    switch (type) {
    case 0: {
        extensions = "base";
        break;
    }
    case 1: {
        extensions = "all";
        break;
    }

    }
    QString requset = "https://restapi.amap.com/v3/weather/weatherInfo?key=" + key_ + "&city="+ adcode_ +"&extensions=" + extensions;
    QEventLoop loop;
    QNetworkReply* reply = manager.get(QNetworkRequest(QUrl(requset)));
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    QString result = QString::fromUtf8(reply->readAll());
    QByteArray json_result = result.toUtf8();
    QJsonDocument json_docr = QJsonDocument::fromJson(json_result);
    if(json_docr.isNull()){
        qDebug() << "[getLivesWeather] Failed to parse JSON document.";
        return;
    }
    if(json_docr.isObject()){
        QJsonObject parsed_object = json_docr.object();
        switch (type) {
        case 0: {
            weather_->caluLivesWeatherFromJson(parsed_object);
            break;
        }
        case 1: {
            weather_->caluForecastWeatherFromJson(parsed_object);
            break;
        }
        }
    } else {
        qDebug() << "[getLivesWeather] Parsed JSON document is not an object.";
        return;
    }
}
