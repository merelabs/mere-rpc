#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{
    // A client pointing to the service path
    // service path = /server/service
    try
    {
        m_client = new Mere::RPC::Client("mms://display/auth");
    }
    catch(...)
    {
        // catch exception
    }

    // Call the method of desire service and get the response
    m_client->method("authenticate")->with({"user", "123456"})->call([](QVariant res, QVariant err){
        qDebug() << "Got it:" << res;
    });
}
