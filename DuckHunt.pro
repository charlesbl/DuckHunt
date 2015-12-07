TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    canard.cpp \
    niveau.cpp \
    affichage.cpp

LIBS += `sdl-config --libs` -lSDL_image -lSDL_ttf
INCLUDEPATH += -I/usr/include/SDL/

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    canard.h \
    niveau.h \
    affichage.h

OTHER_FILES += \
    viseur.png \
    shot.png \
    points.png \
    menu.png \
    hit.png \
    duck.png \
    backGameBlit.png \
    backGame.png \
    duck_hunt.ttf

