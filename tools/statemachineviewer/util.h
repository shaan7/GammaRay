/*
  This file is part of GammaRay, the Qt application inspection and
  manipulation tool.

  Copyright (C) 2010-2011 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Author: Kevin Funk <kevin.funk@kdab.com>

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

#include <QQueue>

template<class T>
class RingBuffer
{
  public:
    RingBuffer() : m_size(5) {}

    void resize(int size)
    {
      Q_ASSERT(size > 0);
      m_size = size;
      cleanup();
    }

    void enqueue(T t)
    {
      m_entries.enqueue(t);
      cleanup();
    }

    void clear()
    {
      m_entries.clear();
    }

    int size() const
    {
      return m_entries.size();
    }

    T tail() const
    {
      return m_entries.last();
    }

    QList<T> entries() const
    {
      return m_entries;
    }

  private:
    void cleanup()
    {
      while (m_entries.size() > m_size) {
        m_entries.dequeue();
      }
    }

    QQueue<T> m_entries;
    int m_size;
};