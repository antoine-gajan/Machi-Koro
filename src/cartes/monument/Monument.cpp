#include "Monument.h"

using namespace std;

Monument::Monument(Moment_Effet effet_moment, const string& nom, unsigned int prix, const string& description_effet, const string& path_image) :
    Carte(nom, description_effet, prix, path_image) {
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

    // Initialisation de moment
    moment = effet_moment;
}