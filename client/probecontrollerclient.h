/*
  probecontrollerclient.h

  This file is part of GammaRay, the Qt application inspection and manipulation tool.

  SPDX-FileCopyrightText: 2013-2022 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Volker Krause <volker.krause@kdab.com>

  SPDX-License-Identifier: GPL-2.0-or-later OR LicenseRef-KDAB-GammaRay

  Licensees holding valid commercial KDAB GammaRay licenses may use this file in
  accordance with GammaRay Commercial License Agreement provided with the Software.

  Contact info@kdab.com if any conditions of this licensing are not clear to you.
*/

#ifndef GAMMARAY_PROBECONTROLLERCLIENT_H
#define GAMMARAY_PROBECONTROLLERCLIENT_H

#include <common/probecontrollerinterface.h>

namespace GammaRay {
class ProbeControllerClient : public ProbeControllerInterface
{
    Q_OBJECT
    Q_INTERFACES(GammaRay::ProbeControllerInterface)
public:
    explicit ProbeControllerClient(QObject *parent = nullptr);

    void detachProbe() override;
    void quitHost() override;
};
}

#endif // GAMMARAY_PROBECONTROLLERCLIENT_H
