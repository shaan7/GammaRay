/*
  pixelmetricmodel.h

  This file is part of GammaRay, the Qt application inspection and
  manipulation tool.

  Copyright (C) 2012-2022 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Author: Volker Krause <volker.krause@kdab.com>

  Licensees holding valid commercial KDAB GammaRay licenses may use this file in
  accordance with GammaRay Commercial License Agreement provided with the Software.

  Contact info@kdab.com if any conditions of this licensing are not clear to you.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef GAMMARAY_STYLEINSPECTOR_PIXELMETRICMODEL_H
#define GAMMARAY_STYLEINSPECTOR_PIXELMETRICMODEL_H

#include "abstractstyleelementmodel.h"

namespace GammaRay {
/**
 * Lists all pixel metric values of a given QStyle.
 */
class PixelMetricModel : public AbstractStyleElementModel
{
    Q_OBJECT
public:
    explicit PixelMetricModel(QObject *parent = nullptr);

    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

protected:
    QVariant doData(int row, int column, int role) const override;
    int doColumnCount() const override;
    int doRowCount() const override;
};
}

#endif // GAMMARAY_PIXELMETRICMODEL_H
