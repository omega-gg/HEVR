//=================================================================================================
/*
    Copyright (C) 2020 HEVR authors. <http://omega.gg/HEVR>

    Author: Benjamin Arnaud. <http://bunjee.me> <bunjee@omega.gg>

    This file is part of libHEVR.

    - GNU Lesser General Public License Usage:
    This file may be used under the terms of the GNU Lesser General Public License version 3 as
    published by the Free Software Foundation and appearing in the LICENSE.md file included in the
    packaging of this file. Please review the following information to ensure the GNU Lesser
    General Public License requirements will be met: https://www.gnu.org/licenses/lgpl.html.

    - Private License Usage:
    HEVR licensees holding valid private licenses may use this file in accordance with the private
    license agreement provided with the Software or, alternatively, in accordance with the terms
    contained in written agreement between you and HEVR authors. For further information contact us
    at contact@omega.gg.
*/
//=================================================================================================

#include "VControllerHevr.h"

#ifndef HEVR_NO_CONTROLLERHEVR

W_INIT_CONTROLLER(VControllerHevr)

//-------------------------------------------------------------------------------------------------
// Private
//-------------------------------------------------------------------------------------------------

#include "VControllerHevr_p.h"

VControllerHevrPrivate::VControllerHevrPrivate(VControllerHevr * p) : WControllerPrivate(p) {}

void VControllerHevrPrivate::init() {}

//-------------------------------------------------------------------------------------------------
// Ctor / dtor
//-------------------------------------------------------------------------------------------------

VControllerHevr::VControllerHevr() : WController(new VControllerHevrPrivate(this)) {}

//-------------------------------------------------------------------------------------------------
// Initialize
//-------------------------------------------------------------------------------------------------

/* virtual */ void VControllerHevr::init()
{
    Q_D(VControllerHevr); d->init();
}

#endif // HEVR_NO_CONTROLLERHEVR
