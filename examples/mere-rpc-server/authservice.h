#ifndef AUTHSERVICE_H
#define AUTHSERVICE_H

#include "mere/rpc/service.h"
#include <QObject>
#include <QDebug>

class AuthService : public QObject
{
    Q_OBJECT
public:
    explicit AuthService(QObject *parent = nullptr){};

    Q_INVOKABLE void foo(int val)
    {
        qDebug() << "Int Value:" << val;
    }

    Q_INVOKABLE void foo(qulonglong val)
    {
        qDebug() << "Long Value:" << val;
    }

    Q_INVOKABLE bool authenticate(const QString &username, const QString &password)
    {
        qDebug() << "Account Value:" << username << password;
        return true;
    }
};

#endif // AUTHSERVICE_H
