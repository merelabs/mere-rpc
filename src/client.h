#ifndef MERE_ROC_CLIENT_H
#define MERE_ROC_CLIENT_H

#include "mere/message/client.h"

#include <QObject>
#include <QDebug>


namespace Mere
{
namespace RPC
{

typedef void (*Callback)(QVariant res, QVariant err, void *context);

class Client : public QObject
{
    Q_OBJECT
public:
    ~Client();
    explicit Client(const std::string &path, QObject *parent = nullptr);

    Client* service(const std::string &service);
    Client* method(const std::string &method);
    Client* with(const std::vector<QVariant> args);

    void call(Callback callback, void *context = nullptr)
    {
        m_callback = callback;
        m_context = context;
        call();
    };

private:
    void call();

signals:
    void response(const QJsonObject &);

public slots:
    void message(const std::string &message);

private:
    std::string m_path;
    std::string m_server;
    std::string m_service;
    std::string m_method;

    std::vector<QVariant> m_args;

    Mere::Message::Client *m_client;

    Callback m_callback = nullptr;
    void *m_context = nullptr;
};

}
}


#endif // MERE_ROC_CLIENT_H
