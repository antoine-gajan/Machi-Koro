#include "Fromagerie.h"

Fromagerie::Fromagerie(const string& path_image)
        : Batiment("Fromagerie",
                   5,
                   "Recevez 3 pièces de la banque pour chaque établissement de type betail que vous possédez.",
                   path_image,
                   Vert,
                   {7},
                   "usine") {}

void Fromagerie::declencher_effet(vector<Joueur *> &tab_joueurs, unsigned int joueur_actuel) {
    /// Effet de la Fromagerie
    Joueur* j_actuel = tab_joueurs[joueur_actuel];

    // On compte le nombre d'etablissements de type betail
    unsigned int nb_betail = count_type(j_actuel, "betail");

    // On donne 3 pièces par betail
    j_actuel->set_argent(j_actuel->get_argent() + 3 * nb_betail);
}