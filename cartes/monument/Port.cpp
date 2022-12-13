#include "Port.h"

Port::Port()
        : Monument(PENDANT,
                   "Port",
                   2,
                   "Si le resultat du jet de de est superieur ou egal a 10, vous pouvez ajouter 2 a ce resultat.",
                   "../../assets/monuments/Port-travaux.png") {
    /// Constructeur de Port
}

void Port::declencher_effet(unsigned int possesseur, int bonus) const {
    std::cout << "Activation de l'effet du Port" << std::endl;
}

void Port::activer() {
    set_image("../../assets/monuments/Port-active.png");
}