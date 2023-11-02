#include "kruskal.h"

int compare_arc(const void* a, const void* b) {
    struct note_arc *arcA = (struct note_arc *)a;
    struct note_arc *arcB = (struct note_arc *)b;

    return arcA->poids - arcB->poids;
}

void algo_kruskal(Graphe graphe){
    int * numCC = NULL;
    int nb_arete = 0;
    int s1, s2;
    numCC = malloc(graphe.ordre* sizeof(int));
    for (int i = 0; i < graphe.ordre; ++i) {
        numCC[i] = i;
    }
    for (int i = 0; i < graphe.taille; ++i) {
        graphe.abre.arc[nb_arete].accepte = 0;
    }
    graphe.abre.ordre = 0;
    //pNote_arc tab = arc_sort(graphe);
    qsort(graphe.abre.arc, graphe.taille, sizeof(struct note_arc), compare_arc);
    while(nb_arete < graphe.taille){
        s1 = graphe.abre.arc[nb_arete].S1;
        s2 = graphe.abre.arc[nb_arete].S2;
        if(numCC[s1] != numCC[s2]){
            graphe.abre.arc[nb_arete].accepte = 1;
            for (int i = 0; i < graphe.ordre; ++i) {
                if(i != s2){
                    if(numCC[i] == numCC[s2]){
                        numCC[i] = numCC[s1];
                    }
                }
            }
            numCC[s2] = numCC[s1];
            printf("\n\n");
        }
        nb_arete++;
    }
    for (int i = 0; i < graphe.taille; ++i) {
        if(graphe.abre.arc[i].accepte){
            printf("%d-%d ", graphe.abre.arc[i].S1, graphe.abre.arc[i].S2);
            graphe.abre.ordre = graphe.abre.ordre + graphe.abre.arc[i].poids;
        }

    }
    printf("\nl'ordre minimal de l'arbre est %d", graphe.abre.ordre);
}