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

Application
{
    id: application

    //---------------------------------------------------------------------------------------------
    // Properties
    //---------------------------------------------------------------------------------------------

    property int index: 0

    //---------------------------------------------------------------------------------------------
    // Childs
    //---------------------------------------------------------------------------------------------

    Window
    {
        id: window

        width : st.dp1024
        height: st.dp576

        st: StyleApplication { id: st }

//#DESKTOP
        Component.onCompleted: centerWindow()
//#END

        onKeyPressed:
        {
            if (event.key == Qt.Key_Escape)
            {
                event.accepted = true;

                close();
            }
            else if (event.key == Qt.Key_F1)
            {
                event.accepted = true;

                sk.restartScript();
            }
            else if (event.key == Qt.Key_F12)
            {
                event.accepted = true;

                application.takeShot();
            }
        }

        Loader
        {
            id: loader

            anchors.fill: parent

            source: "PageMain.qml"
        }
    }
}
