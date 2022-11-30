#include "Epicerie.h"

Epicerie::Epicerie()
        : Batiment("Épicerie",
                   0,
                   "Si vous possédez moins de deux monuments, recevez 2 pièces de la banque.",
                   "../../../assets/batiments/Vert/Epicerie.jpg",
                   Vert,
                   {2},
                   "commerce") {}

void Epicerie::declencher_effet() {
    cout << "Déclenchement de l'effet de la carte Épicerie" << endl;
    /*
    /// Effet de l'Epicerie
    Joueur* j_actuel = tab_joueurs[joueur_actuel];

    if (j_actuel->get_monument_jouables().size() < 2){
        j_actuel->set_argent(j_actuel->get_argent() + 2);
    }
*/
}