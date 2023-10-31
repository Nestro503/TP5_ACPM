#ifndef TP5_ACPM_KRUSKAL_H
#define TP5_ACPM_KRUSKAL_H

#include "../graphe.h"

void parcours_successeur(Graphe* graphe, int s, int numCC[]);
void algo_kruskal(Graphe graphe);

#endif
