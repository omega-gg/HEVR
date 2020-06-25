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

#include "ControllerCore.h"

// Qt includes
#include <QDir>

// Sk includes
#include <WControllerFile>
#include <WControllerView>
#include <WControllerDeclarative>
#include <WApplication>
#include <WView>
#include <WViewResizer>
#include <WViewDrag>
#include <WWindow>
#include <WDeclarativeApplication>
#include <WDeclarativeBorders>
#include <WDeclarativeImage>
#include <WDeclarativeImageSvg>
#include <WImageColorFilter>

W_INIT_CONTROLLER(ControllerCore)

//-------------------------------------------------------------------------------------------------
// Static variables

static const QString CORE_VERSION = "1.0.0-0";

//-------------------------------------------------------------------------------------------------
// Ctor / dtor
//-------------------------------------------------------------------------------------------------

ControllerCore::ControllerCore() : WController()
{

#ifdef SK_DEPLOY
    QString path = WControllerFile::pathWritable();

    wControllerFile->setPathStorage(QDir::fromNativeSeparators(path));
#else
    QString path = QDir::currentPath();

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

    sk->setVersion(CORE_VERSION);

    //---------------------------------------------------------------------------------------------
    // QML
    //---------------------------------------------------------------------------------------------

    qmlRegisterUncreatableType<WControllerDeclarative>("Sky", 1,0, "Sk", "Sk is not creatable");

    qmlRegisterType<WDeclarativeApplication>("Sky", 1,0, "Application");

    qmlRegisterUncreatableType<WView>("Sky", 1,0, "View", "View is abstract");

    qmlRegisterType<WViewResizer>("Sky", 1,0, "ViewResizer");
    qmlRegisterType<WViewDrag>   ("Sky", 1,0, "ViewDrag");

    qmlRegisterType<WWindow>("Sky", 1,0, "BaseWindow");

    qmlRegisterType<WImageColorFilter>("Sky", 1,0, "ImageColorFilter");

    qmlRegisterType<WDeclarativeBorders>("Sky", 1,0, "Borders");

    qmlRegisterType<WDeclarativeMouseArea>("Sky", 1,0, "MouseArea");

    qmlRegisterType<WDeclarativeGradient>    ("Sky", 1,0, "ScaleGradient");
    qmlRegisterType<WDeclarativeGradientStop>("Sky", 1,0, "ScaleGradientStop");

    qmlRegisterType<WDeclarativeImage>     ("Sky", 1,0, "Image");
    qmlRegisterType<WDeclarativeImageScale>("Sky", 1,0, "ImageScale");
    qmlRegisterType<WDeclarativeImageSvg>  ("Sky", 1,0, "ImageSvg");

#ifdef QT_4
    qmlRegisterType<WDeclarativeImageSvgScale>("Sky", 1,0, "ImageSvgScale");
#endif

    qmlRegisterUncreatableType<WImageFilter>("Sky", 1,0, "ImageFilter", "ImageFilter is abstract");

    qmlRegisterType<WImageColorFilter>("Sky", 1,0, "ImageColorFilter");

    qmlRegisterUncreatableType<WDeclarativeKeyEvent>("Sky", 1,0, "DeclarativeKeyEvent",
                                                     "DeclarativeKeyEvent is not creatable");

    //---------------------------------------------------------------------------------------------
    // Context

    wControllerDeclarative->setContextProperty("sk", sk);
}
