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

#include "VDataLocal.h"

// Sk includes
#include <WControllerFile>

//=================================================================================================
// VDataLocal
//=================================================================================================

/* explicit */ VDataLocal::VDataLocal(QObject * parent) : WLocalObject(parent) {}

//-------------------------------------------------------------------------------------------------
// WLocalObject reimplementation
//-------------------------------------------------------------------------------------------------

/* Q_INVOKABLE virtual */ bool VDataLocal::load(bool)
{
    return true;
}

/* Q_INVOKABLE virtual */ QString VDataLocal::getFilePath() const
{
    return WControllerFile::applicationPath("data.xml");
}

//-------------------------------------------------------------------------------------------------
// Protected WLocalObject reimplementation
//-------------------------------------------------------------------------------------------------

/* virtual */ WAbstractThreadAction * VDataLocal::onLoad(const QString &)
{
    return NULL;
}