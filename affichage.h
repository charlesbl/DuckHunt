#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include <SDL/SDL.h>

void applySurface(int x, int y, SDL_Surface* source,SDL_Surface* destination, SDL_Rect* clip);
SDL_Surface *load_image(std::string filename);

#endif // AFFICHAGE_H
