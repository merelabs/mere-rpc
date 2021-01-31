#include "server.h"
#include "method.h"
#include "param.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

Mere::RPC::Server::~Server()
{
    m_server->stop();
}

Mere::RPC::Server::Server(const std::string &path, QObject *parent)
    : QObject(parent),
      m_path(path),
      m_registry(new Mere::RPC::Registry())
{
    m_server = new Mere::Message::Server(m_path);
    connect(m_server, SIGNAL(message(const QString &)), this, SLOT(message(const QString &)));

}

int Mere::RPC::Server::start() const
{
    int err = m_server->start();
    if (!err)
    {
        //connect(m_server, SIGNAL(message(const QString &)), this, SLOT(message(const QString &)));
    }

    return err;
}

QObject* Mere::RPC::Server::get(const QString &name)
{
    return m_registry->get(name);
}

int Mere::RPC::Server::add(const QString name, QObject *service)
{
    return m_registry->add(name, service);
}

void Mere::RPC::Server::message(const QString &message)
{
    QJsonDocument document = QJsonDocument::fromJson(message.toUtf8());
    if (document.isNull() || document.isEmpty())
        return;

    if (!document.isObject()) return;

    QJsonObject object = document.object();

    if(!object.contains("service"))
        return;

    QString serviceName = object.value("service").toString();

    if(!object.contains("method"))
        return;

    QString methodName = object.value("method").toString();

    if(!object.contains("args"))
        return;

    std::vector<QVariant> methodArgs;
    QJsonValue val = object.value("args");
    if (val.isArray())
    {
        QJsonArray arr = val.toArray();
        for(int i = 0; i < arr.size(); i++)
            methodArgs.push_back(arr.at(i));
    }

    Service service(serviceName, *this);
    QVariant value = service.method(methodName)->with(methodArgs)->serve();

    QJsonDocument res;

    QJsonObject obj;
    obj.insert("version", 1.0);
    obj.insert("return", QJsonValue::fromVariant(value));
    obj.insert("error", QJsonValue::Null);

    res.setObject(obj);
    m_server->send(res.toJson());
}

