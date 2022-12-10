#include "EntrepriseRenovation.h"

EntrepriseRenovation::EntrepriseRenovation() :
        Batiment("EntrepriseRenovation",
                 1,
                 "Recevez 1 piece de la banque pour chaque piece placee sur l'ensemble de tous les joueurs. A la fin de votre tour, placez une piece sur votre EntrepriseRenovation.",
                 "../../../assets/batiments/Violet/Entreprise-de-renovation.jpg",
                 Violet,
                 list<unsigned int>{10},
                 "special") {
    ///Constructeur de EntrepriseRenovation
}

void EntrepriseRenovation::declencher_effet(unsigned int possesseur) const{
    /// Effet de la classe Entreprise de Renovation
    std::cout << "Activation de l'effet de la Entreprise de renovation." << std::endl;
}
