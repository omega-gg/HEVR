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

#include "VControllerCore.h"

#ifndef HEVR_NO_CONTROLLERCORE

W_INIT_CONTROLLER(VControllerCore)

//-------------------------------------------------------------------------------------------------
// Private
//-------------------------------------------------------------------------------------------------

#include "VControllerCore_p.h"

VControllerCorePrivate::VControllerCorePrivate(VControllerCore * p) : WControllerPrivate(p) {}

void VControllerCorePrivate::init()
{
    qDebug("Welcome to HEVR");
}

//-------------------------------------------------------------------------------------------------
// Ctor / dtor
//-------------------------------------------------------------------------------------------------

VControllerCore::VControllerCore() : WController(new VControllerCorePrivate(this)) {}

//-------------------------------------------------------------------------------------------------
// Initialize
//-------------------------------------------------------------------------------------------------

/* virtual */ void VControllerCore::init()
{
    Q_D(VControllerCore); d->init();
}


#endif // HEVR_NO_CONTROLLERCORE
