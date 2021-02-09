#include "server.h"
#include "method.h"
#include "param.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

Mere::RPC::Server::~Server()
{
    if(m_registry)
    {
        delete m_registry;
        m_registry = nullptr;
    }

    if (m_server)
    {
        m_server->stop();
        delete m_server;
        m_server = nullptr;
    }
}

Mere::RPC::Server::Server(const std::string &path, QObject *parent)
    : QObject(parent),
      m_path(path),
      m_registry(new Mere::RPC::Registry())
{
    m_server = new Mere::Message::Server(m_path);
    connect(m_server, SIGNAL(message(const std::string &)), this, SLOT(message(const std::string &)));
}

int Mere::RPC::Server::start() const
{
    int err = m_server->start();


    return err;
}

QObject* Mere::RPC::Server::get(const std::string &name)
{
    return m_registry->get(name);
}

int Mere::RPC::Server::add(const std::string &name, QObject *service)
{
    return m_registry->add(name, service);
}

void Mere::RPC::Server::message(const std::string &message)
{
    qDebug() << "SERV REQ::" << QString::fromStdString(message);

    QJsonDocument document = QJsonDocument::fromJson(QByteArray(message.c_str()));
    if (document.isNull() || document.isEmpty())
        return;

    if (!document.isObject()) return;

    QJsonObject object = document.object();

    if(!object.contains("id"))
        return;

    if(!object.contains("ver"))
        return;

    if(!object.contains("req"))
        return;

    QJsonObject reqObj = object.value("req").toObject();

    if(!reqObj.contains("serv"))
        return;

    QString serviceName = reqObj.value("serv").toString();

    if(!reqObj.contains("func"))
        return;

    QString methodName = reqObj.value("func").toString();

    if(!reqObj.contains("args"))
        return;

    std::vector<QVariant> methodArgs;
    QJsonValue val = reqObj.value("args");
    if (val.isArray())
    {
        QJsonArray arr = val.toArray();
        for(int i = 0; i < arr.size(); i++)
            methodArgs.push_back(arr.at(i).toVariant());
    }

    Service service(serviceName.toStdString(), *this);
    QVariant value = service.method(methodName.toStdString())->with(methodArgs)->serve();

    QJsonDocument res;

    QJsonObject obj;
    obj.insert("id", "1");
    obj.insert("ver", 1.0);
    obj.insert("res", QJsonValue::fromVariant(value));
    obj.insert("err", QJsonValue::Null);

    res.setObject(obj);

    m_server->send(res.toJson().toStdString());
}

