#include "BanqueDeMinivilles.h"

BanqueDeMinivilles::BanqueDeMinivilles()
        : Batiment("Banque de minivilles",
                   0,
                   "Lorsque vous achetez cet établissement, recevez 5 pièces de la banque. Payez 2 pièces à la banque.",
                   "../../../assets/batiments/Vert/Banque-de-minivilles.jpeg",
                   Vert,
                   {5, 6},
                   "commerce") {}

void BanqueDeMinivilles::declencher_effet() {
    cout << "Déclenchement de l'effet de la carte Banque de minivilles" << endl;
    /*

    /// Effet de l'BanqueDeMinivilles

    // Le don de 5 pièces est géré lors de l'achat de la carte

    /// TRANSACTION AVEC LA BANQUE
    // Le joueur actuel paye 2 pièces à la banque
    Joueur* j_actuel = tab_joueurs[joueur_actuel];

    if (j_actuel->get_argent() >= 2) {
        j_actuel->set_argent(j_actuel->get_argent() - 2);
    }
    else {
        j_actuel->set_argent(0);
    }
*/

}