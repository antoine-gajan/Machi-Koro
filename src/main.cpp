#include <iostream>
using namespace std;

#include "Joueur.h"
#include "Boulangerie.h"
#include "Gare.h"

int main() {
    Boulangerie test = Boulangerie();
    Gare test2 = Gare();

    Joueur j1("Joueur 1", {&test2}, {&test} , 3, aleatoire);

    j1.afficher_joueur();

    j1.activer_monument(&test2);
    j1.retirer_batiment(&test);
    j1.afficher_joueur();

    return 0;
}