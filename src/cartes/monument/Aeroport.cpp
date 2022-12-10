#include "Aeroport.h"

Aeroport::Aeroport() :
    Monument(APRES,
                "Aeroport",
                30,
                "Si rien n'a ete construit durant le tour, la banque donne 10 au joueur",
                "../../assets/Monuments/Aeroport-travaux.jpg") {
    /// Constructeur de Aeroport
}

void Aeroport::declencher_effet(unsigned int possesseur, int bonus = 0) const {
    std::cout << "Activation de l'effet de l'aeroport" << std::endl;
}
