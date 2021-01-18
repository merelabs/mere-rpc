#include <QCoreApplication>

#include "rpcclient.h"
#include "mere/json-rpc/client.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    RPCClient client;
//    client.ping();
//    Mere::RPC::Json::Client client("service");
//    client.method("authenticate")->with("iklash", "password")->call();


    return a.exec();
}
