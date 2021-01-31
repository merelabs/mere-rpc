# mere-rpc-lib
`mere-rpc-lib` is a simple RPC library for Qt application based on `mere-message-lib`. 

# Example
## Server

A simple `local` server that hosts a sample `auth` service and to accept request
to perform user's authentication;


```
#include "mere/rpc/server.h"
#include "authservice.h"

int main()
{
    Mere::RPC::Server server = new Mere::RPC::Server("mms://local");
    
    // register service
    AuthService authService= new AuthService();
    server->add("auth", authService);
    
    // Just start it!
    server->start();
}
```

## Client

A simple might look like as following; here client is communicating server 
`local` that hosts authentication service named as `auth`, the name of the 
method we would like to call is `authenticate` and it accepts two arguments 
that we pass as positional arguments.

```
#include "mere/rpc/client.h"

int main()
{
    Mere::RPC::Client client = new Mere::RPC::Client("mms://local/auth");
    client->method("authenticate")->with({"user", "123456"})->call([](QVariant res, QVariant err){
        qDebug() << "Got it:" << res << err;
    });
}
```

# Status
It is still in beta state.


# Reference
* [Mere Message](https://github.com/merelabs/mere-message-lib)
