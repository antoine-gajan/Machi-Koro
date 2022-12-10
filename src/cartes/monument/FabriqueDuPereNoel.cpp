#include "FabriqueDuPereNoel.h"

FabriqueDuPereNoel::FabriqueDuPereNoel() :
        Monument(APRES,
                 "FabriqueDuPereNoel",
                 0,
                 "Si le jet de de est casse vous gagnez 3 pieces",
                 "../../assets/Monuments/FabriqueDuPereNoel.png") {
    /// Constructeur de Centre commercial
}

void FabriqueDuPereNoel::declencher_effet(unsigned int possesseur, int bonus) const {
    std::cout << "Activation de l'effet de la Fabrique du Pere Noel" << std::endl;
}

void FabriqueDuPereNoel::activer() {
    set_image("../../assets/Monuments/FabriqueDuPereNoel.png");
}