#ifndef NIVEAU_H
#define NIVEAU_H
#include <canard.h>
const int NB_CANARD_PAR_NIVEAU = 10;

struct niveau
{
    canard cNoir;
    int difficulte;
    int vitesse;
};

void initNiveau(niveau &niv, int vitesse);
void updateNiv(niveau &niv);

#endif // NIVEAU_H
