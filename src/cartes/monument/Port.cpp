#include "Port.h"
#include "Partie.h"

Port::Port()
        : Monument(PENDANT,
                   "Port",
                   2,
                   "Si le resultat du jet de de est superieur ou egal a 10, vous pouvez ajouter 2 a ce resultat.",
                   "../../assets/monuments/Port-travaux.png") {
    /// Constructeur de Port
}

void Port::declencher_effet(unsigned int possesseur, int bonus) const {
    std::cout << "Activation de l'effet du Port" << std::endl;
    Partie *partie = Partie::get_instance();
    if (partie->get_de_1() + partie->get_de_2() >= 10) {
        int choix = -1;
        while (choix != 0 && choix != 1) {
            std::cout << "Voulez-vous ajouter 2 au resultat du jet de de ? (0 : non, 1 : oui)" << std::endl;
            std::cin >> choix;
        }
        if (choix == 1) {
            partie->set_de_1(partie->get_de_1() + 1);
            partie->set_de_2(partie->get_de_2() + 1);
        }
    }
}

void Port::activer() {
    set_image("../../assets/monuments/Port-active.png");
}