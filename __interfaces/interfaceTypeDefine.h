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

#endif