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

void Foret::declencher_effet(unsigned int possesseur, int bonus = 0) const {
    //j'ai deliberement retire le parametre joueur actuel de declencher effet pour respecter la methode virtuelle declaree dans Batiment.h
    cout << "Activation de l'effet de Foret" << endl;
    /*
    joueur_affecte->set_argent(joueur_affecte->get_argent() + 1);
    //On augmente de un l'argent du joueur pointe
     */
}
