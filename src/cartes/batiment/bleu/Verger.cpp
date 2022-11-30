#include "Verger.h"

Verger::Verger() :
    Batiment("Verger",
         3,
        "Recevez trois pieces de la banque",
        "../../assets/batiments/bleu/Verger.jpg",
        Bleu,
        list<unsigned int>{10},
        "Champ"){};
///Constructeur de Verger

void Verger::declencher_effet() const {
    //j'ai délibérément retiré le paramètre joueur actuel de declencher effet pour respecter la méthode virtuelle déclarée dans Batiment.h
    cout<<"declencher effet de Verger";
    /*
    joueur_affecté->set_argent(joueur_affecté->get_argent() + 3);
    //On augmente de un l'argent du joueur actuel
    */
}
