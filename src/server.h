#ifndef SERVER_H
#define SERVER_H

#include "service.h"
#include "registry.h"

#include "mere/message/server.h"

#include <QObject>
#include <QDebug>

namespace Mere
{
namespace RPC
{
namespace Json
{

class Server : public QObject
{
    Q_OBJECT
public:
    ~Server();
    explicit Server(const QString &service, QObject *parent = nullptr);

    int add(Service *service);

signals:
//    void message(const QString &message);

public slots:
    void message(const QString &message);

private:
    QString m_service;
    Mere::Message::Server *m_server;

    std::map<std::string, void *> m_methods;

    Registry *m_registry;
};

}
}
}

#endif // SERVER_H
