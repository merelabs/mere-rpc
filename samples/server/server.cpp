#include "server.h"
#include "authservice.h"

Server::Server(QObject *parent) : QObject(parent)
{
    // A Server
    try
    {
        m_server = new Mere::RPC::Server("mms://lets-call");
    }
    catch(...)
    {
        // catch exception
    }

    // Register one or more service
    m_authService = new AuthService();
    m_server->add("auth", m_authService);

    // Just start it!
    m_server->start();
}
