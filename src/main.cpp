#include <iostream>
using namespace std;

#include "Joueur.h"
#include "Boulangerie.h"
#include "Gare.h"

int main() {
    Boulangerie test = Boulangerie();

    Joueur j1("Joueur 1", {new Gare()}, {&test} , 3, aleatoire);

    j1.afficher_joueur();

    j1.ajouter_batiment(&test);


    j1.afficher_joueur();

    j1.retirer_batiment(&test);

    j1.afficher_joueur();

    return 0;
}