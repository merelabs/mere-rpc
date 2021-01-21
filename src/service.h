#ifndef MERE_RPC_SERVICE_H
#define MERE_RPC_SERVICE_H

//#include "server.h"
#include "method.h"

#include <QObject>
#include <QMetaMethod>
#include <QDebug>


namespace Mere
{
namespace RPC
{

class Server;

class Service : public QObject
{
    Q_OBJECT
public:
    explicit Service(const QString &service, Server &server);

    Service* method(const QString &name);
    Service* with(const std::vector<QVariant> args);
    QVariant serve();

private:
    std::vector<QMetaMethod> filterByName(const QString &name) const;
    std::vector<QMetaMethod> filterByArgs(const std::vector<QVariant> args) const;
    std::vector<QVariant> convertType(const QMetaMethod &method, const std::vector<QVariant> args);
    QVariant call(QObject *object, const QMetaMethod &method, const std::vector<QVariant> &args);

    bool isArgTypeUsable(const QMetaMethod &method, const std::vector<QVariant> &args) const;
    QList<QGenericArgument> genericArguments(const std::vector<QVariant> args) const;

signals:

private:
    QObject *m_provider;

    const QString m_service;
    const QString m_method;

    std::vector<QVariant> m_args;

    std::vector<QMetaMethod> m_methods;
};

}
}

#endif // MERE_RPC_SERVICE_H
