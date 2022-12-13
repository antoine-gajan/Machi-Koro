#include "ChampBle.h"
#include "Partie.h"

ChampBle::ChampBle() :
    Batiment("ChampBle",
        1,
        "Recevez une piece de la banque",
        "../../assets/batiments/bleu/Champs-ble.jpg",
        Bleu,
        list<unsigned int>{1},
        "Champ"){}
///Constructeur de ChampBle

void ChampBle::declencher_effet(unsigned int possesseur, int bonus) const {
    //j'ai deliberement retire le parametre joueur actuel de declencher effet pour respecter la methode virtuelle declaree dans Batiment.h
    cout << "Activation de l'effet de ChampBle" << endl;

    //creation de l'instance de partie
    Partie * partie = Partie::get_instance();
    Joueur* joueur_actuel = partie->get_tab_joueurs()[possesseur];

    //On augmente de un l'argent du joueur actuel
    joueur_actuel->set_argent(joueur_actuel->get_argent() + 1);


}
