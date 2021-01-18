#ifndef SERVICE_H
#define SERVICE_H

#include "method.h"

#include <QObject>
#include <QMetaMethod>
#include <QDebug>

namespace Mere
{
namespace RPC
{
namespace Json
{

class Service : public QObject
{
    Q_OBJECT
public:
    explicit Service(const char *name, QObject *parent = nullptr);

    const char *name() const;

    Service* method(const QString &method)
    {
        return this;
    };

    Service* with(const QVariant &...)
    {

        return this;
    }

    void serve()
    {
        qDebug() << "Yes, going to server!!!";
    }



    QMetaMethod method(Method method) const;

signals:

private:
    const char *m_name;
};

}
}
}
#endif // SERVICE_H
