#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include <SDL/SDL.h>
#include <canard.h>

struct Menu
{
    SDL_Surface *tJouer, *tQuit, *fondMenu = NULL;
    SDL_Rect rjouer, rQuit;

    SDL_Color menuColor = {0, 0 ,0};
};

void applySurface(int x, int y, SDL_Surface* source,SDL_Surface* destination, SDL_Rect* clip);
bool onRect(int x, int y, SDL_Rect rect);
void showMenu(Menu menu, SDL_Surface *screen);
void showBullet(int nbBullet, SDL_Surface *screen, SDL_Surface *bullet);
void showDuck(SDL_Surface *screen, SDL_Surface *duck, Canard can);
#endif // AFFICHAGE_H
