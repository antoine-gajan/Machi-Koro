#include "MaisonEdition.h"


MaisonEdition::MaisonEdition():
        Batiment("MaisonEdition",
                 5,
                 "Recevez 1 piece de chaque joueur pour chaque etablissement de type restaurant et commerce qu'il possede.",
                 "../../../assets/batiments/Violet/Maison-d-edition.jpg",
                 Violet,
                 list<unsigned int>{7},
                 "special") {
    ///Constructeur de Maison d'Edition
}



void MaisonEdition::declencher_effet() const{
    /// Effet de la maison d'edition
    std::cout << "Activation de l'effet de la maison d'edition." << std::endl;

}



