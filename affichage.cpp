#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <affichage.h>
#include <canard.h>
#include <niveau.h>

extern bool showmenu;


void applySurface(int x, int y, SDL_Surface *source, SDL_Surface* destination, SDL_Rect* clip)
{
    SDL_Rect offset = {x, y, 0 ,0};
    SDL_BlitSurface(source, clip, destination, &offset);
}

bool onRect(int x, int y, SDL_Rect rect)
{
    return ((x > rect.x && x < rect.x+rect.w) && (y > rect.y && y < rect.y+rect.h));
}

/****************** Nom de la fonction **********************
* NOM_FONCTION                                              *
******************** Auteur , Dates *************************
* Nom/Date : Éventuellement la version                      *
********************* Description ***************************
* Vous décrivez ici ce que fait cette fonction              *
*********************** Entrées *****************************
* Vous décrivez ici les données en entrée de la fonction    *
*********************** Sorties *****************************
* Vous détaillez ici ce que renvoie la fonction             *
************************************************************/
void initMenu(Menu &menu)
{
    menu.sJouer, menu.sQuit = false;
    menu.menuFonts = TTF_OpenFont("duck_hunt.ttf",100);
    menu.menuColor = {0, 0 ,0};
    menu.menuColorS = {200, 200 ,200};

    menu.tJouer = TTF_RenderText_Blended(menu.menuFonts, "Jouer", menu.menuColor);
    menu.tJouerS = TTF_RenderText_Blended(menu.menuFonts, "Jouer", menu.menuColorS);
    menu.rjouer = {80, 80, 275, 90};
    menu.tQuit = TTF_RenderText_Blended(menu.menuFonts, "Quitter", menu.menuColor);
    menu.tQuitS = TTF_RenderText_Blended(menu.menuFonts, "Quitter", menu.menuColorS);
    menu.rQuit = {80, 200, 375, 90};
    std::string smenu = "menu.png";
    menu.fondMenu = IMG_Load(smenu.c_str());
}

/****************** Nom de la fonction **********************
* NOM_FONCTION                                              *
******************** Auteur , Dates *************************
* Nom/Date : Éventuellement la version                      *
********************* Description ***************************
* Vous décrivez ici ce que fait cette fonction              *
*********************** Entrées *****************************
* Vous décrivez ici les données en entrée de la fonction    *
*********************** Sorties *****************************
* Vous détaillez ici ce que renvoie la fonction             *
************************************************************/
void showMenu(Menu menu, SDL_Surface *screen)
{
    applySurface(0, 0, menu.fondMenu, screen, NULL);

    if(menu.sJouer)
        SDL_BlitSurface(menu.tJouerS, NULL, screen, &menu.rjouer);
    else
        SDL_BlitSurface(menu.tJouer, NULL, screen, &menu.rjouer);

    if(menu.sQuit)
        SDL_BlitSurface(menu.tQuitS, NULL, screen, &menu.rQuit);
    else
        SDL_BlitSurface(menu.tQuit, NULL, screen, &menu.rQuit);
}

/****************** Nom de la fonction **********************
* NOM_FONCTION                                              *
******************** Auteur , Dates *************************
* Nom/Date : Éventuellement la version                      *
********************* Description ***************************
* Vous décrivez ici ce que fait cette fonction              *
*********************** Entrées *****************************
* Vous décrivez ici les données en entrée de la fonction    *
*********************** Sorties *****************************
* Vous détaillez ici ce que renvoie la fonction             *
************************************************************/
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

/****************** Nom de la fonction **********************
* NOM_FONCTION                                              *
******************** Auteur , Dates *************************
* Nom/Date : Éventuellement la version                      *
********************* Description ***************************
* Vous décrivez ici ce que fait cette fonction              *
*********************** Entrées *****************************
* Vous décrivez ici les données en entrée de la fonction    *
*********************** Sorties *****************************
* Vous détaillez ici ce que renvoie la fonction             *
************************************************************/
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
        if(can.time % 6 < 3)
            rect = {529, posCouleur, 40, 87};
        else
            rect = {578, posCouleur, 40, 87};
    }


    applySurface(can.x , can.y, duck, screen, &rect);
}

