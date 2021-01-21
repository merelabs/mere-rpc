#ifndef MERE_ROC_CLIENT_H
#define MERE_ROC_CLIENT_H

#include "mere/message/client.h"

#include <QObject>
#include <QDebug>


namespace Mere
{
namespace RPC
{

typedef void (*Callback)(QVariant res, QVariant err);

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(const QString &path, QObject *parent = nullptr);

    Client* method(const QString &method);
    Client* with(const std::vector<QVariant> args);

    void call();

    void call(Callback callback)
    {
        m_callback = callback;
        call();
    };

signals:
    void response(const QJsonObject &);

public slots:
    void message(const QString &message);

private:
    QString m_path;
    QString m_server;
    QString m_service;
    QString m_method;

    std::vector<QVariant> m_args;

    Mere::Message::Client *m_client;

    Callback m_callback;
};

}
}


#endif // MERE_ROC_CLIENT_H
