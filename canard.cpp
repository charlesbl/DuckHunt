#include <SDL/SDL.h>
#include <affichage.h>
#include <canard.h>
#include <SDL/SDL_image.h>

//Les attributs de l'image
const int SHEET_WIDTH=1379;
const int SHEET_HEIGHT=564;

void initCanard(canard &can, int x, int y, int couleur){
    can.x = x;
    can.y = y;
    can.couleur = couleur;
    if(couleur == 0)
    {
        can.mvx = vitesseCanNoir;
        can.mvy = vitesseCanNoir;
    }else if(couleur == 1)
    {
        can.mvx = vitesseCanMarron;
        can.mvy = vitesseCanMarron;
    }else if(couleur == 2){
        can.mvx = vitesseCanBleu;
        can.mvy = vitesseCanBleu;
    }
}

//appellé a chaque tour de boucle
void updateCan(SDL_Surface *screen)
{
    //affichage
    SDL_Surface *can;

    SDL_Rect rect;
    rect.x=0;
    rect.y=217;
    rect.w=80;
    rect.h=80;
/*// A METTRE DANS LE MAIN DUCON tkt maggle
    can = SDL_DisplayFormat(IMG_Load("duck.png"));

    SDL_SetColorKey(can, SDL_SRCCOLORKEY, SDL_MapRGB(can->format,228, 255, 0));
*/
    applySurface(100,100,can,screen,&rect);

    //mouvement

}
