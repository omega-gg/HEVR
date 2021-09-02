SK = $$_PRO_FILE_PWD_/../../../Sky

SK_CORE = $$SK/src/SkCore/src

HEVR=$$_PRO_FILE_PWD_/../..

TARGET = HEVR-OpenVR

DESTDIR = $$HEVR/lib

TEMPLATE = lib

win32:CONFIG += dll

contains(QT_MAJOR_VERSION, 4) {
    QT += network script xml xmlpatterns
} else {
    QT += network xml xmlpatterns
}

# C++17
contains(QT_MAJOR_VERSION, 4) {
    QMAKE_CXXFLAGS += -std=c++1z
} else {
    CONFIG += c++1z
}

DEFINES += SK_CONSOLE SK_NO_QML SK_CORE_LIBRARY HEVR_LIBRARY OPENVR_LIBRARY

contains(QT_MAJOR_VERSION, 4) {
    DEFINES += QT_4
} else {
    DEFINES += QT_LATEST
}

android {
    DEFINES += SK_MOBILE
} else {
    DEFINES += SK_DESKTOP
}

deploy|android {
    DEFINES += SK_DEPLOY
}

unix:QMAKE_LFLAGS += "-Wl,-rpath,'\$$ORIGIN'"

include(src/global/global.pri)
include(src/controllers/controllers.pri)
include(src/kernel/kernel.pri)
include(src/io/io.pri)
include(src/thread/thread.pri)

include(src/3rdparty/qtsingleapplication/qtsingleapplication.pri)

INCLUDEPATH += $$SK/include/SkCore \
               $$HEVR/include/libHEVR \
               $$HEVR/include/HEVR-OpenVR

# Windows dependency for ShellExecuteA
win32-msvc*:LIBS += shell32.lib
