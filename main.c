#include <stdio.h>

#include "Kruskal/kruskal.h"
#include "prim/prim.h"
#include "graphe.h"



int main() {

    ///initialisation des variables
    Graphe * g;
    char nom_fichier[50]; // le nom du fichier pourra faire au maximum 50 caracteres
    int sommet_initial, sommet_final; // sommet remarquable de notre parcours pour lesquels on va evaluer la distance

    ///validation du fichier utilisé
    printf("Entrer le nom du fichier:");
    scanf("%s",nom_fichier); // atribution du nom du fichier

    ///saisie du numéro des sommets remarquables
    printf("Numero du sommet initial :");
    scanf("%d", &sommet_initial); // atribution du sommet initial
    /*printf("Numero du sommet final :");
    scanf("%d", &sommet_final);*/

    /// creation du graphe
    g = lire_graphe(nom_fichier,sommet_initial);

    /// affichage du graphe
    graphe_afficher(g);

    /// Algo Kruskal
    printf("\nALGORITHME DE KRUSKAL\n");
    algo_kruskal(*g);

    /// Algo Prim
    printf("\n\nALGORITHME DE PRIM\n");
    algo_prim(*g, sommet_initial);


    return 0;
}
