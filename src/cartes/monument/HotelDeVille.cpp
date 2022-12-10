#include "HotelDeVille.h"

HotelDeVille::HotelDeVille() :
    Monument(APRES,
             "HotelDeVille",
             0,
             "Une fois par tour vous pouvez relancer vos des",
             "../../assets/monuments/HotelDeVille.jpg") {
    /// Constructeur de HotelDeVille
}

void HotelDeVille::declencher_effet(unsigned int possesseur, int bonus) const {
    std::cout << "Activation de l'effet de l'Hotel de ville" << std::endl;
}

void HotelDeVille::activer() {
    set_image("../../assets/monuments/HotelDeVille.jpg");
}