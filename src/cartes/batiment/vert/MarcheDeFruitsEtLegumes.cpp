#include "MarcheDeFruitsEtLegumes.h"

MarcheDeFruitsEtLegumes::MarcheDeFruitsEtLegumes()
        : Batiment("Marché de fruits et légumes",
                   2,
                   "Recevez 2 pièces de la banque pour chaque établissement de type champ que vous possédez.",
                   "../../../assets/batiments/Vert/Marche-de-fruits-et-legumes.jpg",
                   Vert,
                   {11, 12},
                   "marche") {}

void MarcheDeFruitsEtLegumes::declencher_effet() {
    cout << "Déclenchement de l'effet de la carte Marché de fruits et légumes" << endl;
    /*
    /// Effet du MarcheDeFruitsEtLegumes
    Joueur* j_actuel = tab_joueurs[joueur_actuel];

    // On compte le nombre d'etablissements de type champ
    unsigned int nb_champs = count_type(j_actuel, "champ");

    // On donne 2 pièces par champ
    j_actuel->set_argent(j_actuel->get_argent() + 2 * nb_champs);
    */
}