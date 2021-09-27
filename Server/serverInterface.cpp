#include "serverInterface.h"
#include <QDebug>

ServerInterface::ServerInterface()
{
    CServerData::registerMetaType_CServerData();
}

ServerInterface::~ServerInterface()
{
}

QString ServerInterface::slot_content4Client(QString content)
{
    emit sig_contentChanged(content);
    return content;
}

void ServerInterface::slot_content4ClientReturnVoid(QString content)
{
    emit sig_contentChanged(content);
    CServerData serverData;
    serverData.m_str_name = "server";
    serverData.m_str_time = "1998-09-23";
    emit sig_receivedContent(content, serverData);
    return;
}
