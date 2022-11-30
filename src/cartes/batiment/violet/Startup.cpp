#include "Startup.h"

Startup::Startup() :
        Batiment("Startup",
                 1,
                 "Recevez 1 pièce de la banque pour chaque pièce placée sur l'ensemble de tous les joueurs. A la fin de votre tour, placez une pièce sur votre Startup.",
                 "../../../assets/batiments/Violet/Startup.jpg",
                 Violet,
                 list<unsigned int>{10},
                 "spécial") {
    ///Constructeur de Startup
}

void Startup::declencher_effet() const{
    /// Effet de la classe Startup
    std::cout << "Activation de l'effet de la startup." << std::endl;
}
