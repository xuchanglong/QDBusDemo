#include "serverInterface.h"
#include <QDebug>

ServerInterface::ServerInterface()
{
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
    emit sig_receivedContent(content);
    return;
}
