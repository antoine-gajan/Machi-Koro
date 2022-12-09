#include "Gare.h"

Gare::Gare()
    : Monument(AVANT,
               "Gare",
               4,
               "Vous pouvez lancer 2 des",
               "../../assets/Monuments/Gare-travaux.png") {
    /// Constructeur de Gare
}

void Gare::declencher_effet(unigned int possesseur) const {
    std::cout << "Activation de l'effet de la gare" << std::endl;
}