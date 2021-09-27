#include "mainwindow.h"
#include <unistd.h>
#include "__interfaces/msgInterface.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    InitWin();
    InitUI();
    InitControl();
}

MainWindow::~MainWindow()
{
}

void MainWindow::InitWin()
{
    setFixedSize(600, 400);
    setWindowTitle("---   Client   ---");
}

void MainWindow::InitUI()
{
    QLabel *m_pLabelC2S = new QLabel(this);
    m_pLabelC2S->setObjectName("m_pLabelC2S");
    m_pLabelC2S->setGeometry(50, 50, 100, 30);
    m_pLabelC2S->setText("Client 2 Server：");

    m_pLineEditC2S = new QLineEdit(this);
    m_pLineEditC2S->setObjectName("m_pLineEditC2S");
    m_pLineEditC2S->setGeometry(150, 50, 150, 30);

    QLabel *m_pLabelS2C = new QLabel(this);
    m_pLabelS2C->setObjectName("m_pLabelS2C");
    m_pLabelS2C->setGeometry(50, 100, 100, 30);
    m_pLabelS2C->setText("Server 2 Client：");

    m_pLineEditS2C = new QLineEdit(this);
    m_pLineEditS2C->setObjectName("m_pLineEditS2C");
    m_pLineEditS2C->setGeometry(150, 100, 150, 30);

    m_p_btnSynSend = new QPushButton(this);
    m_p_btnSynSend->setObjectName("m_p_btnSynSend");
    m_p_btnSynSend->setGeometry(400, 50, 150, 30);
    m_p_btnSynSend->setText("同步发送");

    m_p_btnASynSendbyReturnValue = new QPushButton(this);
    m_p_btnASynSendbyReturnValue->setObjectName("m_p_btnASynSendbyReturnValue");
    m_p_btnASynSendbyReturnValue->setGeometry(400, 100, 150, 30);
    m_p_btnASynSendbyReturnValue->setText("异步发送（Watcher）");

    m_p_btnASynSendbySignal = new QPushButton(this);
    m_p_btnASynSendbySignal->setObjectName("m_p_btnASynSendbySignal");
    m_p_btnASynSendbySignal->setGeometry(400, 150, 150, 30);
    m_p_btnASynSendbySignal->setText("异步发送（Signal）");
    return;
}

void MainWindow::InitControl()
{
    connect(m_p_btnSynSend, &QPushButton::clicked, this, &MainWindow::slot_synSendMsg);
    connect(m_p_btnASynSendbyReturnValue, &QPushButton::clicked, this, &MainWindow::slot_asynSendMsgbyWatcher);
    connect(m_p_btnASynSendbySignal, &QPushButton::clicked, this, &MainWindow::slot_asynSendMsgbySignal);
    connect(&m_client_interface, &ClientInterface::sig_sendContentResult, this, &MainWindow::slot_sendContentResult);
    return;
}

void MainWindow::slot_synSendMsg()
{
    m_client_interface.synSendContent(m_pLineEditC2S->text());
    return;
}

void MainWindow::slot_asynSendMsgbyWatcher()
{
    m_client_interface.asynSendContentbyWatcher(m_pLineEditC2S->text());
    return;
}

void MainWindow::slot_asynSendMsgbySignal()
{
    m_client_interface.asynSendContentbySignal(m_pLineEditC2S->text());
    return;
}

void MainWindow::slot_sendContentResult(QString str)
{
    m_pLineEditS2C->setText(str);
}