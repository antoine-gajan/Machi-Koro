#include "Aeroport.h"
#include "Partie.h"

Aeroport::Aeroport() :
    Monument(APRES,
                "Aeroport",
                30,
                "Si rien n'a ete construit durant le tour, la banque donne 10 au joueur",
                "../../assets/monuments/Aeroport-travaux.jpg") {
    /// Constructeur de Aeroport
}

void Aeroport::declencher_effet(unsigned int possesseur, int bonus) const {
    std::cout << "Activation de l'effet de l'aeroport" << std::endl;
    Partie * partie = Partie::get_instance();
    Joueur * joueur = partie->get_tab_joueurs()[possesseur];

    joueur->set_argent(joueur->get_argent() + 10);
}

void Aeroport::activer() {
    set_image("../../assets/monuments/Aeroport-active.jpg");
}