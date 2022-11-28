#include "Vignoble.h"

Vignoble::Vignoble(const string &path_image) :
            Batiment("Vignoble",
                     3,
                     "Recevez trois pièces de la banque",
                     path_image,
                     Bleu,
                     list<unsigned int>{7},
                     "Champ"){};
///Constructeur de ChampBle

void Vignoble::declencher_effet(Joueur *joueur_affecté) {
    joueur_affecté->set_argent(joueur_affecté->get_argent() + 3);
    //On augmente de un l'argent du joueur actuel
}
