#include "Foret.h"
#include "Partie.h"

Foret::Foret() :
    Batiment("Foret",
         3,
        "Recevez une piece de la banque",
        "../../assets/batiments/bleu/Foret.jpg",
        Bleu,
        list<unsigned int>{5},
        "Engrenage"){}
///Constructeur de Foret

void Foret::declencher_effet(unsigned int possesseur, int bonus) const {

    cout << "Activation de l'effet de Foret" << endl;

    //creation de l'instance de partie
    Partie * partie = Partie::get_instance();
    Joueur* joueur_actuel = partie->get_tab_joueurs().at(possesseur);

    //On augmente de un l'argent du joueur pointe
    joueur_actuel->set_argent(joueur_actuel->get_argent() + 1);
}
