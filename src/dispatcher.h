#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <QObject>

namespace Mere
{
namespace RPC
{
namespace Json
{

class Dispatcher : public QObject
{
    Q_OBJECT
public:
    explicit Dispatcher(QObject *parent = nullptr);
    int dispatch();

signals:

};

}
}
}

#endif // DISPATCHER_H
