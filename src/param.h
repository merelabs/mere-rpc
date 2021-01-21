#ifndef MERE_RPC_PARAM_H
#define MERE_RPC_PARAM_H

#include <QObject>
#include <QVariant>

namespace Mere
{
namespace RPC
{

class Param
{
public:
    Param() = default;

    QString name() const;
    void setName(const QString &name);

    QString type() const;
    void setType(const QString &type);

    QVariant value() const;
    void setValue(const QVariant &value);

signals:

private:
    unsigned int m_position;
    QString m_name;
    QString m_type;
    QVariant m_value;
};

}
}


#endif // MERE_RPC_PARAM_H
