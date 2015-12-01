#ifndef NIVEAU_H
#define NIVEAU_H
#include <canard.h>

const int NB_CANARD_PAR_NIVEAU = 10;

struct Niveau
{
    Canard cNoir;
    Canard cMarron;
    Canard cBleu;
};

void initNiveau(Niveau &niv);
void updateNiv(SDL_Surface *screen, SDL_Surface *duck, Niveau &niv);

#endif // NIVEAU_H
