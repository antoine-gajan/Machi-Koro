#include "HalleDeMarche.h"

HalleDeMarche::HalleDeMarche(const string& path_image)
        : Batiment("Halle de marché",
                   2,
                   "Recevez 2 pièces de la banque pour chaque établissement de type restaurant que vous possédez",
                   path_image,
                   Vert,
                   {12, 13},
                   "usine") {}

void HalleDeMarche::declencher_effet(vector<Joueur *> &tab_joueurs, unsigned int joueur_actuel) {
    /// Effet de la HalleDeMarche
    Joueur* j_actuel = tab_joueurs[joueur_actuel];

    // On compte le nombre d'etablissements de type restaurant
    unsigned int nb_restaurant = count_type(j_actuel, "restaurant");

    // On donne 3 pièces par restaurant
    j_actuel->set_argent(j_actuel->get_argent() + 2 * nb_restaurant);
}