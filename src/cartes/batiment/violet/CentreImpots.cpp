#include "CentreImpots.h"


CentreImpots::CentreImpots():
        Batiment("Centre des Impots",
                 4,
                 "Recevez la moitié (arrondie à l'inférieur) des pièces de chaque joueur qui en possède 10 ou plus.",
                 "../../../assets/batiments/Violet/Centre-des-impots.jpg",
                 Violet,
                 list<unsigned int>{8,9},
                 "spécial") {
    ///Constructeur de Centre d'Affaires
}



void CentreImpots::declencher_effet() const{
    /// Effet du Centre des Impots
    std::cout << "Activation de l'effet du centre des impots." << std::endl;

}



