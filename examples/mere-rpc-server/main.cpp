#include <QCoreApplication>
#include <QDebug>

#include "authservice.h"

#include <QObject>
#include <QtCore>
#include <QMetaMethod>
#include <QMetaObject>
#include "rpcserver.h"

//QVariant call(QObject* object, QMetaMethod metaMethod, QVariantList args)
//{
//    // Convert the arguments

//    QVariantList converted;

//    // We need enough arguments to perform the conversion.

//    QList<QByteArray> methodTypes = metaMethod.parameterTypes();
//    if (methodTypes.size() < args.size()) {
//        qWarning() << "Insufficient arguments to call" << metaMethod.methodSignature();
//        return QVariant();
//    }

//    for (int i = 0; i < methodTypes.size(); i++) {
//        const QVariant& arg = args.at(i);

//        QByteArray methodTypeName = methodTypes.at(i);
//        QByteArray argTypeName = arg.typeName();

//        QVariant::Type methodType = QVariant::nameToType(methodTypeName);
//        QVariant::Type argType = arg.type();

//        QVariant copy = QVariant(arg);

//        // If the types are not the same, attempt a conversion. If it
//        // fails, we cannot proceed.

//        if (copy.type() != methodType) {
//            if (copy.canConvert(methodType)) {
//                if (!copy.convert(methodType)) {
//                    qWarning() << "Cannot convert" << argTypeName
//                               << "to" << methodTypeName;
//                    return QVariant();
//                }
//            }
//        }

//        converted << copy;
//    }

//    QList<QGenericArgument> arguments;

//    for (int i = 0; i < converted.size(); i++) {

//        // Notice that we have to take a reference to the argument, else
//        // we'd be pointing to a copy that will be destroyed when this
//        // loop exits.

//        QVariant& argument = converted[i];

//        // A const_cast is needed because calling data() would detach
//        // the QVariant.

//        QGenericArgument genericArgument(
//            QMetaType::typeName(argument.userType()),
//            const_cast<void*>(argument.constData())
//        );

//        arguments << genericArgument;
//    }

//    QVariant returnValue(QMetaType::type(metaMethod.typeName()),
//        static_cast<void*>(NULL));

//    QGenericReturnArgument returnArgument(
//        metaMethod.typeName(),
//        const_cast<void*>(returnValue.constData())
//    );

//    // Perform the call

//    bool ok = metaMethod.invoke(
//        object,
//        Qt::DirectConnection,
//        returnArgument,
//        arguments.value(0),
//        arguments.value(1),
//        arguments.value(2),
//        arguments.value(3),
//        arguments.value(4),
//        arguments.value(5),
//        arguments.value(6),
//        arguments.value(7),
//        arguments.value(8),
//        arguments.value(9)
//    );

//    if (!ok) {
//        qWarning() << "Calling" << metaMethod.methodSignature() << "failed.";
//        return QVariant();
//    } else {
//        return returnValue;
//    }
//}

//class Target : public QObject
//{
//    Q_OBJECT;

//public:

//    explicit Target(QObject* parent = 0) : QObject(parent) {
//    }

//    Q_INVOKABLE virtual void foo(qulonglong val) {
//        qDebug() << "Value:" << val;
//    }
//};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    RPCServer server;

    return a.exec();
}

//int main(int argc, char** argv) {
//    QCoreApplication a(argc, argv);

//    AuthService* t = new AuthService();

//    int index = t->metaObject()->indexOfMethod("foo(qulonglong)");
//    QMetaMethod metaMethod = t->metaObject()->method(index);

//    QVariantList list;
//    list << QVariant("10");

//    call(t, metaMethod, list);

//    a.exec();
//}

