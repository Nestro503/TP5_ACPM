
#ifndef TP5_ACPM_PRIM_H
#define TP5_ACPM_PRIM_H

#include "../graphe.h"


void init_prim(Graphe graphe, int premier_sommet, int tab[]);

void parcours_prim(Graphe* graphe, int tab[]);

void return_prim(Graphe graphe, int sommet_initial);

int tous_sommet_marque(int const tab[], int ordre);

void algo_prim(Graphe graphe, int premier_sommet);


#endif //TP5_ACPM_PRIM_H
