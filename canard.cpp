#include <SDL/SDL.h>
#include <canard.h>

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
void update()
{
    //affichage
    //mouvement
}
