#include "ChampBle.h"

ChampBle::ChampBle(const string &path_image) :
        Batiment("Champ de blé",
                 0,
                 "Recevez une pièce de la banque",
                 path_image,
                 Bleu,
                 list<unsigned int>{1},
                 "Champ"){};
///Constructeur de ChampBle

void ChampBle::declencher_effet(Joueur *joueur_affecté) {
    joueur_affecté->set_argent(joueur_affecté->get_argent() + 1);
    //On augmente de un l'argent du joueur actuel
}
