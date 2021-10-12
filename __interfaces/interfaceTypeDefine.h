#ifndef INTERFACETYPEDEFINE_H_
#define INTERFACETYPEDEFINE_H_

#include <QString>
#include <QDBusArgument>

class CServerData {
public:
    explicit CServerData() {};
    ~CServerData() {};

public:
    friend QDBusArgument &operator<<(QDBusArgument &argument, const CServerData &);
    friend const QDBusArgument &operator>>(const QDBusArgument &argument, CServerData &);
    static void registerMetaType_CServerData();

    QString m_str_name;
    QString m_str_time;
};
Q_DECLARE_METATYPE(CServerData)

class CServerDataList : public QList<CServerData> {
public:
    friend QDBusArgument &operator<<(QDBusArgument &argument, const CServerDataList &);
    friend const QDBusArgument &operator>>(const QDBusArgument &argument, CServerDataList &);
    static void registerMetaType_CServerDataList();
};
Q_DECLARE_METATYPE(CServerDataList)

#endif