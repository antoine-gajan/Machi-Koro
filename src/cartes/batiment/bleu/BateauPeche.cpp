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


void BateauPeche::declencher_effet() const{
    //j'ai deliberement retire le parametre joueur actuel de declencher effet pour respecter la methode virtuelle declaree dans Batiment.h
    cout<<"declencher effet de BateauPeche";
    /*
    unsigned int argent = joueur_actuel->get_argent();
    argent+=3;
    joueur_actuel->set_argent(argent);
     */
}
//L'effet est que le joueur reçoit 3 pieces de la banque si 8 tombe a tout moment de la partie
