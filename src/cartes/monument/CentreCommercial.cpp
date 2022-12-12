#include "CentreCommercial.h"

using namespace std;

CentreCommercial::CentreCommercial() :
    Monument(APRES,
             "CentreCommercial",
             10,
             "Les etablissement rouge et vert vous rapportent une piece de plus",
             "../../assets/monuments/CentreCommercial-travaux.png") {
    /// Constructeur de Centre commercial
}

void CentreCommercial::declencher_effet(unsigned int possesseur, int bonus) const {
    cout << "Activation de l'efet du Centre commercial" << endl;
}

void CentreCommercial::activer() {
    set_image("../../assets/monuments/CentreCommercial-active.png");
}