#include "CentreCommercial.h"

CentreCommercial::CentreCommercial() :
    Monument(APRES,
             "Centre commercial",
             10,
             "Les établissement rouge et vert vous rapportent une pièce de plus",
             "../../assets/Monuments/CentreCommercial-travaux.png") {
    /// Constructeur de Centre commercial
}

void CentreCommercial::declencher_effet() const {
    std::cout << "Activation de l'efet du Centre commercial" << std::endl;
}