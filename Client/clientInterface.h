#ifndef CLIENTINTERFACE_H_
#define CLIENTINTERFACE_H_

#include <QString>
#include <QObject>
#include "msgInterface.h"

class ClientInterface : public QObject {
    Q_OBJECT
    
public:
    explicit ClientInterface(QObject *parent = 0);
    ~ClientInterface();

signals:
    void sig_sendContentResult(QString);

public:
    void synSendContent(QString name);
    void asynSendContentbyWatcher(QString name);
    void asynSendContentbySignal(QString name);

private slots:
    void slot_receiveContent4Server(QString);
    void slot_sendContentResult(QDBusPendingCallWatcher *wather);
};

#endif
