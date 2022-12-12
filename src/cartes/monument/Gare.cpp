#include "Gare.h"
#include "Partie.h"

Gare::Gare()
    : Monument(AVANT,
               "Gare",
               4,
               "Vous pouvez lancer 2 des",
               "../../assets/monuments/Gare-travaux.png") {
    /// Constructeur de Gare
}

void Gare::declencher_effet(unsigned int possesseur, int bonus) const {
    cout << "Activation de l'effet de la gare" << endl;
    Partie *partie = Partie::get_instance();
    if (partie->get_tab_joueurs()[possesseur]->get_est_ia()) {
        int choix = rand() % 4;
        if (choix != 0) {
            partie->set_de_2((rand() % 6) + 1);
        }
    }
    else {
        int choix = -1;
        while (choix != 0 && choix != 1) {
            cout << "Voulez-vous lancer 2 des ? (0 : non, 1 : oui)" << endl;
            cin >> choix;
        }
        if (choix == 1) {
            partie->set_de_2((rand() % 6) + 1);
        }
    }
}

void Gare::activer() {
    set_image("../../assets/monuments/Gare-active.png");
}