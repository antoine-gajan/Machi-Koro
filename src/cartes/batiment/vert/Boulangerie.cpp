#include "Boulangerie.h"

Boulangerie::Boulangerie()
        : Batiment("Boulangerie",
                   1,
                   "Recevez une pièce de la banque.",
                   "../../../assets/batiments/Vert/Boulangerie.jpg",
                   Vert,
                   {2, 3},
                   "commerce") {}


void Boulangerie::declencher_effet() const {
    cout << "Déclenchement de l'effet de la carte Boulangerie" << endl;
    /*
    /// Effet de la Boulangerie
    Joueur* j_actuel = tab_joueurs[joueur_actuel];

    j_actuel->set_argent(j_actuel->get_argent() + 1);
    */
}