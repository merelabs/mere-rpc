#include <QCoreApplication>

#include "client.h"
#include "mere/rpc/client.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Client client;
//    client.ping();
//    Mere::RPC::Json::Client client("service");
//    client.method("authenticate")->with("iklash", "password")->call();


    return a.exec();
}
