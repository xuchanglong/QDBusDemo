#include "interfaceTypeDefine.h"
#include "qdbusmetatype.h"

QDBusArgument &operator<<(QDBusArgument &argument, const CServerData &serverData)
{
    argument.beginStructure();
    argument << serverData.m_str_name;
    argument << serverData.m_str_time;
    argument.endStructure();

    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, CServerData &serverData)
{
    argument.beginStructure();
    argument >> serverData.m_str_name;
    argument >> serverData.m_str_time;
    argument.endStructure();

    return argument;
}

void CServerData::registerMetaType_CServerData()
{
    qRegisterMetaType<CServerData>("CServerData");
    qDBusRegisterMetaType<CServerData>();
}