#include "Fleuriste.h"

Fleuriste::Fleuriste()
        : Batiment("Fleuriste",
                   1,
                   "Recevez 1 pièce de la banque pour chaque Champ de fleurs que vous possédez.",
                   "../../../assets/batiments/Vert/Fleuriste.jpeg",
                   Vert,
                   {6},
                   "commerce") {}

void Fleuriste::declencher_effet() {
    cout << "Déclenchement de l'effet de la carte Fleuriste" << endl;
    /*
    /// Effet de la FabriqueDeMeubles
    Joueur* j_actuel = tab_joueurs[joueur_actuel];

    unsigned int nb_champs_fleur = 0;

    // liste des batiments bleus du joueur
    map<Batiment*, unsigned int> liste_bat_bleu = j_actuel->get_liste_batiment().find("Bleu")->second;

    // si le joueur possède des champs de fleurs
    map<Batiment*, unsigned int>::iterator it;
    for (it=liste_bat_bleu.begin(); it!=liste_bat_bleu.end(); ++it) {
        if (it->first->get_nom() == "Champ de fleurs") {
            nb_champs_fleur += it->second;
            break;
        }
    }

    // on donne 1 pièce par champ de fleur
    j_actuel->set_argent(j_actuel->get_argent() + nb_champs_fleur);
    */
}