#include "HotelDeVille.h"

HotelDeVille::HotelDeVille() :
    Monument(APRES,
             "Hotel de ville",
             0,
             "Une fois par tour vous pouvez relancer vos dés",
             "../../assets/Monuments/HotelDeVille.png") {
    /// Constructeur de HotelDeVille
}

void HotelDeVille::declencher_effet() const {
    std::cout << "Activation de l'effet de l'Hotel de ville" << std::endl;
}