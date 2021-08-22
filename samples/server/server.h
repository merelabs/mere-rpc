#ifndef MESSAGESERVER_H
#define MESSAGESERVER_H

#include "authservice.h"

#include "mere/rpc/server.h"
#include "mere/rpc/service.h"

#include <QObject>
#include <QDebug>


class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

signals:

public slots:
//    void request(const QJsonObject &);
//    void ping(const int &pid);
//    void message(const QString &message);
//    void message(const Mere::Message::Message &message);

private:
    AuthService *m_authService;

    Mere::RPC::Server *m_server;

};

#endif // MESSAGESERVER_H
