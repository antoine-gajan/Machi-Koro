#include "Epicerie.h"

Epicerie::Epicerie()
        : Batiment("Epicerie",
                   0,
                   "Si vous possedez moins de deux monuments, recevez 2 pieces de la banque.",
                   "../../../assets/batiments/Vert/Epicerie.jpg",
                   Vert,
                   {2},
                   "commerce") {}

void Epicerie::declencher_effet(unigned int possesseur) const{
    cout << "Declenchement de l'effet de la carte Epicerie" << endl;
    /*
    /// Effet de l'Epicerie
    Joueur* j_actuel = tab_joueurs[joueur_actuel];

    if (j_actuel->get_monument_jouables().size() < 2){
        j_actuel->set_argent(j_actuel->get_argent() + 2);
    }
*/
}