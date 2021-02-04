#include "registry.h"

Mere::RPC::Registry::Registry(QObject *parent) : QObject(parent)
{

}

int Mere::RPC::Registry::add(const std::string &name, QObject *service)
{
    if (name.empty())
        return 1;

    auto it = m_services.find(name);
    if (it != m_services.end())
        return 2;

    m_services.insert({name, service});

    return 0;
}

QObject* Mere::RPC::Registry::get(const std::string &name) const
{
    if (name.empty())
        return nullptr;

    if (m_services.empty())
        return nullptr;

    auto it = m_services.find(name);
    if (it == m_services.end())
        return nullptr;

    return it->second;
}
