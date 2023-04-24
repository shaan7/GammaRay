/*
  toolmanagerclient.cpp

  This file is part of GammaRay, the Qt application inspection and manipulation tool.

  SPDX-FileCopyrightText: 2013-2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Anton Kreuzkamp <anton.kreuzkamp@kdab.com>

  SPDX-License-Identifier: GPL-2.0-or-later OR LicenseRef-KDAB-GammaRay

  Licensees holding valid commercial KDAB GammaRay licenses may use this file in
  accordance with GammaRay Commercial License Agreement provided with the Software.

  Contact info@kdab.com if any conditions of this licensing are not clear to you.
*/

#include "toolmanagerclient.h"

#include <common/endpoint.h>

using namespace GammaRay;

ToolManagerClient::ToolManagerClient(QObject *parent)
    : ToolManagerInterface(parent)
{
}

void ToolManagerClient::selectObject(const ObjectId &id, const QString &toolId)
{
    Endpoint::instance()->invokeObject(objectName(), "selectObject",
                                       QVariantList() << QVariant::fromValue(id) << toolId);
}

void ToolManagerClient::requestToolsForObject(const ObjectId &id)
{
    Endpoint::instance()->invokeObject(objectName(), "requestToolsForObject",
                                       QVariantList() << QVariant::fromValue(id));
}

void ToolManagerClient::requestAvailableTools()
{
    Endpoint::instance()->invokeObject(objectName(), "requestAvailableTools");
}
