//=================================================================================================
/*
    Copyright (C) 2015-2020 HEVR authors. <http://omega.gg/HEVR>

    Author: Benjamin Arnaud. <http://bunjee.me> <bunjee@omega.gg>

    This file is part of HEVR.

    - GNU Lesser General Public License Usage:
    This file may be used under the terms of the GNU Lesser General Public License version 3 as
    published by the Free Software Foundation and appearing in the LICENSE.md file included in the
    packaging of this file. Please review the following information to ensure the GNU Lesser
    General Public License requirements will be met: https://www.gnu.org/licenses/lgpl.html.
*/
//=================================================================================================

#ifndef DATALOCAL_H
#define DATALOCAL_H

// Sk includes
#include <WLocalObject>

class DataLocal : public WLocalObject
{
    Q_OBJECT

public:
    explicit DataLocal(QObject * parent = NULL);

public: // WLocalObject reimplementation
    /* Q_INVOKABLE virtual */ bool load(bool instant = false);

    /* Q_INVOKABLE virtual */ QString getFilePath() const;

private:
    Q_DISABLE_COPY(DataLocal)
};

#endif // DATALOCAL_H
