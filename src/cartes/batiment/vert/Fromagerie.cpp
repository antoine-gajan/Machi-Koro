#include "Fromagerie.h"
#include "Partie.h"

Fromagerie::Fromagerie()
        : Batiment("Fromagerie",
                   5,
                   "Recevez 3 pieces de la banque pour chaque etablissement de type betail que vous possedez.",
                   "../../../assets/batiments/Vert/Fromagerie.jpg",
                   Vert,
                   {7},
                   "usine") {}

void Fromagerie::declencher_effet(unsigned int possesseur, int bonus) const {
    cout << "Activation de l'effet de la carte Fromagerie" << endl;
    /// Effet de la Fromagerie
    unsigned int j_act_index =  Partie::get_instance()->get_joueur_actuel();
    Joueur* j_actuel = Partie::get_instance()->get_tab_joueurs()[j_act_index];

    // On compte le nombre d'etablissements de type betail
    unsigned int nb_betail = j_actuel->count_type("betail");

    // On donne 3 pieces par betail
    j_actuel->set_argent(j_actuel->get_argent() + 3 * nb_betail * (1 + bonus));
}