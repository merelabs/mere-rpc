#ifndef MERE_ROC_JSON_CLIENT_H
#define MERE_ROC_JSON_CLIENT_H

#include "mere/message/client.h"

#include <QObject>
#include <QDebug>


namespace Mere
{
namespace RPC
{
namespace Json
{

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(const QString &service, QObject *parent = nullptr);
    Client* method(const QString &method)
    {
        m_method = method;
        return this;
    };

    Client* with(const QVariant &...)
    {

        return this;
    }

    void call();

signals:
    void response(const QJsonObject &);

public slots:
    void message(const QString &message);

private:
    QString m_service;
    QString m_method;

    std::vector<QVariant> m_params;

    Mere::Message::Client *m_client;

};

}
}
}

#endif // MERE_ROC_JSON_CLIENT_H
