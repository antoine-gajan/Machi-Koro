#include "ChampFleur.h"

ChampFleur::ChampFleur(string &path_image) : Batiment("Champ de fleurs",2
        ,"Recevez une pièce de la banque",path_image,Bleu
        ,list<unsigned int>{4},"Champ"){};
///Constructeur de ChampFleur

void ChampFleur::declencher_effet(Joueur *joueur_affecté) {
    joueur_affecté->set_argent(joueur_affecté->get_argent() + 1);
    //On augmente de un l'argent du joueur actuel
}
