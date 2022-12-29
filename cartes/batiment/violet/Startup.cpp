#include "Startup.h"
#include "Partie.h"

Startup::Startup() :
        Batiment("Startup",
                 1,
                 "Recevez 1 piece de la banque pour chaque piece placee sur l'ensemble de tous les joueurs. A la fin de votre tour, placez une piece sur votre Startup.",
                 "../assets/batiments/Violet/Startup.png",
                 Violet,
                 list<unsigned int>{10},
                 "special") {
    ///Constructeur de Startup
}

void Startup::declencher_effet(unsigned int possesseur, int bonus) const{
    /// Effet de la classe Startup
    Partie *partie = Partie::get_instance();
    partie->get_vue_partie()->get_vue_infos()->add_info("Activation de l'effet de la startup.");
}
