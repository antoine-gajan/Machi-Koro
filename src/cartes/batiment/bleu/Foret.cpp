#include "Foret.h"

Foret::Foret() :
    Batiment("Foret",
         3,
        "Recevez une piece de la banque",
        "../../assets/batiments/bleu/Foret.jpg",
        Bleu,
        list<unsigned int>{5},
        "Engrenage"){};
///Constructeur de Foret

void Foret::declencher_effet() {
    //j'ai délibérément retiré le paramètre joueur actuel de declencher effet pour respecter la méthode virtuelle déclarée dans Batiment.h
    cout<<"declencher effet de Foret";
    /*
    joueur_affecté->set_argent(joueur_affecté->get_argent() + 1);
    //On augmente de un l'argent du joueur pointé
     */
}
