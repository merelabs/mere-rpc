#include "method.h"

Mere::RPC::Method::Method(const char *name)
    : m_name(name)
{

}

const char* Mere::RPC::Method::name() const
{
    return m_name;
}

int Mere::RPC::Method::count() const
{
    return m_params.size();
}

int Mere::RPC::Method::add(const Param &param)
{
    m_params.push_back(param);
}
