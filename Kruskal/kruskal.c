#include "kruskal.h"

int compare_arc(const void* a, const void* b) { // compare 2 poids pour pouvoir les trier avec qsort
    struct note_arc *arcA = (struct note_arc *)a;
    struct note_arc *arcB = (struct note_arc *)b;

    return arcA->poids - arcB->poids;
}

void algo_kruskal(Graphe graphe){
    int * numCC = NULL;
    int nb_arete = 0;
    int s1, s2;
    numCC = malloc(graphe.ordre* sizeof(int));
    for (int i = 0; i < graphe.ordre; ++i) { // assigne un nombre à tous les sommets pour vérifier leur connexité
        numCC[i] = i;
    }
    for (int i = 0; i < graphe.taille; ++i) { // mets la marque de tous les arcs à 0
        graphe.abre.arc[nb_arete].accepte = 0;
    }
    graphe.abre.poids = 0;
    printf("Voici la liste des aretes contenues dans l'ACPM :\n");
    qsort(graphe.abre.arc, graphe.taille, sizeof(struct note_arc), compare_arc); // trie les aretes dans l'ordre de poids croissant
    while(nb_arete < graphe.taille){
        s1 = graphe.abre.arc[nb_arete].S1;
        s2 = graphe.abre.arc[nb_arete].S2;
        if(numCC[s1] != numCC[s2]){
            graphe.abre.arc[nb_arete].accepte = 1; // marque le sommet
            for (int i = 0; i < graphe.ordre; ++i) {
                if(i != s2){ // si cette condition n'existe pas cela modifie la connexité s2 et cela
                    if(numCC[i] == numCC[s2]){ //ne modifie pas les valeurs apres s2
                        numCC[i] = numCC[s1];
                    }
                }
            }
            numCC[s2] = numCC[s1]; // modifie la connexité de s2
        }
        nb_arete++;
    }
    for (int i = 0; i < graphe.taille; ++i) {
        if(graphe.abre.arc[i].accepte){ // prends tous les arcs marqués
            printf("%d <--> %d / ", graphe.abre.arc[i].S1, graphe.abre.arc[i].S2); // affiche les arètes présentes dans l'arbre
            graphe.abre.poids = graphe.abre.poids + graphe.abre.arc[i].poids; // calcul le poids de l'arbre
        }
    }
    printf("\nle poids minimal de l'arbre est %d", graphe.abre.poids); // affiche le
}