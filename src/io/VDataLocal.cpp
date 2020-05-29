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

#ifndef HEVR_NO_DATALOCAL

// Sk includes
#include <WControllerFile>

//-------------------------------------------------------------------------------------------------
// Private
//-------------------------------------------------------------------------------------------------

#include "VDataLocal_p.h"

VDataLocalPrivate::VDataLocalPrivate(VDataLocal * p) : WLocalObjectPrivate(p) {}

void VDataLocalPrivate::init() {}

//-------------------------------------------------------------------------------------------------
// Ctor / dtor
//-------------------------------------------------------------------------------------------------

/* explicit */ VDataLocal::VDataLocal(QObject * parent)
    : WLocalObject(new VDataLocalPrivate(this), parent)
{
    Q_D(VDataLocal); d->init();
}

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

#endif // HEVR_NO_DATALOCAL
