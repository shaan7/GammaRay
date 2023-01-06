/*
  methodsextensioninterface.cpp

  This file is part of GammaRay, the Qt application inspection and manipulation tool.

  SPDX-FileCopyrightText: 2013-2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Anton Kreuzkamp <anton.kreuzkamp@kdab.com>

  SPDX-License-Identifier: GPL-2.0-or-later OR LicenseRef-KDAB-GammaRay

  Licensees holding valid commercial KDAB GammaRay licenses may use this file in
  accordance with GammaRay Commercial License Agreement provided with the Software.

  Contact info@kdab.com if any conditions of this licensing are not clear to you.
*/

#include "methodsextensioninterface.h"
#include "objectbroker.h"

using namespace GammaRay;

MethodsExtensionInterface::MethodsExtensionInterface(const QString &name, QObject *parent)
    : QObject(parent)
    , m_name(name)
    , m_hasObject(false)
{
    ObjectBroker::registerObject(name, this);
}

MethodsExtensionInterface::~MethodsExtensionInterface() = default;

const QString &MethodsExtensionInterface::name() const
{
    return m_name;
}

bool MethodsExtensionInterface::hasObject() const
{
    return m_hasObject;
}

void MethodsExtensionInterface::setHasObject(bool hasObject)
{
    if (m_hasObject == hasObject)
        return;
    m_hasObject = hasObject;
    emit hasObjectChanged();
}