/****************** Nom de la fonction **********************
* NOM_FONCTION                                              *
******************** Auteur , Dates *************************
* Nom/Date : Éventuellement la version                      *
********************* Description ***************************
* Vous décrivez ici ce que fait cette fonction              *
*********************** Entrées *****************************
* Vous décrivez ici les données en entrée de la fonction    *
*********************** Sorties *****************************
* Vous détaillez ici ce que renvoie la fonction             *
************************************************************/
void showHit(SDL_Surface *screen, SDL_Surface *hitSurface, Hit hit[])
{
    SDL_Rect rect;
    for(int i = 0; i<10; i++)
    {
        if(hit[i].state == 0){
            rect = {8, 7, 22, 24};
        }else if(hit[i].state == 1){
            rect = {32, 7, 22, 24};
        }else{
            rect = {56, 7, 22, 24};
        }
        applySurface(hit[i].rect.x, hit[i].rect.y,hitSurface, screen, &rect);
    }
}

/****************** Nom de la fonction **********************
* NOM_FONCTION                                              *
******************** Auteur , Dates *************************
* Nom/Date : Éventuellement la version                      *
********************* Description ***************************
* Vous décrivez ici ce que fait cette fonction              *
*********************** Entrées *****************************
* Vous décrivez ici les données en entrée de la fonction    *
*********************** Sorties *****************************
* Vous détaillez ici ce que renvoie la fonction             *
************************************************************/
void showScore(SDL_Surface *screen, SDL_Surface *scoreSurface, TTF_Font *font, int score)
{
    SDL_Color scoreColor = {255, 255 ,255};
    SDL_Rect scoreRec = {590, 670, 275, 90};
    std::ostringstream mssg;
    mssg.flush();
    mssg.str("");
    mssg << score;
    scoreSurface = TTF_RenderText_Blended(font, mssg.str().c_str(), scoreColor);
    SDL_BlitSurface(scoreSurface, NULL, screen, &scoreRec);
}

/****************** Nom de la fonction **********************
* NOM_FONCTION                                              *
******************** Auteur , Dates *************************
* Nom/Date : Éventuellement la version                      *
********************* Description ***************************
* Vous décrivez ici ce que fait cette fonction              *
*********************** Entrées *****************************
* Vous décrivez ici les données en entrée de la fonction    *
*********************** Sorties *****************************
* Vous détaillez ici ce que renvoie la fonction             *
************************************************************/
void showLevel(SDL_Surface *screen, SDL_Surface *nivSurface, TTF_Font *font, Niveau &niv){
    niv.time++;
    SDL_Color color = {0, 0 ,0};
    SDL_Rect rect = {200, 150, 275, 90};
    std::ostringstream mssg;
    mssg.flush();
    mssg.str("");
    mssg << "NIVEAU " << niv.level;
    nivSurface = TTF_RenderText_Blended(font, mssg.str().c_str(), color);
    SDL_BlitSurface(nivSurface, NULL, screen, &rect);

    if(niv.time >= 70){
        niv.start = false;
        niv.time = 0;
    }
}

/****************** Nom de la fonction **********************
* NOM_FONCTION                                              *
******************** Auteur , Dates *************************
* Nom/Date : Éventuellement la version                      *
********************* Description ***************************
* Vous décrivez ici ce que fait cette fonction              *
*********************** Entrées *****************************
* Vous décrivez ici les données en entrée de la fonction    *
*********************** Sorties *****************************
* Vous détaillez ici ce que renvoie la fonction             *
************************************************************/
void showGameOver(SDL_Surface *screen, SDL_Surface *gameOverSurface, TTF_Font *font, Niveau &niv){

    niv.time++;
    SDL_Color color = {255, 0 ,0};
    SDL_Rect rect = {200, 150, 275, 90};
    std::ostringstream mssg;
    mssg.flush();
    mssg.str("");
    mssg << "GAME OVER";
    gameOverSurface = TTF_RenderText_Blended(font, mssg.str().c_str(), color);
    SDL_BlitSurface(gameOverSurface, NULL, screen, &rect);

    if(niv.time >= 70){
        initNiveau(niv, 1, 0);
        showmenu = true;
    }
}
