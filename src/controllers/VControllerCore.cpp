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

#include "VControllerCore.h"

// Qt includes
#ifndef SK_DEPLOY
#include <QDir>
#endif

// Sk includes
#include <WControllerFile>

#ifndef HEVR_NO_CONTROLLERCORE

W_INIT_CONTROLLER(VControllerCore)

//-------------------------------------------------------------------------------------------------
// Static variables

#ifndef SK_DEPLOY
static const QString PATH_STORAGE = "/storage";
#endif

//-------------------------------------------------------------------------------------------------
// Private
//-------------------------------------------------------------------------------------------------

#include "VControllerCore_p.h"

VControllerCorePrivate::VControllerCorePrivate(VControllerCore * p) : WControllerPrivate(p) {}

void VControllerCorePrivate::init()
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
    qDebug("Path config:  %s", local.getFilePath().C_STR);

    //---------------------------------------------------------------------------------------------
    // DataLocal

    local.setSaveEnabled(true);

    if (local.load(true) == false)
    {
        qDebug("CREATE data.xml");

        local.save();
    }
}

//-------------------------------------------------------------------------------------------------
// Ctor / dtor
//-------------------------------------------------------------------------------------------------

VControllerCore::VControllerCore() : WController(new VControllerCorePrivate(this)) {}

//-------------------------------------------------------------------------------------------------
// Initialize
//-------------------------------------------------------------------------------------------------

/* virtual */ void VControllerCore::init()
{
    Q_D(VControllerCore); d->init();
}

#endif // HEVR_NO_CONTROLLERCORE
