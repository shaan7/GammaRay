/*
  widgetattributetab.h

  This file is part of GammaRay, the Qt application inspection and manipulation tool.

  SPDX-FileCopyrightText: 2016-2022 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Volker Krause <volker.krause@kdab.com>

  SPDX-License-Identifier: GPL-2.0-or-later OR LicenseRef-KDAB-GammaRay

  Licensees holding valid commercial KDAB GammaRay licenses may use this file in
  accordance with GammaRay Commercial License Agreement provided with the Software.

  Contact info@kdab.com if any conditions of this licensing are not clear to you.
*/

#ifndef GAMMARAY_WIDGETATTRIBUTETAB_H
#define GAMMARAY_WIDGETATTRIBUTETAB_H

#include <QScopedPointer>
#include <QWidget>

namespace GammaRay {
class PropertyWidget;

namespace Ui {
class WidgetAttributeTab;
}

class WidgetAttributeTab : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetAttributeTab(PropertyWidget *parent = nullptr);
    ~WidgetAttributeTab() override;

private:
    QScopedPointer<Ui::WidgetAttributeTab> ui;
};
}

#endif // GAMMARAY_WIDGETATTRIBUTETAB_H
