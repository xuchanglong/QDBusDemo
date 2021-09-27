#include "mainwindow.h"
#include <QDBusConnection>
#include <QDBusError>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    InitQDbus();
    InitWin();
    InitUI();
    InitControl();
}

MainWindow::~MainWindow()
{
}

void MainWindow::InitQDbus()
{
    QDBusConnection connection = QDBusConnection::systemBus();
    if (!connection.registerService("com.xcl.test")) {
        qDebug() << connection.lastError().message();
        exit(1);
    }
    connection.registerObject("/msg/path", &m_server_interface,
        QDBusConnection::ExportAllContents);
    return;
}

void MainWindow::InitWin()
{
    setFixedSize(300, 100);
    setWindowTitle("---   Server   ---");
    return;
}

void MainWindow::InitUI()
{
    m_pLineEdit = new QLineEdit(this);
    m_pLineEdit->setObjectName("m_pLineEdit");
    m_pLineEdit->setGeometry(30, 50, 150, 30);
    return;
}

void MainWindow::InitControl()
{
    CServerData::registerMetaType_CServerData();
    connect(&m_server_interface, &ServerInterface::sig_contentChanged, this, &MainWindow::slot_contentChanged);
    return;
}

void MainWindow::slot_contentChanged(QString str)
{
    m_pLineEdit->setText(str);
    return;
}