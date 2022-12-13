#include "ChampFleur.h"
#include "Partie.h"

ChampFleur::ChampFleur() :
    Batiment("ChampFleur",
         2,
        "Recevez une piece de la banque",
        "../../assets/batiments/bleu/ChampFleur.jpg",
        Bleu,
        list<unsigned int>{4},
        "Champ"){}
///Constructeur de ChampFleur

void ChampFleur::declencher_effet(unsigned int possesseur, int bonus) const {
    cout << "Activation de l'effet de ChampFleur" << endl;

    //creation de l'instance de partie
    Partie * partie = Partie::get_instance();
    Joueur* joueur_actuel = partie->get_tab_joueurs()[possesseur];

    //On augmente de un l'argent du joueur actuel
    joueur_actuel->set_argent(joueur_actuel->get_argent() + 1);
}
