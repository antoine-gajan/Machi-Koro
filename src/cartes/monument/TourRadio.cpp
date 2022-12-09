#include "TourRadio.h"
#include "Joueur.h"

TourRadio::TourRadio() :
    Monument(APRES,
             "TourRadio",
             22,
             "Une fois par tour vous pouvez relancer vos des",
             "../../assets/Monuments/TourRadio-travaux.png") {
    /// Constructeur de TourRadio
}

void TourRadio::declencher_effet(unigned int possesseur) const {
    std::cout << "Activation de l'effet de la Tour radio" << std::endl;
}