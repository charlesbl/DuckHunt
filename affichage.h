#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include <SDL/SDL.h>

void applySurface(int x, int y, SDL_Surface* source,SDL_Surface* destination, SDL_Rect* clip);
void showMessageScreen(std::string message, int x, int y, TTF_Font *font, int fontSize,SDL_Color scoreColor, SDL_Surface* &screen);

#endif // AFFICHAGE_H
