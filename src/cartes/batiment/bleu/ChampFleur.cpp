#include "ChampFleur.h"

ChampFleur::ChampFleur() :
    Batiment("Champ de fleurs",
         2,
        "Recevez une piece de la banque",
        "../../assets/batiments/bleu/ChampFleur.jpeg",
        Bleu,
        list<unsigned int>{4},
        "Champ"){};
///Constructeur de ChampFleur

void ChampFleur::declencher_effet() const {
    //j'ai deliberement retire le parametre joueur actuel de declencher effet pour respecter la methode virtuelle declaree dans Batiment.h
    cout<<"declencher effet de ChampFleur";
    /*
    joueur_affecte->set_argent(joueur_affecte->get_argent() + 1);
    //On augmente de un l'argent du joueur actuel
     */
}
