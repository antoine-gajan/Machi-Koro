#include "Ferme.h"

Ferme::Ferme(const string &path_image) : Batiment("Ferme",1
        ,"Recevez une pièce de la banque",path_image,Bleu
        ,list<unsigned int>{2},"Bétail"){};
///Constructeur de Ferme

void Ferme::declencher_effet(Joueur *joueur_affecté) {
    joueur_affecté->set_argent(joueur_affecté->get_argent() + 1);
    //On augmente de un l'argent du joueur pointé
}
