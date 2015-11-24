#include <SDL/SDL.h>
#include <niveau.h>
#include <canard.h>

void initNiveau(niveau &niv, int vitesse)
{

}

void updateNiv(niveau &niv)
{
    //affichage
}
bool collision(SDL_Rect a, SDL_Rect b)
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    if(bottomA <= topB)
        return false;
    if(topA >= bottomB)
        return false;
    if(rightA <= leftB)
        return false;
    if(leftA >= rightB)
        return false;

    return true;
}
