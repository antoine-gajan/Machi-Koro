#include "MaisonEdition.h"


MaisonEdition::MaisonEdition():
        Batiment("Maison d'édition",
                 5,
                 "Recevez 1 pièce de chaque joueur pour chaque établissement de type restaurant et commerce qu'il possède.",
                 "../../../assets/batiments/Violet/Maison-d-edition.jpg",
                 Violet,
                 list<unsigned int>{7},
                 "spécial") {
    ///Constructeur de Centre d'Affaires
}



void MaisonEdition::declencher_effet() const{
    /// Effet de la maison d'édition
    std::cout << "Activation de l'effet de la maison d'édition." << std::endl;

}



