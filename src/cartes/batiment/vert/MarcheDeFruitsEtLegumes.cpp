#include "MarcheDeFruitsEtLegumes.h"

MarcheDeFruitsEtLegumes::MarcheDeFruitsEtLegumes()
        : Batiment("MarcheDeFruitsEtLegumes",
                   2,
                   "Recevez 2 pieces de la banque pour chaque etablissement de type champ que vous possedez.",
                   "../../../assets/batiments/Vert/Marche-de-fruits-et-legumes.jpg",
                   Vert,
                   {11, 12},
                   "marche") {}

void MarcheDeFruitsEtLegumes::declencher_effet(unsigned int possesseur, int bonus = 0) const{
    cout << "Declenchement de l'effet de la carte Marche de fruits et legumes" << endl;
    /*
    /// Effet du MarcheDeFruitsEtLegumes
    Joueur* j_actuel = tab_joueurs[joueur_actuel];

    // On compte le nombre d'etablissements de type champ
    unsigned int nb_champs = count_type(j_actuel, "champ");

    // On donne 2 pieces par champ
    j_actuel->set_argent(j_actuel->get_argent() + 2 * nb_champs);
    */
}