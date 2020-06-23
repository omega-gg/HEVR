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
        anchors.fill: parent

        onDoubleClicked: buttonsWindow.onMaximize()
    }

    ButtonsWindow
    {
        id: buttonsWindow

        anchors.top  : parent.top
        anchors.right: parent.right
    }
//#END

    ButtonTouch
    {
        anchors.left: parent.left
        anchors.top : parent.top

        anchors.margins: st.dp2

        text: qsTr("HEVR Client")
    }
}
