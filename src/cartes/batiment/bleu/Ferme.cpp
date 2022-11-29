#include "Ferme.h"

Ferme::Ferme() :
    Batiment("Ferme",
         1,
        "Recevez une piece de la banque",
        "../../assets/batiments/bleu/Ferme.jpg",
        Bleu,
        list<unsigned int>{2},
        "Betail"){};
///Constructeur de Ferme

void Ferme::declencher_effet() {
    //j'ai délibérément retiré le paramètre joueur actuel de declencher effet pour respecter la méthode virtuelle déclarée dans Batiment.h
    cout<<"declencher effet de Ferme";
    /*
    joueur_affecté->set_argent(joueur_affecté->get_argent() + 1);
    //On augmente de un l'argent du joueur pointé
     */
}
