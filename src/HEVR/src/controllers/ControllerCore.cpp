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

#include "ControllerCore.h"

// Qt includes
#ifndef SK_DEPLOY
#include <QDir>
#endif

// Sk includes
#include <WControllerFile>

W_INIT_CONTROLLER(ControllerCore)

//-------------------------------------------------------------------------------------------------
// Static variables

#ifndef SK_DEPLOY
static const QString PATH_STORAGE = "/storage";
#endif

//-------------------------------------------------------------------------------------------------
// Ctor / dtor
//-------------------------------------------------------------------------------------------------

ControllerCore::ControllerCore() : WController()
{

#ifdef SK_DEPLOY
    QString path = QStandardPaths::writableLocation(QStandardPaths::DataLocation);

    wControllerFile->setPathStorage(QDir::fromNativeSeparators(path));
#else
    QString path = QDir::currentPath() + PATH_STORAGE;

    wControllerFile->setPathStorage(path);
#endif

    //---------------------------------------------------------------------------------------------
    // Log

    wControllerFile->initMessageHandler();

    qDebug("Welcome to HEVR");

    qDebug("Path storage: %s", path.C_STR);
    qDebug("Path log:     %s", wControllerFile->pathLog().C_STR);
    qDebug("Path config:  %s", _local.getFilePath().C_STR);

    //---------------------------------------------------------------------------------------------
    // DataLocal

    _local.setSaveEnabled(true);

    if (_local.load(true) == false)
    {
        qDebug("CREATE data.xml");

        _local.save();
    }
}
