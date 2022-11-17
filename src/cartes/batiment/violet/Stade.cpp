#include "Stade.h"

Stade::Stade(string nom, unsigned int prix, string description_effet, string path_image,
                                   couleur_bat coul, std::list<unsigned int> num, std::string type_bat)
        : Batiment(nom, prix, description_effet, path_image, coul, num, type_bat) {
    ///Constructeur de Stade
}