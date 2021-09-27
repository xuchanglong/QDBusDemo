#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "clientInterface.h"
#include <QString>
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void slot_synSendMsg();
    void slot_asynSendMsgbyWatcher();
    void slot_asynSendMsgbySignal();
    void slot_sendContentResult(QString);

private:
    void InitWin();
    void InitUI();
    void InitControl();

private:
    ClientInterface m_client_interface;

private:
    QLabel *m_pLabelC2S;
    QLineEdit *m_pLineEditC2S;
    QLabel *m_pLabelS2C;
    QLineEdit *m_pLineEditS2C;
    QPushButton *m_p_btnSynSend;
    QPushButton *m_p_btnASynSendbyReturnValue;
    QPushButton *m_p_btnASynSendbySignal;
};

#endif
