#include "Startup.h"

Startup::Startup() :
        Batiment("Startup",
                 1,
                 "Recevez 1 piece de la banque pour chaque piece placee sur l'ensemble de tous les joueurs. A la fin de votre tour, placez une piece sur votre Startup.",
                 "../../../assets/batiments/Violet/Startup.jpg",
                 Violet,
                 list<unsigned int>{10},
                 "special") {
    ///Constructeur de Startup
}

void Startup::declencher_effet(unigned int possesseur) const{
    /// Effet de la classe Startup
    std::cout << "Activation de l'effet de la startup." << std::endl;
}
