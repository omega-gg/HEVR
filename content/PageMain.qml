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

Item
{
    //---------------------------------------------------------------------------------------------
    // Childs
    //---------------------------------------------------------------------------------------------

//#DESKTOP
    ViewDrag
    {
        anchors.left : parent.left
        anchors.right: parent.right
        anchors.top  : parent.top

        height: st.dp32

        onDoubleClicked: buttonsWindow.onMaximize()
    }

    ButtonsWindow
    {
        id: buttonsWindow

        anchors.top  : parent.top
        anchors.right: parent.right
    }
//#END

    BarSide
    {
        // NOTE: We have to specify anchors to have proper margins
        anchors.left: parent.left
        anchors.top : parent.top
    }
}
