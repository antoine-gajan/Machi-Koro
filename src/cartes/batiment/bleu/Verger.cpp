#include "Verger.h"

Verger::Verger(const string &path_image) :
            Batiment("Verger",
                     3,
                     "Recevez trois pièces de la banque",
                     path_image,
                     Bleu,
                     list<unsigned int>{10},
                     "Champ"){};
///Constructeur de Verger

void Verger::declencher_effet(Joueur *joueur_affecté) {
    joueur_affecté->set_argent(joueur_affecté->get_argent() + 3);
    //On augmente de un l'argent du joueur actuel
}
