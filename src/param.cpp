#include "param.h"

QString Mere::RPC::Param::name() const
{
    return m_name;
}

void Mere::RPC::Param::setName(const QString &name)
{
    m_name = name;
}

QString Mere::RPC::Param::type() const
{
    return m_type;
}

void Mere::RPC::Param::setType(const QString &type)
{
    m_type = type;
}

QVariant Mere::RPC::Param::value() const
{
    return m_value;
}

void Mere::RPC::Param::setValue(const QVariant &value)
{
    m_value = value;
}
