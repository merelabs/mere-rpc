QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

TARGET = mere-rpc-server 
TEMPLATE = app

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    authservice.h \
    server.h

SOURCES += \
        authservice.cpp \
        main.cpp \
        server.cpp

INCLUDEPATH += /usr/local/include

LIBS += -lmere-rpc -lrt
