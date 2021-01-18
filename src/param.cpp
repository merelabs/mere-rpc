#include "param.h"

QString Mere::RPC::Json::Param::name() const
{
    return m_name;
}

void Mere::RPC::Json::Param::setName(const QString &name)
{
    m_name = name;
}

QString Mere::RPC::Json::Param::type() const
{
    return m_type;
}

void Mere::RPC::Json::Param::setType(const QString &type)
{
    m_type = type;
}

QVariant Mere::RPC::Json::Param::value() const
{
    return m_value;
}

void Mere::RPC::Json::Param::setValue(const QVariant &value)
{
    m_value = value;
}
