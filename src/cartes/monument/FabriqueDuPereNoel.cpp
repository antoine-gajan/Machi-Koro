#include "FabriqueDuPereNoel.h"

FabriqueDuPereNoel::FabriqueDuPereNoel() :
        Monument(APRES,
                 "FabriqueDuPereNoel",
                 0,
                 "Si le jet de de est casse vous gagnez 3 pieces",
                 "../../assets/Monuments/FabriqueDuPereNoel.png") {
    /// Constructeur de Centre commercial
}

void FabriqueDuPereNoel::declencher_effet() const {
    std::cout << "Activation de l'effet de la Fabrique du Père Noel" << std::endl;
}