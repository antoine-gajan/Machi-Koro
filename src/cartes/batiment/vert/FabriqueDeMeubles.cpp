#include "FabriqueDeMeubles.h"
#include "Partie.h"

FabriqueDeMeubles::FabriqueDeMeubles()
        : Batiment("FabriqueDeMeubles",
                   3,
                   "Recevez 3 pieces de la banque pour chaque etablissement de type engrenage que vous possedez.",
                   "../../../assets/batiments/Vert/Fabrique-de-meubles.jpg",
                   Vert,
                   {8},
                   "usine") {}


void FabriqueDeMeubles::declencher_effet(unsigned int possesseur, int bonus) const {
    cout << "Activation de l'effet de la carte Fabrique de meubles" << endl;
    /// Effet de la FabriqueDeMeubles
    unsigned int j_act_index =  Partie::get_instance()->get_joueur_actuel();
    Joueur* j_actuel = Partie::get_instance()->get_tab_joueurs()[j_act_index];

    // On compte le nombre d'etablissements de type engrenage
    unsigned int nb_engrenages = j_actuel->count_type("engrenage");

    // On donne 3 pieces par engrenage
    j_actuel->set_argent(j_actuel->get_argent() + 3 * nb_engrenages * (1 + bonus));
}