#include "Superette.h"

Superette::Superette()
        : Batiment("Supérette",
                   2,
                   "Recevez 3 pièce de la banque.",
                   "../../../assets/batiments/Vert/Superette.jpg",
                   Vert,
                   {4},
                   "commerce") {}

void Superette::declencher_effet() const{
    cout << "Déclenchement de l'effet de la carte Supérette" << endl;
    /*
    /// Effet de la Superette
    Joueur* j_actuel = tab_joueurs[joueur_actuel];

    // On donne 3 pièces
    j_actuel->set_argent(j_actuel->get_argent() + 3);
    */
}