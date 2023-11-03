
#include "prim.h"

void init_prim(Graphe *graphe, int premier_sommet, int counter){
    graphe.abre.poids = 0;
    for (int i = 0; i < graphe.ordre; ++i) {
        graphe.pSommet[i]->marque = 0; // tous les sommets sont non marqués
        graphe.pSommet[i]->pred = 0; // les sommets n’ont pas encore de prédécesseur
    }
    graphe.pSommet[premier_sommet]->marque = 1;
    counter++;
}


//parmi tous les sommets x marqués, choisir un successeur x’ non marqué tel que
//p(x,x’) soit minimum

void parcours_prim(Graphe graphe, int s1, int counter){
    pSommet s2;
    pSommet tmp = graphe->pSommet[s1]->arc;
    tmp->arc->poids = INIT_MAX;

    for (int i = 0; i < graphe.ordre; i++){
        if (graphe.pSommet[i]->marque = 0 && (graphe->pSommet[i]->arc->poids) < (tmp->arc->poids)){
            tmp = graphe->pSommet[i];
        }
    }
    tmp->arc->poids->pred = s2;
    graphe.pSommet[s2]->marque = 1;
    graphe.abre.poids = graphe.abre.poids + tmp->arc->poids;
    counter++;
}

void return_prim(Graphe graphe){
    printf("Le poids total minimum est de %d",graphe.abre.ordre);
    // print la liste des arretes qui ont etaient selectionnes
    printf("Voici la liste des aretes contenues dans l'ACPM :\n");
    // A -- B : 8
    // ...
}

void algo_prim(Graphe graphe){
    int counter = 0;
    init_prim(graphe);
    while (counter != graphe.ordre){
        parcours_prim();
    }
    return_prim();
}

