#include <SDL/SDL.h>
#include <niveau.h>
#include <canard.h>

extern int nbAmmo;

void initNiveau(Niveau &niv)
{
    nbAmmo = 3;
    initCanard(niv.cNoir, 100, 100, 0);
    initCanard(niv.cMarron, 200, 100, 1);
    initCanard(niv.cBleu, 200, 200, 2);
}

void updateNiv(SDL_Surface *screen, SDL_Surface *duck, Niveau &niv)
{
    updateCan(screen, duck, niv.cNoir);
    updateCan(screen, duck, niv.cMarron);
    updateCan(screen, duck, niv.cBleu);
}
