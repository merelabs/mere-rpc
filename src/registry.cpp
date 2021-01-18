#include "registry.h"

Mere::RPC::Json::Registry::Registry(QObject *parent) : QObject(parent)
{

}

int Mere::RPC::Json::Registry::add(Service *service)
{
    std::string name = service->name();

    auto it = m_services.find(name);
    if (it != m_services.end())
        return 1;

    m_services.insert({name, service});

    return 0;
}

Mere::RPC::Json::Service* Mere::RPC::Json::Registry::service(const QString &service) const
{
    std::string name = service.toStdString();

    if (m_services.empty())
        return nullptr;

    auto it = m_services.find(name);
    if (it == m_services.end())
        return nullptr;

    return it->second;
}
