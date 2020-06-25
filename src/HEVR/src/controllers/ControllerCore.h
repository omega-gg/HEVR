//=================================================================================================
/*
    Copyright (C) 2020 HEVR authors. <http://omega.gg/HEVR>

    Author: Benjamin Arnaud. <http://bunjee.me> <bunjee@omega.gg>

    This file is part of HEVR.

    - GNU General Public License Usage:
    This file may be used under the terms of the GNU General Public License version 3 as published
    by the Free Software Foundation and appearing in the LICENSE.md file included in the packaging
    of this file. Please review the following information to ensure the GNU General Public License
    requirements will be met: https://www.gnu.org/licenses/gpl.html.

    - Private License Usage:
    HEVR licensees holding valid private licenses may use this file in accordance with the private
    license agreement provided with the Software or, alternatively, in accordance with the terms
    contained in written agreement between you and HEVR authors. For further information contact us
    at contact@omega.gg.
*/
//=================================================================================================

#ifndef CONTROLLERCORE_H
#define CONTROLLERCORE_H

// Sk includes
#include <WController>

// HEVR includes
#include <DataLocal>

// Defines
#define core ControllerCore::instance()

class ControllerCore : public WController
{
    Q_OBJECT

private:
    ControllerCore();

private: // Variables
    DataLocal _local;

private:
    Q_DISABLE_COPY      (ControllerCore)
    W_DECLARE_CONTROLLER(ControllerCore)
};

#endif // CONTROLLERCORE_H
