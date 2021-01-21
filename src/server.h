#ifndef MERE_RPC_SERVER_H
#define MERE_RPC_SERVER_H

#include "registry.h"

#include "mere/message/server.h"

#include <QObject>
#include <QDebug>

namespace Mere
{
namespace RPC
{

class Server : public QObject
{
    Q_OBJECT
public:
    ~Server();
    explicit Server(const QString &server, QObject *parent = nullptr);
    int start() const;

    int add(const QString name, QObject *service);
    QObject* get(const QString &name);

signals:
//    void message(const QString &message);

public slots:
    void message(const QString &message);

private:
    QString m_path;
    Mere::Message::Server *m_server;
    Registry *m_registry;
};

}
}


#endif // MERE_RPC_SERVER_H
