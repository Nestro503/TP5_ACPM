#ifndef TP5_ACPM_KRUSKAL_H
#define TP5_ACPM_KRUSKAL_H

#include "../graphe.h"

int compare_arc(const void* a, const void* b);
//note_arc* arc_sort(Graphe graphe);
void parcours_successeur(Graphe* graphe, int s, int numCC[]);
void algo_kruskal(Graphe graphe);

#endif
