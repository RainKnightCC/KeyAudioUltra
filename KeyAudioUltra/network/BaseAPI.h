#ifndef BASEAPI_H
#define BASEAPI_H

#include <QObject>
#include <QDebug>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QSettings>
#include <QUrl>
#include <QMap>
#include <QThread>
#include <QTimer>
#include <QEventLoop>

#include <QHttpPart>
#include <QHttpMultiPart>
#include <QJsonDocument>

#include "globaldefine.h"

class BaseAPI : public QObject
{
    Q_OBJECT
public:
    BaseAPI();
    ~BaseAPI();

    void get(const QString url);
    void post(const QString url, const QByteArray &jsonData);
    void upload(const QString url, const QMap<QString, QByteArray> &data, const QString boundary);
    void login(const QString url, const QMap<QString, QByteArray> &formData);

    void put(const QString url);
    void patch(const QString url);
    void head(const QString url);

    inline void setTimeout(int time);
    inline void timeInitialization(QNetworkAccessManager *networkAccessManager,
                                   QNetworkReply *reply ,
                                   QEventLoop *loop);


signals:

public slots:
    void serviceRequestFinished(QNetworkReply *reply);

private:
    QNetworkRequest httpRequest;
    QNetworkAccessManager networkAccessManager;
    QSettings *settings;

    QThread *mThread;
    int mTime;


protected:
    virtual void requestFinished(QNetworkReply *reply, const QByteArray data, const int statusCode) = 0;

};

#endif // BASEAPI_H
