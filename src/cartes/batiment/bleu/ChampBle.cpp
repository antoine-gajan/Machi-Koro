#include "ChampBle.h"

ChampBle::ChampBle() :
    Batiment("Champ de ble",
        1,
        "Recevez une piece de la banque",
        "../../assets/batiments/bleu/Champs-ble.jpg",
        Bleu,
        list<unsigned int>{1},
        "Champ"){};
///Constructeur de ChampBle

void ChampBle::declencher_effet() {
    //j'ai délibérément retiré le paramètre joueur actuel de declencher effet pour respecter la méthode virtuelle déclarée dans Batiment.h
    cout<<"declencher effet de ChampBle";
    /*
    joueur_affecté->set_argent(joueur_affecté->get_argent() + 1);
    //On augmente de un l'argent du joueur actuel
     */
}
