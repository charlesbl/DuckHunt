TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    affichage.cpp \
    canard.cpp \
    niveau.cpp

DISTFILES += \
    duck_hunt.ttf \
    backGame.png \
    backGameBlit.png \
    duck.png \
    hit.png \
    menu.png \
    points.png \
    shot.png \
    viseur.png

HEADERS += \
    affichage.h \
    canard.h \
    niveau.h

LIBS+=`sdl-config --libs` -lSDL_image -lSDL_ttf
INCLUDEPATH+=-I/usr/include/SDL/
