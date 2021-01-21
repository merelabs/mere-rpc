#include "server.h"
#include "authservice.h"

Server::Server(QObject *parent) : QObject(parent)
{
    // A Server
    try
    {
        m_server = new Mere::RPC::Server("/display");
    }
    catch(...)
    {
        // catch exception
    }

    // Register one or more service
    m_authService = new AuthService();
    m_server->add("auth", m_authService);

//    Mere::RPC::Service s("service", m_server);
//    s.method("authenticate")->with({"iklash", "iklash22"})->serve();
//    s.method("foo")->with({10})->serve();

    // Just start it!
    m_server->start();
}
