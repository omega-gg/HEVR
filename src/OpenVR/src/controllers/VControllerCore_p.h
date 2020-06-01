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

#ifndef VCONTROLLERCORE_P_H
#define VCONTROLLERCORE_P_H

/*  W A R N I N G
    -------------

    This file is not part of the HEVR API. It exists purely as an
    implementation detail. This header file may change from version to
    version without notice, or even be removed.

    We mean it.
*/

// OpenVR includes
#include <VDataLocal>

// Private includes
#include <private/WController_p>

#ifndef OPENVR_NO_CONTROLLERCORE

class OPENVR_EXPORT VControllerCorePrivate : public WControllerPrivate
{
public:
    VControllerCorePrivate(VControllerCore * p);

    void init();

public: // Variables
    VDataLocal local;

protected:
    W_DECLARE_PUBLIC(VControllerCore)
};

#endif // OPENVR_NO_CONTROLLERCORE
#endif // VCONTROLLERCORE_P_H
