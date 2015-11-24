#include <cstdlib>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <affichage.h>


void applySurface(int x, int y, SDL_Surface *source, SDL_Surface* destination, SDL_Rect* clip)
{
    SDL_Rect offset = {x, y, 0 ,0};
    SDL_BlitSurface(source, clip, destination, &offset);
}

bool onRect(int x, int y, SDL_Rect rect)
{
    return ((x > rect.x && x < rect.x+rect.w) && (y > rect.y && y < rect.y+rect.h));
}

void showMenu(Menu menu, SDL_Surface *screen)
{
    applySurface(0, 0, menu.fondMenu, screen, NULL);

    SDL_BlitSurface(menu.tJouer, NULL, screen, &menu.rjouer);
    SDL_BlitSurface(menu.tQuit, NULL, screen, &menu.rQuit);
}
