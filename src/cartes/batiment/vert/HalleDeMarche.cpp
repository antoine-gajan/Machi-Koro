#include "HalleDeMarche.h"
#include "Partie.h"

HalleDeMarche::HalleDeMarche()
        : Batiment("HalleDeMarche",
                   2,
                   "Recevez 2 pieces de la banque pour chaque etablissement de type restaurant que vous possedez",
                   "../../../assets/batiments/Vert/Halle-de-marche.jpg",
                   Vert,
                   {12, 13},
                   "usine") {}

void HalleDeMarche::declencher_effet(unsigned int possesseur, int bonus) const {
    cout << "Declenchement de l'effet de la carte Halle de marche" << endl;
    /// Effet de la HalleDeMarche
    unsigned int j_act_index =  Partie::get_instance()->get_joueur_actuel();
    Joueur* j_actuel = Partie::get_instance()->get_tab_joueurs()[j_act_index];

    // On compte le nombre d'etablissements de type restaurant
    unsigned int nb_restaurant = j_actuel->count_type("restaurant");

    // On donne 2 pieces par restaurant
    j_actuel->set_argent(j_actuel->get_argent() + 2 * nb_restaurant * (1 + bonus));
}