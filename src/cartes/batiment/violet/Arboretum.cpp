#include "Arboretum.h"

Arboretum::Arboretum():
        Batiment("Arboretum",
                 3,
                 "Rassemblez les pièces de tous les joueurs puis redistribuez les de manière égale entre tous. La banque complètera s'il manque des pièces pour une redistribution égale.",
                 "../../../assets/batiments/Violet/Arboretum.jpeg",
                 Violet,
                 list<unsigned int>{11, 12, 13},
                 "spécial") {
    ///Constructeur de l'Arboretum
}



void Arboretum::declencher_effet() const{
    /// Effet de l'arboretum
    std::cout << "Activation de l'effet de l'arboretum." << std::endl;

}