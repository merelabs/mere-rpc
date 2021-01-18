QT -= gui

TARGET = mere-rpc
TEMPLATE = lib

CONFIG += c++11
CONFIG += shared

DEFINES += MERE_JSON_RPC_LIB

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/client.cpp \
    src/dispatcher.cpp \
    src/method.cpp \
    src/param.cpp \
    src/registry.cpp \
    src/server.cpp \
    src/service.cpp

HEADERS += \
    src/client.h \
    src/dispatcher.h \
    src/global.h \
    src/method.h \
    src/param.h \
    src/registry.h \
    src/server.h \
    src/service.h

INCLUDEPATH += /usr/local/include

#LIBS += -lmere-message -lrt
LIBS += -lmere-message

#
# Install
#
unix {
    target.path = /usr/local/lib
    INSTALLS += target

    INSTALL_PREFIX = /usr/local/include/mere/json-rpc
    for(header, HEADERS) {
        sdir = $${dirname(header)}
        sdir = $$replace(sdir, "src", "")
        path = $${INSTALL_PREFIX}$${sdir}

        eval(headers_$${path}.files += $$header)
        eval(headers_$${path}.path = $$path)
        eval(INSTALLS *= headers_$${path})
    }
}
#!isEmpty(target.path): INSTALLS += target
