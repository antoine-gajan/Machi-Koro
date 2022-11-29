#include "Vignoble.h"

Vignoble::Vignoble() :
    Batiment("Vignoble",
         3,
        "Recevez trois pieces de la banque",
        "../../assets/batiments/bleu/Vignoble.jpg",
        Bleu,
        list<unsigned int>{7},
        "Champ"){};
///Constructeur de Vignoble

void Vignoble::declencher_effet() {
    //j'ai délibérément retiré le paramètre joueur actuel de declencher effet pour respecter la méthode virtuelle déclarée dans Batiment.h
    cout<<"declencher effet de Vignoble";
    /*
    joueur_affecté->set_argent(joueur_affecté->get_argent() + 3);
    //On augmente de un l'argent du joueur actuel
     */
}
