#include "CentreCommercial.h"

CentreCommercial::CentreCommercial() :
    Monument(APRES,
             "CentreCommercial",
             10,
             "Les etablissement rouge et vert vous rapportent une piece de plus",
             "../../assets/Monuments/CentreCommercial-travaux.png") {
    /// Constructeur de Centre commercial
}

void CentreCommercial::declencher_effet(unsigned int possesseur, int bonus = 0) const {
    std::cout << "Activation de l'efet du Centre commercial" << std::endl;
}
