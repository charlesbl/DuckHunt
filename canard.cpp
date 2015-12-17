#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <affichage.h>
#include <canard.h>

const int SCREEN_WIDTH=750;
const int SCREEN_HEIGHT=761;

const int vitesseCanNoir = 2;
const int vitesseCanMarron = 4;
const int vitesseCanBleu = 6;

/****************** Nom de la fonction **********************
* NOM_FONCTION : initCanard                                 *
******************** Auteur , Dates *************************
* Nom/Date : Yonnel Berwit                                  *
********************* Description ***************************
* Initialise le canard.                                     *
*********************** Entrées *****************************
*  3 entiers x,y, couleur et la structure can               *
*********************** Sorties *****************************
* La structure can                                          *
************************************************************/
void initCanard(Canard &can, int x, int y, int couleur){
    can.x = x;
    can.y = y;
    can.couleur = couleur;
    can.isDead = false;
    can.time = 0;
    can.echape = false;
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

/****************** Nom de la fonction **********************
* NOM_FONCTION : updateCan                                  *
******************** Auteur , Dates *************************
* Nom/Date : Charles Blancheton                             *
********************* Description ***************************
* Affiche le canard et le mouvement du canard              *
*********************** Entrées *****************************
* Surface screen et duck et structure can                   *
*********************** Sorties *****************************
* Structure can                                             *
************************************************************/
//appeler a chaque tour de boucle
void updateCan(SDL_Surface *screen, SDL_Surface *duck, Canard &can)
{
    moveCanard(can);
    can.time++;
    showDuck(screen, duck, can);
}

/****************** Nom de la fonction **********************
* NOM_FONCTION : moveCanard                                 *
******************** Auteur , Dates *************************
* Nom/Date : Charles Blancheton et Berwit Yonnel            *
********************* Description ***************************
* Gère le mouvement du canard  en fonction de s'il s'est    *
* échapper ou non, ou bien s'il est mort ou non.            *
*********************** Entrées *****************************
* structure can                                             *
*********************** Sorties *****************************
* structure can                                             *
************************************************************/
void moveCanard(Canard &can)
{
    int taille = 80;
    can.rect = {can.x, can.y, taille, taille};

    if(!can.isDead)
    {
        if(!can.echape)
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
        }else
        {
            can.y -= 10;
            can.x += can.mvx;
        }
    }
    else{
        can.y += 15;
    }
}
