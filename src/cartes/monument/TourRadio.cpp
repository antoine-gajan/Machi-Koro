#include "TourRadio.h"
#include "Partie.h"

TourRadio::TourRadio() :
    Monument(APRES,
             "TourRadio",
             22,
             "Une fois par tour vous pouvez relancer vos des",
             "../../assets/monuments/TourRadio-travaux.png") {
    /// Constructeur de TourRadio
}

void TourRadio::declencher_effet(unsigned int possesseur, int bonus) const {
    cout << "Activation de l'effet de la Tour radio" << endl;
    Partie *partie = Partie::get_instance();
    int choix = -1;

    if (partie->get_tab_joueurs()[possesseur]->get_est_ia()) {
        choix = rand() % 2;
    }
    else {
        while (choix != 0 && choix != 1) {
            cout << "Voulez-vous relancer vos dés ? (0 : non, 1 : oui)" << endl;
            cin >> choix;
        }
    }

    if(choix == 1) {
        partie->set_de_1(1 + (rand() % 6));
        if (partie->get_de_2() != 0) {
            partie->set_de_2(1 + (rand() % 6));
        }
    }

}

void TourRadio::activer(){
    set_image("../../assets/monuments/TourRadio-active.png");
}