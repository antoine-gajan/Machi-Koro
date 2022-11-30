#include "FabriqueDeMeubles.h"

FabriqueDeMeubles::FabriqueDeMeubles()
        : Batiment("Fabrique de meubles",
                   3,
                   "Recevez 3 pièces de la banque pour chaque établissement de type engrenage que vous possédez.",
                   "../../../assets/batiments/Vert/Fabrique-de-meubles.jpeg",
                   Vert,
                   {8},
                   "usine") {}


void FabriqueDeMeubles::declencher_effet() {
    cout << "Déclenchement de l'effet de la carte Fabrique de meubles" << endl;
    /*
    /// Effet de la FabriqueDeMeubles
    Joueur* j_actuel = tab_joueurs[joueur_actuel];

    // On compte le nombre d'etablissements de type engrenage
    unsigned int nb_engrenages = count_type(j_actuel, "engrenage");

    // On donne 3 pièces par engrenage
    j_actuel->set_argent(j_actuel->get_argent() + 3 * nb_engrenages);
    */
}