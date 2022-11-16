#include "Carte.h"
#include <string>
#include <iostream>

using namespace std;

Carte::Carte(string name, string effect_description, int price, string path_picture) {
    /// Constructeur de la classe Carte

    // Gestion des erreurs
    if (price < prix_min) {
        throw "Le prix de la carte ne peut pas être inférieur à 0";
    }

    if (name.empty()) {
        throw "Le nom de la carte ne peut pas être vide";
    }

    if (effect_description.empty()) {
        throw "La description de l'effet de la carte ne peut pas être vide";
    }

    if (path_image.empty()) {
        throw "Le chemin de l'image de la carte ne peut pas être vide";
    }

    // Initialisation des attributs
    nom = name;
    description_effet = effect_description;
    prix = price;
    path_image = path_picture;
}