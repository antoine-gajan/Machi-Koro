#include "Mine.h"

Mine::Mine(string &path_image) : Batiment("Mine",6
        ,"Recevez cinq pièces de la banque",path_image,Bleu
        ,list<unsigned int>{9},"Engrenage"){};
///Constructeur de Mine

void Mine::declencher_effet(Joueur *joueur_affecté) {
    joueur_affecté->set_argent(joueur_affecté->get_argent() + 5);
    //On augmente de un l'argent du joueur actuel
}
