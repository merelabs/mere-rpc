#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{
    // A client pointing to the service path
    // service path = mms://server/service
    try
    {
        m_client = new Mere::RPC::Client("mms://lets-call/auth");
    }
    catch(...)
    {
        // catch exception
    }

    // Call the method of desire service and get the response
    m_client->method("authenticate")->with({"user", "123456"})->call([](QVariant res, QVariant err, void* context){
        qDebug() << "Got it:" << res;
    });
}
