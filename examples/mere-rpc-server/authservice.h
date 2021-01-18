#ifndef AUTHSERVICE_H
#define AUTHSERVICE_H

#include "mere/json-rpc/service.h"
#include <QObject>
#include <QDebug>

class AuthService : public Mere::RPC::Json::Service
{
    Q_OBJECT
public:
    explicit AuthService(QObject *parent = nullptr);

public slots:
    bool authenticate(const QString &username, const QString &password);
    bool authenticate(const QString &username){return  false;};
    bool authenticate(const int &username){return  false;};
    bool authenticate(const int &username, const int &password){return  false;};
    bool authenticate(const QString &username, const int &password){return  false;};
    bool authenticate(const int &username, const QString &password){return  false;};
    bool authenticate(const char *username, const char *password){return  false;};
//signals:

};

#endif // AUTHSERVICE_H
