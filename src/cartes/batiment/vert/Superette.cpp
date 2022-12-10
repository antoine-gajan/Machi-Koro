#include "Superette.h"

Superette::Superette()
        : Batiment("Superette",
                   2,
                   "Recevez 3 piece de la banque.",
                   "../../../assets/batiments/Vert/Superette.jpg",
                   Vert,
                   {4},
                   "commerce") {}

void Superette::declencher_effet(unsigned int possesseur) const{
    cout << "Declenchement de l'effet de la carte Superette" << endl;
    /*
    /// Effet de la Superette
    Joueur* j_actuel = tab_joueurs[joueur_actuel];

    // On donne 3 pieces
    j_actuel->set_argent(j_actuel->get_argent() + 3);
    */
}