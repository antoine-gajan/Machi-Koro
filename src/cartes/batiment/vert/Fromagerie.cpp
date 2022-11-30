#include "Fromagerie.h"

Fromagerie::Fromagerie()
        : Batiment("Fromagerie",
                   5,
                   "Recevez 3 pièces de la banque pour chaque établissement de type betail que vous possédez.",
                   "../../../assets/batiments/Vert/Fromagerie.jpeg",
                   Vert,
                   {7},
                   "usine") {}

void Fromagerie::declencher_effet() {
    cout << "Déclenchement de l'effet de la carte Fromagerie" << endl;
    /*
    /// Effet de la Fromagerie
    Joueur* j_actuel = tab_joueurs[joueur_actuel];

    // On compte le nombre d'etablissements de type betail
    unsigned int nb_betail = count_type(j_actuel, "betail");

    // On donne 3 pièces par betail
    j_actuel->set_argent(j_actuel->get_argent() + 3 * nb_betail);
    */
}