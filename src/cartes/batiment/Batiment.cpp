#include "Batiment.h"



Batiment::Batiment(string nom, unsigned int prix, string description_effet, string path_image, couleur_bat coul,
                   std::list<unsigned int> num, std::string type_bat) : Carte(nom, description_effet,
                                                                          prix, path_image), couleur(coul),
                                                                          type(type_bat), num_activation(std::move(num)){
    ///Constructeur de Batiment
}

