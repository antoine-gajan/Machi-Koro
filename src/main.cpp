#include <iostream>
using namespace std;

#include "Joueur.h"
#include "Boulangerie.h"
#include "Gare.h"

int main() {

    Joueur j1("Joueur 1", {new Gare()}, {new Boulangerie()} , 3, neutre);
    cout << j1.get_nom() << endl;
    vector<unsigned int> repartition = j1.get_repartition_argent();
    for (auto i : repartition) {
        cout << i << endl;
    }
    if (j1.get_est_ia()) {
        cout << "IA" << endl;
    } else {
        cout << "Humain" << endl;
    }

    j1.ajouter_batiment(new Boulangerie());


    return 0;
}