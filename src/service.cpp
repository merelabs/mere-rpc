#include "service.h"

Mere::RPC::Json::Service::Service(const char *name, QObject *parent)
    : QObject(parent),
      m_name(name)
{

}

const char* Mere::RPC::Json::Service::name() const
{
    return m_name;
}

QMetaMethod Mere::RPC::Json::Service::method(Method method) const
{
    QMetaMethod mm;

    const QMetaObject *metaObject = this->metaObject();

    for (int i = 0; i < metaObject->methodCount(); i++)
    {
        QMetaMethod metaMethod = metaObject->method(i);

        if (metaMethod.access() != QMetaMethod::Public || metaMethod.methodType() == QMetaMethod::Signal)
            continue;

        if (QString(metaMethod.name()).compare(method.name()) != 0)
            continue;

        if (metaMethod.parameterCount() != method.count())
            continue;

        // check the type of each params....

         qDebug()  << metaMethod.parameterCount() << metaMethod.parameterNames() << metaMethod.parameterTypes();

        QString signature = QString::fromLatin1(metaMethod.methodSignature());

        mm = metaMethod;
        break;
    }

    return mm;
}
