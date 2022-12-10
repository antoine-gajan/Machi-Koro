#include "ChampBle.h"

ChampBle::ChampBle() :
    Batiment("ChampBle",
        1,
        "Recevez une piece de la banque",
        "../../assets/batiments/bleu/Champs-ble.jpg",
        Bleu,
        list<unsigned int>{1},
        "Champ"){};
///Constructeur de ChampBle

void ChampBle::declencher_effet(unsigned int possesseur) const {
    //j'ai deliberement retire le parametre joueur actuel de declencher effet pour respecter la methode virtuelle declaree dans Batiment.h
    cout << "Activation de l'effet de ChampBle" << endl;
    /*
    joueur_affecte->set_argent(joueur_affecte->get_argent() + 1);
    //On augmente de un l'argent du joueur actuel
     */
}
