#include "Gare.h"

Gare::Gare()
    : Monument(AVANT,
               "Gare",
               4,
               "Vous pouvez lancer 2 des",
               "../../assets/monuments/Gare-travaux.png") {
    /// Constructeur de Gare
}

void Gare::declencher_effet(unsigned int possesseur, int bonus) const {
    std::cout << "Activation de l'effet de la gare" << std::endl;
}

void Gare::activer() {
    set_image("../../assets/monuments/Gare-active.png");
}