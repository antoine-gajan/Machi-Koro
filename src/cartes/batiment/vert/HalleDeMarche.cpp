#include "HalleDeMarche.h"

HalleDeMarche::HalleDeMarche()
        : Batiment("HalleDeMarche",
                   2,
                   "Recevez 2 pieces de la banque pour chaque etablissement de type restaurant que vous possedez",
                   "../../../assets/batiments/Vert/Halle-de-marche.jpg",
                   Vert,
                   {12, 13},
                   "usine") {}

void HalleDeMarche::declencher_effet(unigned int possesseur) const {
    cout << "Declenchement de l'effet de la carte Halle de marche" << endl;
    /*
    /// Effet de la HalleDeMarche
    Joueur* j_actuel = tab_joueurs[joueur_actuel];

    // On compte le nombre d'etablissements de type restaurant
    unsigned int nb_restaurant = count_type(j_actuel, "restaurant");

    // On donne 3 pieces par restaurant
    j_actuel->set_argent(j_actuel->get_argent() + 2 * nb_restaurant);
    */
}