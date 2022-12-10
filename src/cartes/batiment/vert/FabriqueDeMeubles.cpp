#include "FabriqueDeMeubles.h"

FabriqueDeMeubles::FabriqueDeMeubles()
        : Batiment("FabriqueDeMeubles",
                   3,
                   "Recevez 3 pieces de la banque pour chaque etablissement de type engrenage que vous possedez.",
                   "../../../assets/batiments/Vert/Fabrique-de-meubles.jpg",
                   Vert,
                   {8},
                   "usine") {}


void FabriqueDeMeubles::declencher_effet(unsigned int possesseur) const {
    cout << "Declenchement de l'effet de la carte Fabrique de meubles" << endl;
    /*
    /// Effet de la FabriqueDeMeubles
    Joueur* j_actuel = tab_joueurs[joueur_actuel];

    // On compte le nombre d'etablissements de type engrenage
    unsigned int nb_engrenages = count_type(j_actuel, "engrenage");

    // On donne 3 pieces par engrenage
    j_actuel->set_argent(j_actuel->get_argent() + 3 * nb_engrenages);
    */
}