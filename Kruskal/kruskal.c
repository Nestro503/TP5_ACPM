#include "kruskal.h"


void parcours_successeur(Graphe* graphe, int s, int numCC[]){
    pArc arc = graphe->pSommet[s]->arc;

    while ((arc != NULL)){
        if(numCC[s] != numCC[arc->sommet]){
            for (int i = 0; i < graphe->ordre; ++i) {
                if(numCC[i] == numCC[arc->sommet]){
                    numCC[i] = numCC[s];
                    graphe->abre.poids = graphe->abre.poids + arc->poids;
                }
            }
        }
        arc = arc->arc_suivant;
    }
}



void algo_kruskal(Graphe graphe){
    int * numCC = NULL;
    numCC = malloc(graphe.taille* sizeof(int));
    graphe.abre.ordre = 0;

    for (int i = 0; i < graphe.taille; ++i) {
        numCC[i] = i;
    }


    printf("\n%d", graphe.abre.ordre);
}