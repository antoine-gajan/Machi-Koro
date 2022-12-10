#include "ParcAttraction.h"

ParcAttraction::ParcAttraction() :
    Monument(APRES,
             "ParcAttraction",
             16,
             "Si le jet de de est un double vous pouvez rejouer",
             "../../assets/Monuments/ParcAttraction-travaux.png") {
    /// Constructeur de ParcAttraction
}

void ParcAttraction::declencher_effet(unsigned int possesseur, int bonus = 0) const {
    std::cout << "Activation de l'effet du Parc d'attractions" << std::endl;
}