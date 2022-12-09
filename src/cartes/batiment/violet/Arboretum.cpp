#include "Arboretum.h"

Arboretum::Arboretum():
        Batiment("Arboretum",
                 3,
                 "Rassemblez les pieces de tous les joueurs puis redistribuez les de maniere egale entre tous. La banque completera s'il manque des pieces pour une redistribution egale.",
                 "../../../assets/batiments/Violet/Arboretum.jpg",
                 Violet,
                 list<unsigned int>{11, 12, 13},
                 "special") {
    ///Constructeur de l'Arboretum
}



void Arboretum::declencher_effet(unigned int possesseur) const{
    /// Effet de l'arboretum
    std::cout << "Activation de l'effet de l'arboretum." << std::endl;

}