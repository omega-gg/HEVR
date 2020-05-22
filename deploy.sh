#!/bin/sh
set -e

#--------------------------------------------------------------------------------------------------
# Settings
#--------------------------------------------------------------------------------------------------

Sky="../Sky"

#--------------------------------------------------------------------------------------------------
# Syntax
#--------------------------------------------------------------------------------------------------

if [ $# != 1 -a $# != 2 ] \
   || \
   [ $1 != "win32" -a $1 != "win64" -a $1 != "win32-msvc" -a $1 != "win64-msvc" -a \
     $1 != "macOS" -a $1 != "linux" ] \
   || \
   [ $# = 2 -a "$2" != "lib" -a "$2" != "clean" ]; then

    echo "Usage: deploy <win32 | win64 | win32-msvc | win64-msvc | macOS | linux>"
    echo "              [lib | clean]"

    exit 1
fi

#--------------------------------------------------------------------------------------------------
# Configuration
#--------------------------------------------------------------------------------------------------

if [ $1 = "win32" -o $1 = "win64" -o $1 = "win32-msvc" -o $1 = "win64-msvc" ]; then

    os="windows"

    if [ $1 = "win32" -o $1 = "win64" ]; then

        compiler="mingw"
    else
        compiler="default"
    fi
else
    os="default"

    compiler="default"
fi

#--------------------------------------------------------------------------------------------------
# Clean
#--------------------------------------------------------------------------------------------------

echo "CLEANING"

rm -rf deploy/*

touch deploy/.gitignore

if [ "$2" = "clean" ]; then

    exit 0
fi

echo ""

#--------------------------------------------------------------------------------------------------
# Sky
#--------------------------------------------------------------------------------------------------

echo "DEPLOYING Sky"
echo "-------------"

cd "$Sky"

sh deploy.sh qt5 $1 tools

cd -

path="$Sky/deploy"

if [ $os = "windows" ]; then

    if [ $compiler = "mingw" ]; then

        cp "$path"/libgcc_s_*-1.dll    deploy
        cp "$path"/libstdc++-6.dll     deploy
        cp "$path"/libwinpthread-1.dll deploy
    fi

    cp "$path"/Qt5Core.dll        deploy
    cp "$path"/Qt5Network.dll     deploy
    cp "$path"/Qt5Xml.dll         deploy
    cp "$path"/Qt5XmlPatterns.dll deploy

elif [ $1 = "macOS" ]; then

    # FIXME Qt 5.14 macOS: We have to copy qt.conf to avoid a segfault.
    cp "$path"/qt.conf deploy

    cp "$path"/QtCore.dylib        deploy
    cp "$path"/QtNetwork.dylib     deploy
    cp "$path"/QtXml.dylib         deploy
    cp "$path"/QtXmlPatterns.dylib deploy

elif [ $1 = "linux" ]; then

    cp "$path"/libQt5Core.so.5        deploy
    cp "$path"/libQt5Network.so.5     deploy
    cp "$path"/libQt5Xml.so.5         deploy
    cp "$path"/libQt5XmlPatterns.so.5 deploy
fi

echo "-------------"
echo ""

#--------------------------------------------------------------------------------------------------
# ALVR2
#--------------------------------------------------------------------------------------------------

echo "COPYING ALVR2"

if [ $os = "windows" ]; then

    if [ "$2" = "lib" ]; then

        cp lib/*ALVR2.a deploy

        cp lib/ALVR2.dll deploy
    else
        cp bin/ALVR2.exe deploy
    fi

elif [ $1 = "macOS" ]; then

    if [ "$2" = "lib" ]; then

        cp lib/libALVR2.dylib deploy
    else
        cp bin/ALVR2 deploy

        cd deploy

        #----------------------------------------------------------------------------------------------
        # Qt

        install_name_tool -change @rpath/QtCore.framework/Versions/5/QtCore \
                                  @loader_path/QtCore.dylib ALVR2

        install_name_tool -change @rpath/QtNetwork.framework/Versions/5/QtNetwork \
                                  @loader_path/QtNetwork.dylib ALVR2

        install_name_tool -change @rpath/QtQml.framework/Versions/5/QtQml \
                                  @loader_path/QtQml.dylib ALVR2

        install_name_tool -change @rpath/QtXml.framework/Versions/5/QtXml \
                                  @loader_path/QtXml.dylib ALVR2

        install_name_tool -change @rpath/QtXmlPatterns.framework/Versions/5/QtXmlPatterns \
                                  @loader_path/QtXmlPatterns.dylib ALVR2

        #----------------------------------------------------------------------------------------------

        cd -
    fi

elif [ $1 = "linux" ]; then

    if [ "$2" = "lib" ]; then

        cp lib/libALVR2.so deploy
    else
        cp bin/ALVR2 deploy
    fi
fi
