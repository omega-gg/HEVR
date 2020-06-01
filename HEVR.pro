TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS = src/HEVR \
          src/OpenVR \

OTHER_FILES += 3rdparty.sh \
               configure.sh \
               build.sh \
               deploy.sh \
               README.md \
               LICENSE.md \
               AUTHORS.md \
               .azure-pipelines.yml \
               include/generate.sh \
               dist/changes/1.0.0.md \
