#include "Ferme.h"
#include "Partie.h"

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

    cout << "Activation de l'effet de Ferme" << endl;

    //creation de l'instance de partie
    Partie * partie = Partie::get_instance();
    Joueur* joueur_actuel = partie->get_tab_joueurs()[possesseur];

    //On augmente de un l'argent du joueur pointe
    joueur_actuel->set_argent(joueur_actuel->get_argent() + 1);
}
