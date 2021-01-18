#include "authservice.h"

AuthService::AuthService(QObject *parent)
    : Mere::RPC::Json::Service("auth", parent)
{

}

bool AuthService::authenticate(const QString &username, const QString &password)
{
    qDebug() << "Method of this service called with " << username << password;
    return true;
}
