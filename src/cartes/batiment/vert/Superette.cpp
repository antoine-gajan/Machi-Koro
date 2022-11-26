#include "Superette.h"

Superette::Superette(const string& path_image)
        : Batiment("Supérette",
                   2,
                   "Recevez 3 pièce de la banque.",
                   path_image,
                   Vert,
                   {4},
                   "commerce") {}

void Superette::declencher_effet(vector<Joueur *> &tab_joueurs, unsigned int joueur_actuel) {
    /// Effet de la Superette
    Joueur* j_actuel = tab_joueurs[joueur_actuel];

    // On donne 3 pièces
    j_actuel->set_argent(j_actuel->get_argent() + 3);
}