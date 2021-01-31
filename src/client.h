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
    explicit Client(const std::string &path, QObject *parent = nullptr);

    Client* method(const std::string &method);
    Client* with(const std::vector<QVariant> params);

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
    std::string m_path;
    std::string m_server;
    std::string m_service;
    std::string m_method;

    std::vector<QVariant> m_params;

    Mere::Message::Client *m_client;

    Callback m_callback = nullptr;
};

}
}


#endif // MERE_ROC_CLIENT_H
