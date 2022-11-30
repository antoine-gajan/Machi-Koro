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

void Mine::declencher_effet() const{
    //j'ai délibérément retiré le paramètre joueur actuel de declencher effet pour respecter la méthode virtuelle déclarée dans Batiment.h
    cout<<"declencher effet de Mine";
    /*
    joueur_affecté->set_argent(joueur_affecté->get_argent() + 5);
    //On augmente de un l'argent du joueur actuel
     */
}
