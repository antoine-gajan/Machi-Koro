#include "Mine.h"

Mine::Mine() :
    Batiment("Mine",
         6,
        "Recevez cinq pieces de la banque",
        "../../assets/batiments/bleu/Mine.jpg",
        Bleu,
        list<unsigned int>{9},
        "Engrenage"){};
///Constructeur de Mine

void Mine::declencher_effet(unigned int possesseur) const{
    //j'ai deliberement retire le parametre joueur actuel de declencher effet pour respecter la methode virtuelle declaree dans Batiment.h
    cout << "Activation de l'effet de Mine" << endl;
    /*
    joueur_affecte->set_argent(joueur_affecte->get_argent() + 5);
    //On augmente de un l'argent du joueur actuel
     */
}
