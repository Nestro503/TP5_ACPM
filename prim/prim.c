
#include "prim.h"

void init_prim(Graphe graphe, int premier_sommet, int tab[]){
    graphe.abre.poids = 0;
    for (int i = 0; i < graphe.ordre; ++i) {
        tab[i] = 0; // tous les sommets sont non marqués
        graphe.pSommet[i]->pred = 0; // les sommets n’ont pas encore de prédécesseur
    }
    tab[premier_sommet] = 1;
}


//parmi tous les sommets x marqués, choisir un successeur x’ non marqué tel que
//p(x,x’) soit minimum

void parcours_prim(Graphe* graphe, int tab[]){// parcours les arcs de tous les sommets marqués
    pArc arc_temp = malloc(sizeof(pArc)); // et détecte l'arc avec le plus petit poids
    arc_temp->poids = INT_MAX;
    int pred_temp;

    for (int i = 0; i < graphe->ordre; ++i) {
        if(tab[i] == 1){
            pArc arc = graphe->pSommet[i]->arc;
            while ((arc != NULL)){
                if(tab[arc->sommet] == 0){ // si le sucesseur du sommet i n'est pas marque
                    if(arc->poids < arc_temp->poids){ // permet de trouver l'arc avec le plus petit poids de tous les sommets marqués
                        arc_temp = arc;
                        pred_temp = i;
                    }
                }
                arc = arc->arc_suivant;
            }
        }
    }
    graphe->abre.poids = graphe->abre.poids + arc_temp->poids;
    graphe->pSommet[arc_temp->sommet]->pred = pred_temp;
    tab[arc_temp->sommet] = 1; // marque le sommet avec l'arc le plus petit poids
}

int tous_sommet_marque(int const tab[], int ordre){
    int compteur = 0;
    for (int i = 0; i < ordre; ++i) { // Si un sommet est detecte comme etant marque alors compteur augmente
        if(tab[i] == 0){
            compteur++;
        }
    }
    if(compteur > 0)
        return 0;
    else
        return 1;
}

void return_prim(Graphe graphe){// le resultat de l'algo de prim
    int temp = 0;
    int compteur = 0;
    for (int i = 0; i < graphe.ordre; ++i) {
        if(temp < graphe.pSommet[i]->distance)
            temp = graphe.pSommet[i]->distance;
    }
    printf("Le poids total minimum est de %d\n",graphe.abre.poids);
    // print la liste des arretes qui ont etaient selectionnes
    printf("Voici la liste des aretes contenues dans l'ACPM :\n");
    while(compteur != graphe.ordre){
        printf("%d --> %d / ", graphe.pSommet[compteur]->pred, compteur);
        compteur++;
    }
}

void algo_prim(Graphe graphe,int premier_sommet){
    int tab[graphe.ordre]; // tableau qui recense les etats de chaque sommets
    init_prim(graphe,premier_sommet, tab);
    do{
        parcours_prim(&graphe, tab);
    }while(!tous_sommet_marque(tab,graphe.ordre));
    return_prim(graphe);
}

