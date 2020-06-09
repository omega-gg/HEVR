//=================================================================================================
/*
    Copyright (C) 2015-2020 HEVR authors. <http://omega.gg/HEVR>

    Author: Benjamin Arnaud. <http://bunjee.me> <bunjee@omega.gg>

    This file is part of libHEVR.

    - GNU Lesser General Public License Usage:
    This file may be used under the terms of the GNU Lesser General Public License version 3 as
    published by the Free Software Foundation and appearing in the LICENSE.md file included in the
    packaging of this file. Please review the following information to ensure the GNU Lesser
    General Public License requirements will be met: https://www.gnu.org/licenses/lgpl.html.
*/
//=================================================================================================

#ifndef LIBHEVR_H_
#define LIBHEVR_H_

//-------------------------------------------------------------------------------------------------
// Defines

#if defined(HEVR_LIBRARY)
#   define HEVR_EXPORT Q_DECL_EXPORT
#else
#   define HEVR_EXPORT Q_DECL_IMPORT
#endif

#if defined(OPENVR_LIBRARY)
#   define OPENVR_EXPORT Q_DECL_EXPORT
#else
#   define OPENVR_EXPORT Q_DECL_IMPORT
#endif

#endif // LIBHEVR_H_
