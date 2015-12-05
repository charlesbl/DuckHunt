#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include <SDL/SDL.h>
#include <canard.h>
#include <SDL/SDL_ttf.h>
#include <niveau.h>

struct Menu
{
    SDL_Surface *tJouer, *tJouerS, *tQuit, *tQuitS, *fondMenu = NULL;
    SDL_Rect rjouer, rQuit;

    SDL_Color menuColor;
    SDL_Color menuColorS;
    TTF_Font *menuFonts;
    bool sJouer, sQuit;
};

void applySurface(int x, int y, SDL_Surface* source,SDL_Surface* destination, SDL_Rect* clip);
bool onRect(int x, int y, SDL_Rect rect);
void initMenu(Menu &menu);
void showMenu(Menu menu, SDL_Surface *screen);
void showBullet(int nbBullet, SDL_Surface *screen, SDL_Surface *bullet);
void showDuck(SDL_Surface *screen, SDL_Surface *duck, Canard can);
void showHit(SDL_Surface *screen, SDL_Surface *hitSurface, Hit hit[]);
#endif // AFFICHAGE_H
