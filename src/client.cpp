#include "client.h"

#include "mere/message/uri.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

Mere::RPC::Client::~Client()
{
    qDebug() << "dtor...";
    if (m_client)
    {
        m_client->done();
        delete m_client;
        m_client = nullptr;
    }

}

Mere::RPC::Client::Client(const std::string &path, QObject *parent)
    : QObject(parent),
      m_path(path)
{
    Mere::Message::Uri uri(path);

    m_server  = uri.server();
    if(m_server.length() == 0)
        throw std::invalid_argument("Invalid server name in service path!");

    // optional
    m_service = uri.service();
//    if(m_service.length() == 0)
//        throw std::invalid_argument("Invalid service name in service path!");

    m_client = new Mere::Message::Client(uri.fqbase());
    connect(m_client, SIGNAL(message(const std::string &)), this, SLOT(message(const std::string &)));

    m_client->join();
}

Mere::RPC::Client* Mere::RPC::Client::service(const std::string &service)
{
    m_service = service;
    return this;
};

Mere::RPC::Client* Mere::RPC::Client::method(const std::string &method)
{
    m_method = method;
    return this;
};

Mere::RPC::Client* Mere::RPC::Client::with(const std::vector<QVariant> args)
{
    m_args = args;

    return this;
}

void Mere::RPC::Client::call()
{
    QJsonArray args;
    for(const auto &arg : m_args)
        args.append(arg.toJsonValue());

    // create the main object
    QJsonObject jsonObj;
    jsonObj.insert("id"   , QUuid::createUuid().toString());
    jsonObj.insert("ver", 1.0);

    QJsonObject reqObj;
    reqObj.insert("serv", QJsonValue(m_service.c_str()));
    reqObj.insert("func", QJsonValue(m_method.c_str()));
    reqObj.insert("args", args);

    jsonObj.insert("req", reqObj);

    QJsonDocument jsonDocument(jsonObj);

    const QByteArray request = jsonDocument.toJson(QJsonDocument::Compact);

    m_client->send(request.toStdString());
}

void Mere::RPC::Client::message(const std::string &message)
{
    if (m_callback)
    {
        QJsonDocument document = QJsonDocument::fromJson(QByteArray(message.c_str()));
        if (document.isNull() || document.isEmpty())
            return;

        if (!document.isObject()) return;

        QJsonObject object = document.object();

        QVariant res;
        if (object.contains("res"))
            res = object.value("res").toVariant();

        QVariant err;
        if (object.contains("err"))
            err = object.value("err").toVariant();

        m_callback(res, err, m_context);
    }
}
