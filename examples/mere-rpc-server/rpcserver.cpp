#include "rpcserver.h"
#include "authservice.h"

#include <QMetaObject>
#include <QMetaMethod>
//#include <QMeta>

RPCServer::RPCServer(QObject *parent) : QObject(parent)
{
    m_server = new Mere::RPC::Json::Server("service");
//    connect(m_server, SIGNAL(message(const Mere::Message::Message &)), this, SLOT(message(const Mere::Message::Message &)));
//    connect(m_server, SIGNAL(message(const QString &)), this, SLOT(message(const QString &)));
//    connect(m_server, SIGNAL(request(const QJsonObject &)), this, SLOT(request(const QJsonObject &)));

//    m_server->start();

//    delete m_server;

    AuthService service;
    m_server->add(&service);

//    service.metaObject();

    QString methodName = "authenticate";
//    QStringList methodParams =

//    for(int i=0; i<(&service)->metaObject()->methodCount(); i++)
//    {
        const QMetaObject *mo = (&service)->metaObject();

//        QMetaMethod meta = (&service)->metaObject()->method( i );

//        qDebug() << meta.methodType() << meta.name();
//        if( meta.methodType() == QMetaMethod::Signal )
//            qDebug()  << meta.parameterTypes() << meta.parameterNames();

//            bool found = false;
            for (int methodIndex = 0; methodIndex < mo->methodCount(); methodIndex++)
            {
                QMetaMethod method = mo->method(methodIndex);

                if (method.access() != QMetaMethod::Public || method.methodType() == QMetaMethod::Signal)
                    continue;

                if (QString(method.name()).compare(methodName) != 0)
                    continue;

                 qDebug()  << method.parameterCount() << method.parameterNames() << method.parameterTypes();

                QString signature = QString::fromLatin1(method.methodSignature());
//            qDebug() << "1...." << signature << method.access() << method.methodType();
//                if (signature.startsWith(checkedSignature)) {
//                    found = true;
//                    break;
//                }
            }
//            return found;
//    }

}

void RPCServer::request(const QJsonObject &)
{

}

//void RPCServer::ping(const int &pid)
//{
//    qDebug() << "SOMEONE PING ME" << pid;
//}

//void RPCServer::message(const QString &message)
//{
//    qDebug() << "MESSAGE BODY ONLY" << message;
//}

//void RPCServer::message(const Mere::Message::Message &message)
//{
//    qDebug() << "MESSAGE HEADER AND BODY";
//}
