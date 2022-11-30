#include "FabriqueDuPereNoel.h"

FabriqueDuPereNoel::FabriqueDuPereNoel() :
        Monument(APRES,
                 "FabriqueDuPereNoel",
                 0,
                 "Si le jet de dé est cassé vous gagnez 3 pièces",
                 "../../assets/Monuments/FabriqueDuPereNoel.png") {
    /// Constructeur de Centre commercial
}

void FabriqueDuPereNoel::declencher_effet() const {
    std::cout << "Activation de l'effet de la Fabrique du Père Noël" << std::endl;
}