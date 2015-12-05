#include <iostream>
#include <SDL/SDL.h>
#include <niveau.h>
#include <canard.h>
#include <cstdlib>
#include <ctime>

extern int nbAmmo;

void initNiveau(Niveau &niv)
{
    nbAmmo = 3;
    int x;
    int y;
    genRandomPos(x,y);
    initCanard(niv.cNoir, x, y, 0);
    genRandomPos(x,y);
    initCanard(niv.cMarron, x, y, 1);
    genRandomPos(x,y);
    initCanard(niv.cBleu, x, y, 2);

    killRandomCan(niv);
}

void updateNiv(SDL_Surface *screen, SDL_Surface *duck, Niveau &niv)
{
    updateCan(screen, duck, niv.cNoir);
    updateCan(screen, duck, niv.cMarron);
    updateCan(screen, duck, niv.cBleu);
    if((niv.cNoir.isDead && niv.cMarron.isDead && niv.cBleu.isDead) || (nbAmmo <= 0))
    {
        initNiveau(niv);
    }
}

void genRandomPos(int &x, int &y)
{
    x = rand() % 650 + 10;
    y = rand() % 400 + 10;
}

void killRandomCan(Niveau &niv)
{
    int a = rand() % 3;
    if(a == 0)
        niv.cBleu.isDead = true;
    if(a == 1)
        niv.cMarron.isDead = true;
    if(a == 2)
        niv.cNoir.isDead = true;
}
