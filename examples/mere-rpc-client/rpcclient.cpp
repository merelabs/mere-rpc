#include "rpcclient.h"


RPCClient::RPCClient(QObject *parent) : QObject(parent)
{
    m_client = new Mere::RPC::Json::Client("service");
//    connect(m_client, SIGNAL(message(const Mere::Message::Message &)), this, SLOT(message(const Mere::Message::Message &)));
//    connect(m_client, SIGNAL(message(const QString &)), this, SLOT(message(const QString &)));
//    connect(m_client, SIGNAL(pong(const int &)), this, SLOT(pong(const int &)));

    connect(m_client, SIGNAL(response(const QJsonObject &)), this, SLOT(response(const QJsonObject &)));

    m_client->method("authenticate")->with("iklash", "iklash22")->call();
}

//void RPCClient::pong(const int &pid)
//{
//    qDebug() << "PONG";
//}

void RPCClient::response(const QJsonObject &response)
{
    qDebug() << "MESSAGE BODY ONLY";
}

//void RPCClient::message(const Mere::Message::Message &message)
//{
//    qDebug() << "MESSAGE HEADER AND BODY";
//}
