#include "BaseAPI.h"

#define OVER_TIMEOUT 10000

BaseAPI::BaseAPI() {

    mThread = new QThread(this);
    moveToThread(mThread);
    mThread->start();

    mTime = OVER_TIMEOUT;
    httpRequest.setRawHeader("Accept", API_ACCEPT);
    httpRequest.setRawHeader("User-Agent", API_USER_AGENT);
    httpRequest.setRawHeader("X-XXX-API-Key", API_KEY);
    httpRequest.setRawHeader("X-XXX-API-Secret", API_SECRET);
    httpRequest.setRawHeader("Accept-Encoding", "gzip, deflate, br, compress");
    httpRequest.setRawHeader("Content-Type", "application/json; charset=UTF-8");
    httpRequest.setRawHeader("Cache-Control", "no-cache");

    settings = new QSettings("XXX");
    QString id = settings->value(SETTING_ACCOUNT_ID, "").toString();
    QString token = settings->value(SETTING_ACCOUNT_TOKEN, "").toString();

    if(!id.isEmpty())
        httpRequest.setRawHeader("X-XXX-User-ID", id.toStdString().c_str());
    if(!token.isEmpty())
        httpRequest.setRawHeader("X-XXX-User-Token", token.toStdString().c_str());

//    this->timeInitialization(&networkAccessManager,);

    QObject::connect(&networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(serviceRequestFinished(QNetworkReply*)));

}


BaseAPI::~BaseAPI() {
    networkAccessManager.disconnect();
    mThread->quit();
    mThread->wait();
    if(settings) {
        delete settings;
        settings = nullptr;
    }
}


inline void BaseAPI::setTimeout(int time) {
    mTime = time;
}

inline void BaseAPI::timeInitialization(QNetworkAccessManager *networkAccessManager, QNetworkReply *reply , QEventLoop *loop) {

}


void BaseAPI::serviceRequestFinished(QNetworkReply *reply) {
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug() << "Status Code : " << statusCode;

    if(reply->error() == QNetworkReply::NoError) {
        requestFinished(reply, reply->readAll(), statusCode);
    }else{
        requestFinished(reply, "", statusCode);
    }
    reply->deleteLater();
}


void BaseAPI::get(const QString url) {

    // Setting url
    httpRequest.setUrl(QUrl(url));
    // Setting header (constructure already setup)

    // Setting nework communication and timeout even loop
    QTimer timer;
    QEventLoop loop;
    timer.setSingleShot(true);
    QObject::connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
    timer.start((mTime > 0) ? mTime : OVER_TIMEOUT);

    QNetworkReply *reply = networkAccessManager.get(httpRequest);
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    QObject::connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), &loop, SLOT(quit()));

    loop.exec();

    if(!timer.isActive()) {
        qDebug() << "RESTFul get url : " << url << "over time, timeout = " << mTime;
        reply->deleteLater();
//        continue;
    }else{
        timer.stop();
        QNetworkReply::NetworkError netError = reply->error();

        if(netError != QNetworkReply::NoError) {
            qDebug() << "Failed : " << reply->errorString();
        }else{
            qDebug() << "response : " << QJsonDocument::fromJson(reply->readAll(), nullptr);
        }
    }

}

// for general post with json payload
void BaseAPI::post(const QString url, const QByteArray &jsonData) {
    httpRequest.setUrl(QUrl(url));

    QEventLoop loop;
    QTimer timer;
    timer.setSingleShot(true);
    QObject::connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
    timer.start((mTime > 0) ? mTime : OVER_TIMEOUT);
    QNetworkReply *reply = networkAccessManager.post(httpRequest, jsonData);
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    QObject::connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), &loop, SLOT(quit()));
    loop.exec();

    if(!timer.isActive()) {
        qDebug() << "RESTFul post url : " << url << "over time, timeout = " << mTime;
        reply->deleteLater();
//        continue;
    }else{
        timer.stop();
        QNetworkReply::NetworkError netError = reply->error();
        if(netError != QNetworkReply::NoError) {
            qDebug() << "Failed : " << reply->errorString();
        }else{
            qDebug() << "response : " << QJsonDocument::fromJson(reply->readAll());
        }
        reply->deleteLater();
    }
}


// for multipart upload to remote site
void BaseAPI::upload(const QString url, const QMap<QString, QByteArray> &data, const QString boundary) {
    httpRequest.setUrl(QUrl(url));
    QHttpMultiPart multiPart(QHttpMultiPart::FormDataType);
    // add output file name
    QHttpPart textPart;
    for(auto it=data.begin();it!=data.end();it++) {
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(QString("form-data; name=\"%1\"").arg("output")));
        textPart.setBody(it.value());
        multiPart.append(textPart);
    }
    // add boundary
    httpRequest.setHeader(QNetworkRequest::ContentTypeHeader, "multipart/form-data;boundary=" + multiPart.boundary());

    // network communication
    QEventLoop loop;
    QTimer timer;
    timer.setSingleShot(true);
    QObject::connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
    timer.start((mTime > 0) ? mTime : OVER_TIMEOUT);

    QNetworkReply *reply = networkAccessManager.post(httpRequest, &multiPart);
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    QObject::connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), &loop, SLOT(quit()));
    loop.exec();

    if(!timer.isActive()) {
        qDebug() << "RESTFul post url : " << url << "over time, timeout = " << mTime;
        reply->deleteLater();
//        continue;
    }else{
        timer.stop();
        QNetworkReply::NetworkError netError = reply->error();
        if(netError != QNetworkReply::NoError) {
            qDebug() << "Failed : " << reply->errorString();
        }
        else {
            qDebug() << "response : " << QJsonDocument::fromJson(reply->readAll(), nullptr);
        }
        reply->deleteLater();
    }
}


void BaseAPI::login(const QString url, const QMap<QString, QByteArray> &formData) {
    QByteArray params;
    for(auto it=formData.begin();it!=formData.end();++it) {
        params.append(it.key().toUtf8());
        params.append("=");
        params.append(it.value());
        params.append("&");
    }
    params.remove(params.length() -1, 1);

    httpRequest.setUrl(QUrl(url));

    QEventLoop loop;
    QTimer timer;
    timer.setSingleShot(true);
    QObject::connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
    timer.start((mTime > 0) ? mTime : OVER_TIMEOUT);

    QNetworkReply *reply = networkAccessManager.post(httpRequest, params);
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    QObject::connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), &loop, SLOT(quit()));

    loop.exec();

    if(!timer.isActive()) {
        qDebug() << "RESTFul post url : " << url << "over time, timeout = "<< mTime;
        reply->deleteLater();
//        continue;
    }else{
        timer.stop();
        QNetworkReply::NetworkError netError = reply->error();
        if(netError != QNetworkReply::NoError) {
            qDebug() << "response : " << QString::fromUtf8(reply->readAll());
        }else{

        }
        reply->deleteLater();
    }

}


void BaseAPI::put(const QString url) {
    httpRequest.setUrl(QUrl(url));
}


void BaseAPI::patch(const QString url) {
    httpRequest.setUrl(QUrl(url));
}

void BaseAPI::head(const QString url) {
    httpRequest.setUrl(QUrl(url));
}






















