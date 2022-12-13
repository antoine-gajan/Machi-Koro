#include "MoonsterSoda.h"

MoonsterSoda::MoonsterSoda()
        : Batiment("MoonsterSoda",
                   5,
                   "Recevez 1 piece de la banque pour chaque etablissement de type restaurant que possedent tous les joueurs.",
                   "../../../assets/batiments/Vert/Moonster-soda.jpg",
                   Vert,
                   {11},
                   "usine") {}

void MoonsterSoda::declencher_effet(unsigned int possesseur, int bonus) const {
    cout << "Declenchement de l'effet de la carte MoonsterSoda" << endl;
    /*
    /// Effet du MoonsterSoda
    Joueur* j_actuel = tab_joueurs[joueur_actuel];

    // On compte le nombre d'etablissements de type restaurant de tous les joueurs
    unsigned int nb_restaurants = 0;
    for (Joueur* j : tab_joueurs) {
        nb_restaurants += count_type(j, "restaurant");
    }

    // On donne 1 piece par restaurant
    j_actuel->set_argent(j_actuel->get_argent() + nb_restaurants);
    */
}