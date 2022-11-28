#include "Carte.h"
#include <string>
#include <iostream>

using namespace std;

Carte::Carte(const string& name, const string& effect_description, unsigned int price, const string& path_picture) {
    /// Constructeur de la classe Carte

    // Gestion des erreurs
    if (name.empty()) {
        throw invalid_argument("Le nom de la carte ne peut pas être vide");
    }

    if (effect_description.empty()) {
        throw invalid_argument("La description de l'effet de la carte ne peut pas être vide");
    }

    if (path_picture.empty()) {
        throw invalid_argument("Le chemin de l'image de la carte ne peut pas être vide");
    }

    // Initialisation des attributs
    nom = name;
    description_effet = effect_description;
    prix = price;
    path_image = path_picture;
}