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

void Verger::declencher_effet(unigned int possesseur) const {
    //j'ai deliberement retire le parametre joueur actuel de declencher effet pour respecter la methode virtuelle declaree dans Batiment.h
    cout << "Activation de l'effet de Verger" << endl;
    /*
    joueur_affecte->set_argent(joueur_affecte->get_argent() + 3);
    //On augmente de un l'argent du joueur actuel
    */
}
