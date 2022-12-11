#include "Superette.h"
#include "Partie.h"

Superette::Superette()
        : Batiment("Superette",
                   2,
                   "Recevez 3 piece de la banque.",
                   "../../../assets/batiments/Vert/Superette.jpg",
                   Vert,
                   {4},
                   "commerce") {}

void Superette::declencher_effet(unsigned int possesseur, int bonus) const{
    cout << "Activation de l'effet de la carte Superette" << endl;
    /// Effet de la Superette
    unsigned int j_act_index =  Partie::get_instance()->get_joueur_actuel();
    Joueur* j_actuel = Partie::get_instance()->get_tab_joueurs()[j_act_index];

    // On donne 3 pieces
    j_actuel->set_argent(j_actuel->get_argent() + 3 + bonus);
}