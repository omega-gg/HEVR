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

#ifndef VCONTROLLERCORE_H
#define VCONTROLLERCORE_H

// Sk includes
#include <WController>

// Hevr includes
#include <VDataLocal>

// Defines
#define core VControllerCore::instance()

class HEVR_EXPORT VControllerCore : public WController
{
    Q_OBJECT

private:
    VControllerCore();

private: // Variables
    VDataLocal _local;

private:
    Q_DISABLE_COPY      (VControllerCore)
    W_DECLARE_CONTROLLER(VControllerCore)
};

#endif // VCONTROLLERCORE_H
