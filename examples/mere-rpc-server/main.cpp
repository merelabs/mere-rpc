#include <QCoreApplication>
#include <QDebug>

#include "rpcserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    RPCServer server;

    return a.exec();
}
