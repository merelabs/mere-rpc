#ifndef MERE_RPC_REGISTRY_H
#define MERE_RPC_REGISTRY_H

#include "service.h"

#include <string>
#include <unordered_map>

#include <QObject>

namespace Mere
{
namespace RPC
{

class Registry : public QObject
{
    Q_OBJECT
public:
    explicit Registry(QObject *parent = nullptr);

    // register is a keyword...
    int add(const std::string &name, QObject *service);

    QObject* get(const std::string &name) const;

signals:

private:
    std::unordered_map<std::string, QObject *> m_services;
};

}
}

#endif // MERE_RPC_REGISTRY_H
