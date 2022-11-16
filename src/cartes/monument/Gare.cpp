#include "Gare.h"
#include "../../Joueur/Joueur.h"
#include <iostream>

using namespace std;

Gare::Gare(Moment_Effet effet_moment, string nom, unsigned int prix, string description_effet, string path_image)
    : Monument(effet_moment, nom, prix, description_effet, path_image) {
}

void Gare::effet(Joueur *joueur) {
    cout << "Vous avez acheté une gare\nVous pouvez maintenant jeter deux dés." << endl;
    jour.nb_de = 2;
}