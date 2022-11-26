#include "Epicerie.h"

Epicerie::Epicerie(const string& path_image)
        : Batiment("Épicerie",
                   0,
                   "Si vous possédez moins de deux monuments, recevez 2 pièces de la banque.",
                   path_image,
                   Vert,
                   {2},
                   "commerce") {}

void Epicerie::declencher_effet(vector<Joueur *> &tab_joueurs, unsigned int joueur_actuel) {
    /// Effet de l'Epicerie
    Joueur* j_actuel = tab_joueurs[joueur_actuel];

    if (j_actuel->get_monuments_jouables().size() < 2){
        j_actuel->set_argent(j_actuel->get_argent() + 2);
    }

}