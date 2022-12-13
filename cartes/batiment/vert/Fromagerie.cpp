#include "Fromagerie.h"

Fromagerie::Fromagerie()
        : Batiment("Fromagerie",
                   5,
                   "Recevez 3 pieces de la banque pour chaque etablissement de type betail que vous possedez.",
                   "../../../assets/batiments/Vert/Fromagerie.jpg",
                   Vert,
                   {7},
                   "usine") {}

void Fromagerie::declencher_effet(unsigned int possesseur, int bonus) const {
    cout << "Declenchement de l'effet de la carte Fromagerie" << endl;
    /*
    /// Effet de la Fromagerie
    Joueur* j_actuel = tab_joueurs[joueur_actuel];

    // On compte le nombre d'etablissements de type betail
    unsigned int nb_betail = count_type(j_actuel, "betail");

    // On donne 3 pieces par betail
    j_actuel->set_argent(j_actuel->get_argent() + 3 * nb_betail);
    */
}