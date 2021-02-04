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
    explicit Service(const std::string &service, Server &server);

    Service* method(const std::string &name);
    Service* with(const std::vector<QVariant> args);
    QVariant serve();

private:
    std::vector<QMetaMethod> filterByName(const std::string &name) const;
    std::vector<QMetaMethod> filterByArgs(const std::vector<QVariant> args) const;
    std::vector<QVariant> convertType(const QMetaMethod &method, const std::vector<QVariant> args);
    QVariant call(QObject *object, const QMetaMethod &method, const std::vector<QVariant> &args);

    bool isArgTypeUsable(const QMetaMethod &method, const std::vector<QVariant> &args) const;
    QList<QGenericArgument> genericArguments(const std::vector<QVariant> args) const;

signals:

private:
    QObject *m_provider;

    const std::string m_service;
    const std::string m_method;

    std::vector<QVariant> m_args;

    std::vector<QMetaMethod> m_methods;
};

}
}

#endif // MERE_RPC_SERVICE_H
