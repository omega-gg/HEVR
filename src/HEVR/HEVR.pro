SK = $$_PRO_FILE_PWD_/../../../Sky

SK_CORE = $$SK/src/SkCore/src
SK_GUI  = $$SK/src/SkGui/src

HEVR=$$_PRO_FILE_PWD_/../..

TARGET = HEVR

!android:DESTDIR = $$HEVR/bin

contains(QT_MAJOR_VERSION, 4) {
    QT += opengl declarative network xml xmlpatterns svg
} else {
    QT += opengl quick network xml xmlpatterns svg

    win32:QT += winextras

    unix:!macx:!android:QT += dbus x11extras

    android:QT += androidextras
}

# C++17
contains(QT_MAJOR_VERSION, 4) {
    QMAKE_CXXFLAGS += -std=c++1z
} else {
    CONFIG += c++1z
}

DEFINES += SK_CORE_LIBRARY SK_GUI_LIBRARY

contains(QT_MAJOR_VERSION, 4) {
    DEFINES += QT_4

    CONFIG(release, debug|release) {

        win32:DEFINES += SK_WIN_NATIVE
    }
} else {
    DEFINES += QT_LATEST #SK_SOFTWARE

    win32:DEFINES += SK_WIN_NATIVE
}

android {
    DEFINES += SK_MOBILE
} else {
    DEFINES += SK_DESKTOP
}

deploy|android {
    DEFINES += SK_DEPLOY

    RESOURCES = $$HEVR/dist/HEVR.qrc
}

unix:QMAKE_LFLAGS += "-Wl,-rpath,'\$$ORIGIN'"

include(src/global/global.pri)
include(src/controllers/controllers.pri)
include(src/kernel/kernel.pri)
include(src/io/io.pri)
include(src/thread/thread.pri)
include(src/image/image.pri)
include(src/graphicsview/graphicsview.pri)
include(src/declarative/declarative.pri)

include(src/3rdparty/qtsingleapplication/qtsingleapplication.pri)

INCLUDEPATH += $$SK/include/SkCore \
               $$SK/include/SkGui \
               $$HEVR/include/HEVR

contains(QT_MAJOR_VERSION, 5) {
    INCLUDEPATH += $$SK/include/Qt5 \
                   $$SK/include/Qt5/QtCore \
                   $$SK/include/Qt5/QtGui \
                   $$SK/include/Qt5/QtQml \
                   $$SK/include/Qt5/QtQuick
}

unix:!macx:!android:contains(QT_MAJOR_VERSION, 5) {
    INCLUDEPATH += $$SK/include/Qt5/QtDBus
}

unix:contains(QT_MAJOR_VERSION, 4) {
    INCLUDEPATH += $$SK/include/Qt4/QtCore \
                   $$SK/include/Qt4/QtGui \
                   $$SK/include/Qt4/QtDeclarative
}

# Windows dependency for ShellExecuteA and PostMessage
win32-msvc*:LIBS += shell32.lib User32.lib

unix:!macx:!android:contains(QT_MAJOR_VERSION, 4) {
    LIBS += -lX11
}

macx:ICON = $$HEVR/dist/icon.icns

RC_FILE = $$HEVR/dist/HEVR.rc

android {
    ANDROID_PACKAGE_SOURCE_DIR = $$HEVR/dist/android

    DISTFILES += $$ANDROID_PACKAGE_SOURCE_DIR/AndroidManifest.xml
}
