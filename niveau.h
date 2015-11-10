#ifndef NIVEAU_H
#define NIVEAU_H

const int NB_CANARD_PAR_NIVEAU = 10;

struct niveau
{
    canard listeCanard[NB_CANARD_PAR_NIVEAU];
    int difficulte;
    int vitesse;

};

void initNiveau(niveau &niv, int vitesse);

#endif // NIVEAU_H
