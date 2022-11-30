#include "Port.h"

Port::Port()
        : Monument(PENDANT,
                   "Port",
                   2,
                   "Si le résultat du jet de dé est supérieur ou égal à 10, vous pouvez ajouter 2 à ce résultat.",
                   "../../assets/Monuments/Port-travaux.png") {
    /// Constructeur de Port
}

void Port::declencher_effet() const {
    std::cout << "Activation de l'effet du Port" << std::endl;
}