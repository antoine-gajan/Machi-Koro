#include "Batiment.h"



Batiment::Batiment(const string& nom, unsigned int prix, const string& description_effet, const string& path_image, couleur_bat coul,
                   const std::list<unsigned int>& num, const std::string& type_bat) : Carte(nom, description_effet,
                                                                          prix, path_image), couleur(coul),
                                                                          type(type_bat), num_activation(num){
    ///Constructeur de Batiment
}

