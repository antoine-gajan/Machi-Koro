#include "BanqueDeMinivilles.h"

BanqueDeMinivilles::BanqueDeMinivilles()
        : Batiment("BanqueDeMinivilles",
                   0,
                   "Lorsque vous achetez cet etablissement, recevez 5 pieces de la banque. Payez 2 pieces a la banque.",
                   "../../../assets/batiments/Vert/Banque-de-minivilles.jpg",
                   Vert,
                   {5, 6},
                   "commerce") {}

void BanqueDeMinivilles::declencher_effet(unigned int possesseur) const{
    cout << "Declenchement de l'effet de la carte Banque de minivilles" << endl;
    /*

    /// Effet de l'BanqueDeMinivilles

    // Le don de 5 pieces est gere lors de l'achat de la carte

    /// TRANSACTION AVEC LA BANQUE
    // Le joueur actuel paye 2 pieces a la banque
    Joueur* j_actuel = tab_joueurs[joueur_actuel];

    if (j_actuel->get_argent() >= 2) {
        j_actuel->set_argent(j_actuel->get_argent() - 2);
    }
    else {
        j_actuel->set_argent(0);
    }
*/

}