/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp msgInterface.xml -p msgInterface
 *
 * qdbusxml2cpp is Copyright (C) 2020 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#include "msgInterface.h"

/*
 * Implementation of interface class MsgInterfaceInterface
 */

MsgInterfaceInterface::MsgInterfaceInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent)
    : QDBusAbstractInterface(service, path, staticInterfaceName(), connection, parent)
{
}

MsgInterfaceInterface::~MsgInterfaceInterface()
{
}

