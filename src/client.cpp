#include "client.h"

#include "mere/message/uri.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

Mere::RPC::Client::Client(const std::string &path, QObject *parent)
    : QObject(parent),
      m_path(path)
{
    Mere::Message::Uri uri(path);

    m_server  = uri.server();
    if(m_server.length() == 0)
        throw std::invalid_argument("Invalid server name in service path!");

    m_service = uri.service();
    if(m_service.length() == 0)
        throw std::invalid_argument("Invalid service name in service path!");

    m_client = new Mere::Message::Client(uri.fqbase());
    connect(m_client, SIGNAL(message(const QString &)), this, SLOT(message(const QString &)));

    m_client->join();
}

Mere::RPC::Client* Mere::RPC::Client::method(const std::string &method)
{
    m_method = method;
    return this;
};

Mere::RPC::Client* Mere::RPC::Client::with(const std::vector<QVariant> params)
{
    m_params = params;

    return this;
}

void Mere::RPC::Client::call()
{
    QJsonArray params;
    for(const auto &arg : m_params)
        params.append(arg.toJsonValue());

    // create the main object
    QJsonObject jsonObj;
    jsonObj.insert("version", 1.0);
    jsonObj.insert("uuid", QUuid::createUuid().toString());
    jsonObj.insert("service", QJsonValue(m_service.c_str()));
    jsonObj.insert("method", QJsonValue(m_method.c_str()));
    jsonObj.insert("params", params);

    QJsonDocument jsonDocument(jsonObj);
    QString request(jsonDocument.toJson(QJsonDocument::Compact));

    m_client->send(request);
}

void Mere::RPC::Client::message(const QString &message)
{
    if (m_callback)
        m_callback(QVariant(message), QVariant());
}
