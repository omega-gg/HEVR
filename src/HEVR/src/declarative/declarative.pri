# Declarative module

HEADERS += $$SK_GUI/declarative/WDeclarativeApplication.h \
           $$SK_GUI/declarative/WDeclarativeItem.h \
           $$SK_GUI/declarative/WDeclarativeItem_p.h \
           $$SK_GUI/declarative/WDeclarativeMouseArea.h \
           $$SK_GUI/declarative/WDeclarativeMouseArea_p.h \
           $$SK_GUI/declarative/WDeclarativeBorders.h \
           $$SK_GUI/declarative/WDeclarativeImageBase.h \
           $$SK_GUI/declarative/WDeclarativeImageBase_p.h \
           $$SK_GUI/declarative/WDeclarativeImage.h \
           $$SK_GUI/declarative/WDeclarativeImage_p.h \
           $$SK_GUI/declarative/WDeclarativeImageSvg.h \
           $$SK_GUI/declarative/WDeclarativeImageSvg_p.h \

contains(QT_MAJOR_VERSION, 5): HEADERS += $$SK_GUI/declarative/WDeclarativeTexture.h \
                                          $$SK_GUI/declarative/WDeclarativeTexture_p.h \

SOURCES += $$SK_GUI/declarative/WDeclarativeApplication.cpp \
           $$SK_GUI/declarative/WDeclarativeItem.cpp \
           $$SK_GUI/declarative/WDeclarativeMouseArea.cpp \
           $$SK_GUI/declarative/WDeclarativeBorders.cpp \
           $$SK_GUI/declarative/WDeclarativeImageBase.cpp \
           $$SK_GUI/declarative/WDeclarativeImage.cpp \
           $$SK_GUI/declarative/WDeclarativeImageSvg.cpp \

contains(QT_MAJOR_VERSION, 5): SOURCES += $$SK_GUI/declarative/WDeclarativeTexture.cpp \
