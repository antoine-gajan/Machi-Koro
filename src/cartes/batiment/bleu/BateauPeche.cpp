#include "BateauPeche.h"
BateauPeche::BateauPeche() :
        Batiment("Petit bateau de peche",
                 2,
                 "Si vous avez le port, recevez 3 pieces",
                 "../../assets/batiments/bleu/Petit-bateau-peche.jpg",
                 Bleu,
                 list<unsigned int>{8},
                 "Bateau"){};
///Constructeur de BateauPeche


void BateauPeche::declencher_effet() {
    //j'ai délibérément retiré le paramètre joueur actuel de declencher effet pour respecter la méthode virtuelle déclarée dans Batiment.h
    cout<<"declencher effet de BateauPeche";
    /*
    unsigned int argent = joueur_actuel->get_argent();
    argent+=3;
    joueur_actuel->set_argent(argent);
     */
}
//L'effet est que le joueur reçoit 3 pièces de la banque si 8 tombe à tout moment de la partie
