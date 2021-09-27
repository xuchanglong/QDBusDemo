#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDBusConnection>
#include "serverInterface.h"
#include <QDebug>
#include <QDBusError>
#include <QLineEdit>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void slot_contentChanged(QString);

private:
    void InitQDbus();
    void InitWin();
    void InitUI();
    void InitControl();

private:
    ServerInterface m_server_interface;

private:
    QLineEdit *m_pLineEdit;
};

#endif
