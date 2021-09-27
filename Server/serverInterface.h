#ifndef SERVERINTERFACE_H_
#define SERVERINTERFACE_H_

#include <QObject>
#include <QString>

#include "__interfaces/interfaceTypeDefine.h"

class ServerInterface : public QObject {
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "msg.interface")

public:
    explicit ServerInterface();
    ~ServerInterface();

signals:
    void sig_contentChanged(QString);
    void sig_receivedContent(const QString &in0, CServerData serverData);

public slots:
    QString slot_content4Client(QString content);
    void slot_content4ClientReturnVoid(QString content);
};

#endif 
