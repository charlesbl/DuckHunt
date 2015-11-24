#ifndef CANARD_H
#define CANARD_H

const int vitesseCanNoir = 10;
const int vitesseCanMarron = 20;
const int vitesseCanBleu = 30;

// couleur: 0 = noir, 1 = marron, 2 = bleueeee
struct canard{
    int x;
    int y;
    int mvx;
    int mvy;
    int couleur;
    bool isDead;
    SDL_Rect rect;
};

void initCanard(canard &can, int x, int y, int couleur);

void updateCan(SDL_Surface *screen);

#endif // CANARD_H
