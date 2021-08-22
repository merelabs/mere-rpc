#ifndef AUTHSERVICE_H
#define AUTHSERVICE_H

#include <QObject>
#include <QDebug>

class AuthService : public QObject
{
    Q_OBJECT
public:
    explicit AuthService(QObject *parent = nullptr);
    Q_INVOKABLE bool authenticate(const QString &username, const QString &password);
};

#endif // AUTHSERVICE_H
