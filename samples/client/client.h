#ifndef MESSAGECLIENT_H
#define MESSAGECLIENT_H

#include "mere/rpc/client.h"

#include <QObject>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);

private:
    Mere::RPC::Client *m_client;
};

#endif // MESSAGECLIENT_H
