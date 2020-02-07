#include "MonitoreSafAPI.h"

#define RESTFulAPI "http://localhost:3000/posts "

MonitoreSafAPI::MonitoreSafAPI() {

}

MonitoreSafAPI::~MonitoreSafAPI() {

}

void MonitoreSafAPI::getObjectList(function<void(bool, QList<QPair<QString, QString>>)> callback) {
    this->funCallback = callback;
    get(RESTFulAPI);
//    post(RESTFulAPI);

    // useing method
//    MonitoreSafAPI mAPI = new MonitoreSafAPI();
//    mAPI.getObjectList([&](bool success, QList<QPair<QString, QString>> monitor){
//        if(success) {
//            // do something
//        }
//    });

}

void MonitoreSafAPI::postObjectList(function<void(bool, QList<QPair<QString, QString>>)> callback) {
    this->funCallback = callback;
    QMap<QString, QByteArray> *map;
    map = new QMap<QString, QByteArray>();
    upload(RESTFulAPI, *map, "98765");
}

void MonitoreSafAPI::requestFinished(QNetworkReply *reply, const QByteArray data, const int statusCode) {
    if(statusCode == 200) {
        QJsonParseError jsonError;
        QJsonArray jsonArray = QJsonDocument::fromJson(data, &jsonError).array();
        if(jsonError.error == QJsonParseError::NoError) {
            QList<QPair<QString, QString>> monitor;
            for(int i=0; i<jsonArray.size(); ++i) {
                QJsonObject jObject = jsonArray.at(i).toObject();
                monitor.append(qMakePair(jObject.value("key1").toString(), jObject.value("key2").toString()));
            }
            this->funCallback(true, monitor);
            return;
        }
    }
    QList<QPair<QString, QString>> monitor;
    this->funCallback(false, monitor);
}
