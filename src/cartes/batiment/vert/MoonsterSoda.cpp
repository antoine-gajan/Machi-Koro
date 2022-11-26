#include "MoonsterSoda.h"

MoonsterSoda::MoonsterSoda(const string& path_image)
        : Batiment("Moonster soda",
                   5,
                   "Recevez 1 pièce de la banque pour chaque établissement de type restaurant que possèdent tous les joueurs.",
                   path_image,
                   Vert,
                   {11},
                   "usine") {}

void MoonsterSoda::declencher_effet(vector<Joueur *> &tab_joueurs, unsigned int joueur_actuel) {
    /// Effet du MoonsterSoda
    Joueur* j_actuel = tab_joueurs[joueur_actuel];

    // On compte le nombre d'etablissements de type restaurant de tous les joueurs
    unsigned int nb_restaurants = 0;
    for (Joueur* j : tab_joueurs) {
        nb_restaurants += count_type(j, "restaurant");
    }

    // On donne 1 pièce par restaurant
    j_actuel->set_argent(j_actuel->get_argent() + nb_restaurants);
}