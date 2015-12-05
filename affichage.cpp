#include <cstdlib>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <affichage.h>
#include <canard.h>


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
void showBullet(int nbBullet, SDL_Surface *screen, SDL_Surface *bullet)
{
    SDL_Rect rect;

    if(nbBullet == 3)
        rect = {232, 2, 73, 48};
    else if(nbBullet == 2)
        rect = {156, 2, 73, 48};
    else if(nbBullet == 1)
        rect = {79, 2, 73, 48};
    else
        rect = {2, 2, 74, 48};

    applySurface(63 , 660, bullet, screen, &rect);
}

void showDuck(SDL_Surface *screen, SDL_Surface *duck, Canard can)
{
    SDL_Rect rect;
    int posCouleur;

    if(can.couleur == 0) //Noir
    {
        posCouleur = 227;
    }else if(can.couleur == 1) //marron
    {
        posCouleur = 312;

    }else //BLUEUEEUIEUUEUE
    {
        posCouleur = 392;
    }

    if(!can.isDead){
        if(can.time % 8 < 2)
            rect = {0, posCouleur, 79, 87};
        else if(can.time % 8 < 4)
            rect = {75, posCouleur, 72, 87};
        else if(can.time % 8 < 6)
            rect = {150, posCouleur, 65, 87};
        else
            rect = {75, posCouleur, 72, 87};
    } else {
        if(can.time % 4 < 2)
            rect = {529, posCouleur, 40, 87};
        else
            rect = {578, posCouleur, 40, 87};
    }


    applySurface(can.x , can.y, duck, screen, &rect);
}
