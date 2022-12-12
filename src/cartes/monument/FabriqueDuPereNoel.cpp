#include "FabriqueDuPereNoel.h"
#include "Partie.h"

FabriqueDuPereNoel::FabriqueDuPereNoel() :
        Monument(APRES,
                 "FabriqueDuPereNoel",
                 0,
                 "Si le jet de de est casse vous gagnez 3 pieces",
                 "../../assets/monuments/FabriqueDuPereNoel.png") {
    /// Constructeur de Centre commercial
}

void FabriqueDuPereNoel::declencher_effet(unsigned int possesseur, int bonus) const {
    cout << "Activation de l'effet de la Fabrique du Pere Noel" << endl;
    Partie *partie = Partie::get_instance();
    Joueur *joueur = partie->get_tab_joueurs()[possesseur];
    joueur->set_argent(joueur->get_argent() + 3);

    partie->set_de_1((rand() % 6) + 1);
    if (partie->get_de_2() != 0) {
        partie->set_de_2((rand() % 6) + 1);
    }
}

void FabriqueDuPereNoel::activer() {
    set_image("../../assets/monuments/FabriqueDuPereNoel.png");
}