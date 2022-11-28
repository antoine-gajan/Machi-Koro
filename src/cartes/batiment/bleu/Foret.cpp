#include "Foret.h"

Foret::Foret(const string &path_image) :
            Batiment("Forêt",
                     3,
                     "Recevez une pièce de la banque",path_image,
                     Bleu,
                     list<unsigned int>{5},
                     "Engrenage"){};
///Constructeur de Foret

void Foret::declencher_effet(Joueur *joueur_affecté) {
    joueur_affecté->set_argent(joueur_affecté->get_argent() + 1);
    //On augmente de un l'argent du joueur pointé
}
