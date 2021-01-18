#include "server.h"
#include "method.h"
#include "param.h"

#include <QJsonObject>
#include <QJsonDocument>

Mere::RPC::Json::Server::~Server()
{
    m_server->stop();
}

Mere::RPC::Json::Server::Server(const QString &service, QObject *parent)
    : QObject(parent),
      m_service(service),
      m_registry(new Mere::RPC::Json::Registry())
{
    QString server("/" + service);
    m_server = new Mere::Message::Server(server.toStdString().c_str());
    connect(m_server, SIGNAL(message(const QString &)), this, SLOT(message(const QString &)));

    m_server->start();
}

int Mere::RPC::Json::Server::add(Service *service)
{
    return m_registry->add(service);
}

void Mere::RPC::Json::Server::message(const QString &message)
{
    qDebug() << "WHAT I GIT AS REQUEST??" << message;

    QJsonDocument document = QJsonDocument::fromJson(message.toUtf8());
    if (document.isNull() || document.isEmpty())
        return;

    if (document.isArray()) return;

    QJsonObject object = document.object();

    qDebug() << "Service:" << object.value("service").toString();
    qDebug() << "Method:"  << object.value("method").toString();
    qDebug() << "Params:"  << object.value("params").toString();




//    const char *name = object.value("method").toString().toStdString().c_str();
//    Method method(name);

//    Param p1;
//    p1.setName("username");
//    p1.setType("QString");
//    method.add(p1);

//    Param p2;
//    p2.setName("password");
//    p2.setType("QString");
//    method.add(p1);


//    QMetaMethod mm = m_registry->service(object.value("service").toString())->method(method);
//    if(mm.isValid())
//        mm.invoke();
    try
    {
        Service service("hellow...");
        service.method("authenticate")->with("a...", "b...")->serve();
    }
    catch (...)
    {

    }
}

