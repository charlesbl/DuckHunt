#ifndef CANARD_H
#define CANARD_H


// couleur: 0 = noir, 1 = marron, 2 = bleueeee
struct Canard{
    int x;//position x du canard
    int y;//position y du canard
    int mvx;//Mouvement x du canard
    int mvy;//Mouvement y du canard
    int couleur;//couleur du canard
    bool isDead;//Booléen canard mort
    SDL_Rect rect;//Rectangle du canard
    int time;//Temps pour l'afficher en ttf de Niveau
    bool echape;//Booléen canard échappé
};

void initCanard(Canard &can, int x, int y, int couleur);

void updateCan(SDL_Surface *screen, SDL_Surface *duck, Canard &can);

void moveCanard(Canard &can);
#endif // CANARD_H
