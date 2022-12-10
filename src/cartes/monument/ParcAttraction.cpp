#include "ParcAttraction.h"

ParcAttraction::ParcAttraction() :
    Monument(APRES,
             "ParcAttraction",
             16,
             "Si le jet de de est un double vous pouvez rejouer",
             "../../assets/monuments/ParcAttraction-travaux.png") {
    /// Constructeur de ParcAttraction
}

void ParcAttraction::declencher_effet(unsigned int possesseur, int bonus) const {
    std::cout << "Activation de l'effet du Parc d'attractions" << std::endl;
}

void ParcAttraction::activer(){
    set_image("../../assets/monuments/ParcAttraction-active.png");
}