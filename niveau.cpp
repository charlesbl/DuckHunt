#include <iostream>
#include <SDL/SDL.h>
#include <niveau.h>
#include <canard.h>
#include <cstdlib>
#include <ctime>

extern int nbAmmo;

const int SCREEN_WIDTH=750;
const int SCREEN_HEIGHT=761;

void initNiveau(Niveau &niv)
{
    nbAmmo = 3;
    niv.score = 0;
    int x;
    int y;
    genRandomPos(x,y);
    initCanard(niv.cNoir, x, y, 0);
    genRandomPos(x,y);
    initCanard(niv.cMarron, x, y, 1);
    genRandomPos(x,y);
    initCanard(niv.cBleu, x, y, 2);

    killRandomCan(niv);

    niv.nbHit = 0;
    for(int i=0; i<10;i++)
    {
        niv.hit[i].state = 0;
        niv.hit[i].rect = {33*i + 190, 670, 10, 10};
    }
}

void updateNiv(SDL_Surface *screen, SDL_Surface *duck, Niveau &niv)
{
    updateCan(screen, duck, niv.cNoir);
    updateCan(screen, duck, niv.cMarron);
    updateCan(screen, duck, niv.cBleu);

    if(nbAmmo <= 0)
    {
        niv.cBleu.echape = true;
        niv.cMarron.echape = true;
        niv.cNoir.echape = true;
    }

    if((niv.cNoir.y > SCREEN_HEIGHT - 200 && niv.cMarron.y > SCREEN_HEIGHT - 200 && niv.cBleu.y > SCREEN_HEIGHT - 200))
    {
        if(nbAmmo <= 0){
            int alive = getNbAliveCan(niv);
            for(int i = niv.nbHit; i < alive + niv.nbHit;i++){
                niv.hit[i].state = 1;
            }
            niv.nbHit += alive;
        }
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

    if(niv.nbHit >= 10){
        initNiveau(niv);
    }
}

int getNbAliveCan(Niveau &niv)
{
    int a = 0;
    if(!niv.cBleu.isDead)
        a++;
    if(!niv.cMarron.isDead)
        a++;
    if(!niv.cNoir.isDead)
        a++;

    return a;
}

void killCan(Canard &can, Niveau &niv)
{
    can.isDead = true;
    niv.hit[niv.nbHit].state = 2;
    niv.nbHit++;
    niv.score += 1000;
}

void genRandomPos(int &x, int &y)
{
    x = rand() % 650 + 10;
    y = rand() % 400 + 10;
}

void killRandomCan(Niveau &niv)
{
    int a = rand() % 3;
    if(a == 0){
        niv.cBleu.isDead = true;
        niv.cBleu.y = SCREEN_HEIGHT;
    }
    if(a == 1){
        niv.cMarron.isDead = true;
        niv.cMarron.y = SCREEN_HEIGHT;
    }
    if(a == 2){
        niv.cNoir.isDead = true;
        niv.cNoir.y = SCREEN_HEIGHT;
    }
}
