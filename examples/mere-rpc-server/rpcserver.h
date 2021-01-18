#ifndef MESSAGESERVER_H
#define MESSAGESERVER_H

#include "mere/json-rpc/server.h"

#include <QObject>
#include <QDebug>


class RPCServer : public QObject
{
    Q_OBJECT
public:
    explicit RPCServer(QObject *parent = nullptr);

signals:

public slots:
    void request(const QJsonObject &);
//    void ping(const int &pid);
//    void message(const QString &message);
//    void message(const Mere::Message::Message &message);

private:
//    Mere::Message::Server *m_server;
    Mere::RPC::Json::Server *m_server;

};

#endif // MESSAGESERVER_H
