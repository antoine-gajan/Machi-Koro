#include "Gare.h"

Gare::Gare()
    : Monument(AVANT,
               "Gare",
               4,
               "Vous pouvez lancer 2 des",
               "../../assets/Monuments/Gare-travaux.png") {
    /// Constructeur de Gare
}

void Gare::declencher_effet(unsigned int possesseur, int bonus = 0) const {
    std::cout << "Activation de l'effet de la gare" << std::endl;
}