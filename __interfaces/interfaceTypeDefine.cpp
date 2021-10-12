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

QDBusArgument &operator<<(QDBusArgument &argument, const CServerDataList &serverDataList)
{
    argument.beginArray(qMetaTypeId<CServerData>());
    for (int i = 0; i < serverDataList.count(); ++i) {
        argument << serverDataList.at(i);
    }
    argument.endArray();
    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, CServerDataList &serverDataList)
{
    argument.beginArray();
    while (!argument.atEnd()) {
        CServerData item;
        argument >> item;
        serverDataList.append(item);
    }
    argument.endArray();
    return argument;
}

void CServerDataList::registerMetaType_CServerDataList()
{
    qRegisterMetaType<CServerDataList>("CServerDataList");
    qDBusRegisterMetaType<CServerDataList>();
}