TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS = src/libHEVR \
          src/HEVR-OpenVR \
          src/HEVR \

OTHER_FILES += 3rdparty.sh \
               configure.sh \
               build.sh \
               deploy.sh \
               env.sh \
               README.md \
               GPL3.md \
               LPGL3.md \
               AUTHORS.md \
               .azure-pipelines.yml \
               content/generate.sh \
               content/Main.qml \
               include/generate.sh \
               dist/changes/1.0.0.md \
