#include "Monument.h"
#include "Carte.h"

Monument::Monument(Moment_Effet effet_moment, const std::string& nom, unsigned int prix, const std::string& description_effet, const std::string& path_image) :
    Carte(nom, description_effet, prix, path_image) {
    /// Constructeur de Monument

    // Gestion d'erreur moment
    if (effet_moment != AVANT && effet_moment != PENDANT && effet_moment != APRES) {
        std::cout << "Erreur : Moment_Effet invalide" << std::endl;
        return;
    }

    // Gestion d'erreur nom, description_effet et path_image
    if (nom == "" || description_effet == "") {
        std::cout << "Erreur : nom ou description_effet invalide" << std::endl;
        return;
    }

    // Initialisation de moment
    moment = effet_moment;
}