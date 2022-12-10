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

void Vignoble::declencher_effet(unsigned int possesseur) const {
    //j'ai deliberement retire le parametre joueur actuel de declencher effet pour respecter la methode virtuelle declaree dans Batiment.h
    cout << "Activation de l'effet de Vignoble" << endl;
    /*
    joueur_affecte->set_argent(joueur_affecte->get_argent() + 3);
    //On augmente de un l'argent du joueur actuel
     */
}
