#include "client.h"


Client::Client(QObject *parent) : QObject(parent)
{
    // A client pointing to the service path
    // service path = /server/service
    try
    {
        m_client = new Mere::RPC::Client("/display/auth");
    }
    catch(...)
    {
        // catch exception
    }

    // Call the method of desire service and get the response
    m_client->method("authenticate")->with({"iklash", "iklash22"})->call([](QVariant res, QVariant err){
        qDebug() << "WOW! Got it:" << res;
    });
}
