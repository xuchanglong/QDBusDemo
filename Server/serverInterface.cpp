#include "serverInterface.h"
#include <QDebug>

ServerInterface::ServerInterface()
{
    CServerData::registerMetaType_CServerData();
    CServerDataList::registerMetaType_CServerDataList();
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
    CServerDataList List;
    CServerData serverData1, serverData2;
    serverData1.m_str_name = "server1";
    serverData1.m_str_time = "1998-09-23";
    serverData2.m_str_name = "server2";
    serverData2.m_str_time = "2008-09-23";
    List.push_back(serverData2);
    emit sig_receivedContent(content, serverData1, List);
    return;
}
