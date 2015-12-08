#ifndef NIVEAU_H
#define NIVEAU_H
#include <canard.h>
#include <SDL/SDL.h>

struct Hit
{
    SDL_Rect rect;
    int state; //0 = neutre, 1 = raté, 2 = touché
};

struct Niveau
{
    Canard cNoir;
    Canard cMarron;
    Canard cBleu;
    Hit hit[10];
    int nbHit;
    int score;
    int level;
    int time;
    int nbCanRate;
    bool start;
    bool perdu;
};

void initNiveau(Niveau &niv, int level, int score);
void updateNiv(SDL_Surface *screen, SDL_Surface *duck, Niveau &niv);
void genRandomPos(int &x, int &y);
void killRandomCan(Niveau &niv);
void killCan(Canard &can, Niveau &niv);
int getNbAliveCan(Niveau &niv);

#endif // NIVEAU_H
