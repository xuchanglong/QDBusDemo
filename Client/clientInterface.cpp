#include "clientInterface.h"
#include "interfaceTypeDefine.h"

ClientInterface::ClientInterface(QObject *parent)
    : QObject(parent)
{
    msg::interface *p_msg_interface;
    p_msg_interface = new msg::interface("com.xcl.test", "/msg/path",
        QDBusConnection::sessionBus());
    CServerData::registerMetaType_CServerData();
    connect(p_msg_interface, &msg::interface::sig_receivedContent,
        this, &ClientInterface::slot_receiveContent4Server);
}

ClientInterface::~ClientInterface()
{
    ;
}

void ClientInterface::synSendContent(QString str_content)
{
    msg::interface msg_interface("com.xcl.test", "/msg/path",
        QDBusConnection::sessionBus());
    QDBusPendingReply<QString> reply = msg_interface.slot_content4Client(str_content);
    reply.waitForFinished();
    emit sig_sendContentResult(reply.value());
    return;
}

void ClientInterface::asynSendContentbyWatcher(QString str_content)
{
    msg::interface msg_interface("com.xcl.test", "/msg/path", QDBusConnection::sessionBus());
    QDBusPendingReply<QString> reply = msg_interface.slot_content4Client(str_content);
    QDBusPendingCallWatcher *watcher = new QDBusPendingCallWatcher(reply, nullptr);
    QObject::connect(watcher, &QDBusPendingCallWatcher::finished, this, &ClientInterface::slot_sendContentResult);
    return;
}

void ClientInterface::asynSendContentbySignal(QString str_content)
{
    msg::interface msg_interface("com.xcl.test", "/msg/path", QDBusConnection::sessionBus());
    msg_interface.slot_content4ClientReturnVoid(str_content);
    return;
}

void ClientInterface::slot_receiveContent4Server(const QString &content, CServerData serverData)
{
    qDebug() << "===  ClientInterface::slot_receiveContent4Server name = " << serverData.m_str_name;
    qDebug() << "===  ClientInterface::slot_receiveContent4Server time = " << serverData.m_str_time;
    emit sig_sendContentResult(content);
    return;
}

void ClientInterface::slot_sendContentResult(QDBusPendingCallWatcher *wather)
{
    QDBusPendingReply<QString> reply = *wather;
    QString strData = reply.argumentAt<0>();
    wather->deleteLater();
    emit sig_sendContentResult(strData);
    return;
}
