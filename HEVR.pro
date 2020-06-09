TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS = src/HEVR \
          src/libHEVR \
          src/OpenVR \

OTHER_FILES += 3rdparty.sh \
               configure.sh \
               build.sh \
               deploy.sh \
               README.md \
               GPL3.md \
               LPGL3.md \
               AUTHORS.md \
               .azure-pipelines.yml \
               content/generate.sh \
               content/Main.qml \
               include/generate.sh \
               dist/changes/1.0.0.md \
