#ifndef MERE_RPC_METHOD_H
#define MERE_RPC_METHOD_H

#include "param.h"
#include <QObject>

namespace Mere
{
namespace RPC
{

class Method
{
public:
    explicit Method(const char *name);

    const char* name() const;
    int count() const;

    int add(const Param &param);
signals:


private:
    const char *m_name;

    std::vector<Param> m_params;
};

}
}

#endif // MERE_RPC_METHOD_H
