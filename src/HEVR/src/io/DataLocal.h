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

#ifndef VDATALOCAL_H
#define VDATALOCAL_H

// Sk includes
#include <WLocalObject>

// Forward declarations
class VDataLocalPrivate;

class VDataLocal : public WLocalObject
{
    Q_OBJECT

public:
    explicit VDataLocal(QObject * parent = NULL);

public: // WLocalObject reimplementation
    /* Q_INVOKABLE virtual */ QString getFilePath() const;

protected: // WLocalObject reimplementation
    /* virtual */ WAbstractThreadAction * onSave(const QString & path);
    /* virtual */ WAbstractThreadAction * onLoad(const QString & path);

private:
    W_DECLARE_PRIVATE(VDataLocal)
};

#endif // VDATALOCAL_H
