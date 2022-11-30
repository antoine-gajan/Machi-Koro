#include "CentreImpots.h"


CentreImpots::CentreImpots():
        Batiment("Centre des Impots",
                 4,
                 "Recevez la moitie (arrondie a l'inferieur) des pieces de chaque joueur qui en possede 10 ou plus.",
                 "../../../assets/batiments/Violet/Centre-des-impots.jpg",
                 Violet,
                 list<unsigned int>{8,9},
                 "special") {
    ///Constructeur du Centre des Impots
}



void CentreImpots::declencher_effet() const{
    /// Effet du Centre des Impots
    std::cout << "Activation de l'effet du centre des impots." << std::endl;
}



