#include "client.h"

#include <QJsonObject>
#include <QJsonDocument>

Mere::RPC::Json::Client::Client(const QString &service, QObject *parent)
    : QObject(parent),
      m_service(service)
{
    QString server("/" + service);
    m_client = new Mere::Message::Client(server.toStdString().c_str());

    connect(m_client, SIGNAL(message(const QString &)), this, SLOT(message(const QString &)));

    m_client->join();
}


void Mere::RPC::Json::Client::call()
{
    qDebug() << "YES GOT A CALL";

    QJsonObject params;
    params.insert("parameter1", 1);
    params.insert ("parameter2", 2);

    // create the main object
    QJsonObject jsonObj;
//    jsonObj.insert("uuid", QUuid::createUuid().toString());
    jsonObj.insert("service", m_service);
    jsonObj.insert("method", m_method);
    jsonObj.insert("params", params);

    qDebug() << jsonObj.toVariantMap();

    QJsonDocument jsonDocument(jsonObj);
    QString request(jsonDocument.toJson(QJsonDocument::Compact));

    m_client->send(request);
}

void Mere::RPC::Json::Client::message(const QString &message)
{
    qDebug() << " KI BLE??";
}
