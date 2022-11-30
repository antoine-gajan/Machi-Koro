#include "ParcAttraction.h"

ParcAttraction::ParcAttraction() :
    Monument(APRES,
             "Parc d'attractions",
             16,
             "Si le jet de dé est un double vous pouvez rejouer",
             "../../assets/Monuments/ParcAttraction-travaux.png") {
    /// Constructeur de ParcAttraction
}

void ParcAttraction::declencher_effet() const {
    std::cout << "Activation de l'effet du Parc d'attractions" << std::endl;
}