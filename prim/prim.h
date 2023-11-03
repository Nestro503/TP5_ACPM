
#ifndef TP3_DJIKSTRA_GRAPHE_H
#define TP3_DJIKSTRA_GRAPHE_H

#include "../graphe.h"

void init_prim(Graphe *graphe, int premier_sommet, int counter);

void parcours_prim(Graphe graphe, int s1, int counter);

void return_prim(Graphe graphe);

void algo_prim(Graphe graphe);


#endif //TP3_DJIKSTRA_GRAPHE_H
