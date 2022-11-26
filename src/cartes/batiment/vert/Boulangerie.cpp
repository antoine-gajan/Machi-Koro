#include "Boulangerie.h"

Boulangerie::Boulangerie(string path_image)
        : Batiment("Boulangerie",
                   1,
                   "Recevez une pièce de la banque.",
                   path_image,
                   Vert,
                   {2, 3},
                   "commerce") {}


void Boulangerie::declencher_effet(vector<Joueur *> &tab_joueurs, unsigned int joueur_actuel) {
    /// Effet de la Boulangerie
    Joueur* j_actuel = tab_joueurs[joueur_actuel];

    j_actuel->set_argent(j_actuel->get_argent() + 1);
}