#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include <SDL/SDL.h>

void applySurface(int x, int y, SDL_Surface* source,SDL_Surface* destination, SDL_Rect* clip);

#endif // AFFICHAGE_H
