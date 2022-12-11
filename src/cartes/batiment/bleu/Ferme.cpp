#include "Ferme.h"

Ferme::Ferme() :
    Batiment("Ferme",
         1,
        "Recevez une piece de la banque",
        "../../assets/batiments/bleu/Ferme.jpg",
        Bleu,
        list<unsigned int>{2},
        "Betail"){}
///Constructeur de Ferme

void Ferme::declencher_effet(unsigned int possesseur, int bonus) const {
    //j'ai deliberement retire le parametre joueur actuel de declencher effet pour respecter la methode virtuelle declaree dans Batiment.h
    cout << "Activation de l'effet de Ferme" << endl;
    /*
    joueur_affecte->set_argent(joueur_affecte->get_argent() + 1);
    //On augmente de un l'argent du joueur pointe
     */
}
