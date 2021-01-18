#ifndef MESSAGECLIENT_H
#define MESSAGECLIENT_H

#include "mere/json-rpc/client.h"

#include <QObject>

class RPCClient : public QObject
{
    Q_OBJECT
public:
    explicit RPCClient(QObject *parent = nullptr);

signals:

public slots:
//    void pong(const int &pid);
    void response(const QJsonObject &response);
//    void message(const Mere::Message::Message &message);

private:
    Mere::RPC::Json::Client *m_client;
};

#endif // MESSAGECLIENT_H
