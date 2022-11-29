#include "ChampFleur.h"

ChampFleur::ChampFleur() :
    Batiment("Champ de fleurs",
         2,
        "Recevez une piece de la banque",
        "../../assets/batiments/bleu/ChampFleur.jpg",
        Bleu,
        list<unsigned int>{4},
        "Champ"){};
///Constructeur de ChampFleur

void ChampFleur::declencher_effet() {
    //j'ai délibérément retiré le paramètre joueur actuel de declencher effet pour respecter la méthode virtuelle déclarée dans Batiment.h
    cout<<"declencher effet de ChampFleur";
    /*
    joueur_affecté->set_argent(joueur_affecté->get_argent() + 1);
    //On augmente de un l'argent du joueur actuel
     */
}
