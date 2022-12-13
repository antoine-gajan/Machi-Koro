#include "PetitBateauDePeche.h"
PetitBateauDePeche::PetitBateauDePeche() :
        Batiment("PetitBateauDePeche",
                 2,
                 "Si vous avez le port, recevez 3 pieces",
                 "../../assets/batiments/bleu/Petit-bateau-peche.jpg",
                 Bleu,
                 list<unsigned int>{8},
                 "Bateau"){};
///Constructeur de BateauPeche


void PetitBateauDePeche::declencher_effet(unsigned int possesseur, int bonus) const{
    //j'ai deliberement retire le parametre joueur actuel de declencher effet pour respecter la methode virtuelle declaree dans Batiment.h
    cout << "Activation de l'effet de BateauPeche" << endl;
    /*
    unsigned int argent = joueur_actuel->get_argent();
    argent+=3;
    joueur_actuel->set_argent(argent);
     */
}
//L'effet est que le joueur reçoit 3 pieces de la banque si 8 tombe a tout moment de la partie
