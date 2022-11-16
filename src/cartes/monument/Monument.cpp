#include "Monument.h"
#include "carte.h"
#include <iostream>

using namespace std;

Monument::Monument(Moment_Effet effet_moment, string nom, unsigned int prix, string description_effet, string path_image) : Carte(nom, prix, description_effet, path_image) {
    /// Constructeur de Monument

    // Gestion d'erreur moment
    if (effet_moment != AVANT && effet_moment != PENDANT && effet_moment != APRES) {
        cout << "Erreur : Moment_Effet invalide" << endl;
        return;
    }

    // Gestion d'erreur nom, description_effet et path_image
    if (nom == "" || description_effet == "") {
        cout << "Erreur : nom ou description_effet invalide" << endl;
        return;
    }

    // Gestion d'erreur prix
    if (prix < 0) {
        cout << "Erreur : prix invalide" << endl;
        return;
    }

    // Appel au constructeur de Carte et initialisation de moment
    Carte(description_effet, nom, prix, path_image);
    moment = effet_moment;
}