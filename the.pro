QT += core gui widgets multimedia multimediawidgets

CONFIG += c++11


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        album_page.cpp \
        favourite_page.cpp \
        filter_page.cpp \
        library_page.cpp \
        map_page.cpp \
        player.cpp \
        thumbnailButton.cpp \
        tomeo.cpp \
        # Map Files
        Map/map.cpp \
        Map/image.cpp \
        Map/results.cpp

HEADERS += \
    album_page.h \
    favourite_page.h \
    filter_page.h \
    library_page.h \
    map_page.h \
    player.h \
    thumbnailButton.h \
    videoFile.h \
    # Map Files
    Map/map.h \
    Map/image.h \
    Map/results.h

RESOURCES += \
    map.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS +=

RESOURCES += \
    resources.qrc

