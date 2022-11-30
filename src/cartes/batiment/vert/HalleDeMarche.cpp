#include "HalleDeMarche.h"

HalleDeMarche::HalleDeMarche()
        : Batiment("Halle de marché",
                   2,
                   "Recevez 2 pièces de la banque pour chaque établissement de type restaurant que vous possédez",
                   "../../../assets/batiments/Vert/Halle-de-marche.jpg",
                   Vert,
                   {12, 13},
                   "usine") {}

void HalleDeMarche::declencher_effet() {
    cout << "Déclenchement de l'effet de la carte Halle de marché" << endl;
    /*
    /// Effet de la HalleDeMarche
    Joueur* j_actuel = tab_joueurs[joueur_actuel];

    // On compte le nombre d'etablissements de type restaurant
    unsigned int nb_restaurant = count_type(j_actuel, "restaurant");

    // On donne 3 pièces par restaurant
    j_actuel->set_argent(j_actuel->get_argent() + 2 * nb_restaurant);
    */
}