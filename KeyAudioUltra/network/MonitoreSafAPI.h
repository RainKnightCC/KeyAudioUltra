#ifndef MONITORESAFAPI_H
#define MONITORESAFAPI_H

#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonObject>

#include <QList>
#include <QPair>

#include "BaseAPI.h"

using namespace std;

class MonitoreSafAPI : public BaseAPI
{
public:
    MonitoreSafAPI();
    ~MonitoreSafAPI();

    void getObjectList(function<void(bool, QList<QPair<QString, QString>>)> callback);
    void postObjectList(function<void(bool, QList<QPair<QString, QString>>)> callback);

protected:
    void requestFinished(QNetworkReply *reply, const QByteArray data, const int statusCode);

private:
    function<void(bool, QList<QPair<QString, QString>>)> funCallback;
};

#endif // MONITORESAFAPI_H
