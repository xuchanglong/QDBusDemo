#include <QCoreApplication>
#include <QDBusConnection>
#include "serverInterface.h"
#include <QDebug>
#include <QDBusError>

ServerInterface g_server_interface;

void initQDbus();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    initQDbus();
    return a.exec();
}

void initQDbus()
{
    QDBusConnection connection = QDBusConnection::systemBus();
    if (!connection.registerService("com.xcl.test")) {
        qDebug() << connection.lastError().message();
        exit(1);
    }
    connection.registerObject("/msg/path", &g_server_interface,
        QDBusConnection::ExportAllContents);
    return;
}
