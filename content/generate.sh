#!/bin/sh
set -e

#--------------------------------------------------------------------------------------------------
# Settings
#--------------------------------------------------------------------------------------------------

Sky="../../Sky"

SkyBase="$Sky/src/SkyBase"

#--------------------------------------------------------------------------------------------------

content="../content"

bin="../bin"

#--------------------------------------------------------------------------------------------------
# Syntax
#--------------------------------------------------------------------------------------------------

if [ $# != 1 -a $# != 2 ] \
   || \
   [ $1 != "win32" -a $1 != "win64" -a $1 != "win32-msvc" -a $1 != "win64-msvc" -a \
     $1 != "macOS" -a $1 != "linux" -a $1 != "android" ] \
   || \
   [ $# = 2 -a "$2" != "all" -a "$2" != "deploy" -a "$2" != "clean" ]; then

    echo "Usage: generate <win32 | win64 | win32-msvc | win64-msvc | macOS | linux | android>"
    echo "                [all | deploy | clean]"

    exit 1
fi

#--------------------------------------------------------------------------------------------------
# Configuration
#--------------------------------------------------------------------------------------------------

if [ $1 = "win32" -o $1 = "win64" -o $1 = "win32-msvc" -o $1 = "win64-msvc" ]; then

    os="windows"
else
    os="default"
fi

if [ "$2" = "deploy" -o $1 = "android" ]; then

    path="qrc"
else
    path="$bin"
fi

cd ../dist

#--------------------------------------------------------------------------------------------------
# Clean
#--------------------------------------------------------------------------------------------------

if [ "$2" = "clean" ]; then

    echo "CLEANING"

    rm -f  $bin/*.qml
    rm -rf $bin/pictures

    rm -f  qrc/*.qml
    rm -rf qrc/pictures

    exit 0
fi

#--------------------------------------------------------------------------------------------------
# QML
#--------------------------------------------------------------------------------------------------

echo "COPYING QML"

cp $content/*.qml $path

#--------------------------------------------------------------------------------------------------
# Content
#--------------------------------------------------------------------------------------------------

if [ "$2" = "all" -o "$2" = "deploy" -o $1 = "android"  ]; then

    echo "COPYING pictures"

    #cp -r $content/pictures $path
fi

#--------------------------------------------------------------------------------------------------
# Icon
#--------------------------------------------------------------------------------------------------

if [ $2 = "macOS" ]; then

    echo "GENERATING icon"

    mkdir icon.iconset

    cp pictures/icon/16.png  icon.iconset/icon_16x16.png
    cp pictures/icon/24.png  icon.iconset/icon_24x24.png
    cp pictures/icon/32.png  icon.iconset/icon_32x32.png
    cp pictures/icon/48.png  icon.iconset/icon_48x48.png
    cp pictures/icon/64.png  icon.iconset/icon_64x64.png
    cp pictures/icon/128.png icon.iconset/icon_128x128.png
    cp pictures/icon/256.png icon.iconset/icon_256x256.png
    cp pictures/icon/512.png icon.iconset/icon_512x512.png

    iconutil -c icns icon.iconset

    rm -rf icon.iconset
fi

echo ""

#--------------------------------------------------------------------------------------------------
# Deployer
#--------------------------------------------------------------------------------------------------

if [ $os = "windows" ]; then

    version=2.11
else
    version=2.7
fi

if [ $os = "windows" ]; then

    defines="DESKTOP WINDOWS"

elif [ $2 = "macOS" ]; then

    defines="DESKTOP MAC"

elif [ $1 = "linux" ]; then

    defines="DESKTOP LINUX"
else
    defines="ANDROID"
fi

"$Sky"/deploy/deployer $path $version HEVR.qrc "$defines" \
"$SkyBase"/Style.qml \
"$SkyBase"/Window.qml \
"$SkyBase"/RectangleBorders.qml \
"$SkyBase"/BaseButton.qml \
