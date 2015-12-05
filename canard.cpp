#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <affichage.h>
#include <canard.h>

const int SCREEN_WIDTH=750;
const int SCREEN_HEIGHT=761;

const int vitesseCanNoir = 5;
const int vitesseCanMarron = 7;
const int vitesseCanBleu = 10;

void initCanard(Canard &can, int x, int y, int couleur){
    can.x = x;
    can.y = y;
    can.couleur = couleur;
    can.isDead = false;
    can.time = 0;
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
void updateCan(SDL_Surface *screen, SDL_Surface *duck, Canard &can)
{
    moveCanard(can);
    can.time++;
    showDuck(screen, duck, can);
}
void moveCanard(Canard &can)
{
    int taille = 80;
    can.rect = {can.x, can.y, taille, taille};

    if(!can.isDead)
    {
        can.x += can.mvx;

        // Correction Mouvement Horizontal
        if((can.x + taille > SCREEN_WIDTH) || (can.x < 0))
        {
            can.x -= can.mvx;
            can.mvx *=- 1;
        }

        can.y += can.mvy;

        // Correction Mouvement Vertical
        if((can.y + taille > SCREEN_HEIGHT - 250) || (can.y< 0))
        {
            can.y -= can.mvy;
            can.mvy *= -1;
        }
    }
    else{
        if(can.mvy < 0)
            can.mvy *= -1;
        can.y += can.mvy;
    }
}
