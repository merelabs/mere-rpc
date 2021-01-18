#ifndef REGISTRY_H
#define REGISTRY_H

#include "service.h"

#include <string>
#include <unordered_map>

#include <QObject>

namespace Mere
{
namespace RPC
{
namespace Json
{

class Registry : public QObject
{
    Q_OBJECT
public:
    explicit Registry(QObject *parent = nullptr);

    // register is a keyword...
    int add(Service *service);

    Service* service(const QString &service) const;

signals:

private:
    std::unordered_map<std::string, Service *> m_services;
};

}
}
}

#endif // REGISTRY_H
