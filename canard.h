#ifndef CANARD_H
#define CANARD_H


// couleur: 0 = noir, 1 = marron, 2 = bleueeee
struct Canard{
    int x;
    int y;
    int mvx;
    int mvy;
    int couleur;
    bool isDead;
    SDL_Rect rect;
    int time;
};

void initCanard(Canard &can, int x, int y, int couleur);

void updateCan(SDL_Surface *screen, SDL_Surface *duck, Canard &can);

void moveCanard(Canard &can);
#endif // CANARD_H
