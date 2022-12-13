#include "ChampMais.h"
#include "Partie.h"

ChampMais::ChampMais() :
    Batiment("ChampMais",
         2,
        "Recevez une piece de la banque si vous avez moins de deux monuments construits",
        "../../assets/batiments/bleu/ChampMais.jpg",
        Bleu,
        list<unsigned int>{3,4},
        "Champ"){}
///Constructeur de Ferme

void ChampMais::declencher_effet(unsigned int possesseur, int bonus) const{

    cout << "Activation de l'effet de ChampMais" << endl;

    //creation de l'instance de partie
    Partie * partie = Partie::get_instance();
    Joueur* joueur_actuel = partie->get_tab_joueurs()[possesseur];

    //On augmente de un l'argent du joueur pointe s'il a moins de deux monuments construits
    if(joueur_actuel->get_liste_monument().size() < 2)joueur_actuel->set_argent(joueur_actuel->get_argent() + 1);

}
