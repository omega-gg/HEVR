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

#ifndef VDATALOCAL_P_H
#define VDATALOCAL_P_H

/*  W A R N I N G
    -------------

    This file is not part of the HEVR API. It exists purely as an
    implementation detail. This header file may change from version to
    version without notice, or even be removed.

    We mean it.
*/

// Hevr includes
#include <Hevr>

// Private includes
#include <private/WLocalObject_p>

#ifndef OPENVR_NO_DATALOCAL

class OPENVR_EXPORT VDataLocalPrivate : public WLocalObjectPrivate
{
public:
    VDataLocalPrivate(VDataLocal * p);

    void init();

protected:
    W_DECLARE_PUBLIC(VDataLocal)
};

#endif // OPENVR_NO_DATALOCAL
#endif // VDATALOCAL_P_H
