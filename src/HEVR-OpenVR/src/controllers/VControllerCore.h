//=================================================================================================
/*
    Copyright (C) 2020 HEVR authors. <http://omega.gg/HEVR>

    Author: Benjamin Arnaud. <http://bunjee.me> <bunjee@omega.gg>

    This file is part of HEVR-OpenVR.

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

#ifndef VCONTROLLERCORE_H
#define VCONTROLLERCORE_H

// Sk includes
#include <WController>

// HEVR includes
#include <Hevr>

#ifndef OPENVR_NO_CONTROLLERCORE

// Forward declarations
class VControllerCorePrivate;

// Defines
#define core VControllerCore::instance()

class OPENVR_EXPORT VControllerCore : public WController
{
    Q_OBJECT

private:
    VControllerCore();

protected: // Initialize
    /* virtual */ void init();

private:
    W_DECLARE_PRIVATE   (VControllerCore)
    W_DECLARE_CONTROLLER(VControllerCore)
};

#endif // OPENVR_NO_CONTROLLERCORE
#endif // VCONTROLLERCORE_H
