#include "service.h"
#include "server.h"
#include <stdarg.h>

Mere::RPC::Service::Service(const QString &service, Server &server)
    : QObject(&server),
      m_service(service)
{
    m_provider = server.get(service);
}

Mere::RPC::Service* Mere::RPC::Service::method(const QString &name)
{
    qDebug() << "Filter methods by name:" << name << m_provider;
    if (m_provider)
        m_methods = this->filterByName(name);

    return this;
};

Mere::RPC::Service* Mere::RPC::Service::with(const std::vector<QVariant> args)
{
    qDebug() << "Filter methods by args:" << args;
    if (m_provider && m_methods.size())
        m_methods = this->filterByArgs(m_args = args);

    return this;
}

QVariant Mere::RPC::Service::serve()
{
    QVariant value;
    if (m_provider && m_methods.size())
        value = call(m_provider, m_methods.at(0), m_args);

    qDebug() << "Yes, going to server!!!" << value;

    return value;
}

std::vector<QMetaMethod> Mere::RPC::Service::filterByName(const QString &name) const
{
    std::vector<QMetaMethod> metaMethods;

    const QMetaObject *metaObject = m_provider->metaObject();

    for (int index = 0; index < metaObject->methodCount(); index++)
    {
        QMetaMethod metaMethod = metaObject->method(index);

        if (metaMethod.access() != QMetaMethod::Public || metaMethod.methodType() == QMetaMethod::Signal)
            continue;

        if (QString(metaMethod.name()).compare(name) != 0)
            continue;

        metaMethods.push_back(metaMethod);
    }

    return metaMethods;
}

std::vector<QMetaMethod> Mere::RPC::Service::filterByArgs(const std::vector<QVariant> args) const
{
    std::vector<QMetaMethod> metaMethods;

    for( const auto &method : m_methods)
    {
        if (method.parameterCount() != args.size())
            continue;

        if (!isArgTypeUsable(method, args))
            continue;

        metaMethods.push_back(method);
        break;
    }

    return metaMethods;
}

bool Mere::RPC::Service::isArgTypeUsable(const QMetaMethod &method, const std::vector<QVariant> &args) const
{
    for(int i = 0; i < args.size(); i++)
    {
        QVariant arg = args[i];

        int argType = arg.userType();
        int paramType = method.parameterType(i);

        if (argType == paramType)
            continue;

        if(!arg.canConvert(paramType))
            return false;
    }

    return true;
}


std::vector<QVariant> Mere::RPC::Service::convertType(const QMetaMethod &method, const std::vector<QVariant> args)
{
    std::vector<QVariant> _args;
    for(int i = 0; i < args.size(); i++)
    {
        QVariant arg = args[i];
        if(!arg.convert(method.parameterType(i)))
        {
            qDebug() << "Error!";
            break;
        }
        _args.push_back(arg);
    }

    return _args;
}

QList<QGenericArgument> Mere::RPC::Service::genericArguments(const std::vector<QVariant> args) const
{
    QList<QGenericArgument> arguments;
    for (auto &arg  : args)
    {
        QGenericArgument genericArgument(
                    QMetaType::typeName(arg.userType()),
                    const_cast<void*>(arg.constData())
                );

        arguments << genericArgument;
    }

    return arguments;
};



QVariant Mere::RPC::Service::call(QObject *object, const QMetaMethod &method, const std::vector<QVariant> &args)
{
    std::vector<QVariant> _args = convertType(method, args);

//    QList<QGenericArgument> arguments = genericArguments(_args);

    QList<QGenericArgument> arguments;
    for (int i = 0; i < _args.size(); i++)
    {
        QGenericArgument genericArgument(
            QMetaType::typeName(_args[i].userType()),
            const_cast<void*>(_args[i].constData())
        );
        arguments << genericArgument;
    }

    QVariant returnValue(QMetaType::type(method.typeName()),
        static_cast<void*>(NULL));

    QGenericReturnArgument returnArgument(
        method.typeName(),
        const_cast<void*>(returnValue.constData())
    );

    bool ok = method.invoke(
        object,
        Qt::DirectConnection,
        returnArgument,
        arguments.value(0),
        arguments.value(1),
        arguments.value(2),
        arguments.value(3),
        arguments.value(4),
        arguments.value(5),
        arguments.value(6),
        arguments.value(7),
        arguments.value(8),
        arguments.value(9)
    );

    if (!ok) {
        qWarning() << "Calling" << method.methodSignature() << "failed.";
        return QVariant();
    } else {
        return returnValue;
    }
}
