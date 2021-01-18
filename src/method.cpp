#include "method.h"

Mere::RPC::Json::Method::Method(const char *name)
    : m_name(name)
{

}

const char* Mere::RPC::Json::Method::name() const
{
    return m_name;
}

int Mere::RPC::Json::Method::count() const
{
    return m_params.size();
}

int Mere::RPC::Json::Method::add(const Param &param)
{
    m_params.push_back(param);
}
