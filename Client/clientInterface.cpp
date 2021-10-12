#include "clientInterface.h"
#include "__interfaces/interfaceTypeDefine.h"

ClientInterface::ClientInterface(QObject *parent)
    : QObject(parent)
{
    msg::interface *p_msg_interface;
    p_msg_interface = new msg::interface("com.xcl.test", "/msg/path",
        QDBusConnection::systemBus());
    CServerData::registerMetaType_CServerData();
    CServerDataList::registerMetaType_CServerDataList();
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
        QDBusConnection::systemBus());
    QDBusPendingReply<QString> reply = msg_interface.slot_content4Client(str_content);
    reply.waitForFinished();
    emit sig_sendContentResult(reply.value());
    return;
}

void ClientInterface::asynSendContentbyWatcher(QString str_content)
{
    msg::interface msg_interface("com.xcl.test", "/msg/path", QDBusConnection::systemBus());
    QDBusPendingReply<QString> reply = msg_interface.slot_content4Client(str_content);
    QDBusPendingCallWatcher *watcher = new QDBusPendingCallWatcher(reply, nullptr);
    QObject::connect(watcher, &QDBusPendingCallWatcher::finished, this, &ClientInterface::slot_sendContentResult);
    return;
}

void ClientInterface::asynSendContentbySignal(QString str_content)
{
    msg::interface msg_interface("com.xcl.test", "/msg/path", QDBusConnection::systemBus());
    msg_interface.slot_content4ClientReturnVoid(str_content);
    return;
}

void ClientInterface::slot_receiveContent4Server(const QString &in0, CServerData serverData, CServerDataList serverDataList)
{
    qDebug() << "===  ClientInterface::slot_receiveContent4Server name = " << serverData.m_str_name;
    qDebug() << "===  ClientInterface::slot_receiveContent4Server time = " << serverData.m_str_time;
    QList<CServerData>::iterator it = serverDataList.begin();
    for (; it != serverDataList.end(); ++it) {
        qDebug() << "===  ClientInterface::slot_receiveContent4Server name = " << it->m_str_name;
        qDebug() << "===  ClientInterface::slot_receiveContent4Server time = " << it->m_str_time;
    }
    emit sig_sendContentResult(in0);
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
