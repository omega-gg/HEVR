//=================================================================================================
/*
    Copyright (C) 2015-2020 HEVR authors. <http://omega.gg/HEVR>

    Author: Benjamin Arnaud. <http://bunjee.me> <bunjee@omega.gg>

    This file is part of HEVR.

    - GNU General Public License Usage:
    This file may be used under the terms of the GNU General Public License version 3 as published
    by the Free Software Foundation and appearing in the LICENSE.md file included in the packaging
    of this file. Please review the following information to ensure the GNU General Public License
    requirements will be met: https://www.gnu.org/licenses/gpl.html.
*/
//=================================================================================================

import QtQuick 1.0
import Sky     1.0

Column
{
    //---------------------------------------------------------------------------------------------
    // Settings
    //---------------------------------------------------------------------------------------------

    anchors.margins: spacing

    spacing: st.dp2

    //---------------------------------------------------------------------------------------------
    // Childs
    //---------------------------------------------------------------------------------------------

    ButtonTouchIcon
    {
        width: st.dp64

        margins: st.dp12

        checked: (index == 0)

        icon: st.icon_home

        onPressed: index = 0
    }

    ButtonTouchIcon
    {
        width: st.dp64

        margins: st.dp12

        checked: (index == 1)

        icon: st.icon_settings

        onPressed: index = 1
    }

    ButtonTouchIcon
    {
        width: st.dp64

        margins: st.dp14

        checked: (index == 2)

        icon: st.icon_about

        onPressed: index = 2
    }
}
