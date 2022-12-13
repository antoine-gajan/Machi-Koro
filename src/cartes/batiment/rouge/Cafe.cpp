#include "Cafe.h"
#include "Partie.h"

Cafe::Cafe() :
            Batiment("Cafe",
                     2,
                     "Recevez 1 piece du joueur qui a lance les des",
                     "../../assets/batiments/Rouge/Cafe.jpg",
                     Rouge ,
                     list<unsigned int>{3},
                     "restaurant") {};

void Cafe::declencher_effet(unsigned int possesseur, int bonus) const{

    Partie * partie = Partie::get_instance();
    Joueur* joueur_possesseur = partie->get_tab_joueurs()[possesseur];
    cout << "Activation de l'effet du Cafe du joueur \"" << joueur_possesseur->get_nom()<<"\"" << endl;
    //Trouver un joueur qui a cette carte
    if(partie->get_joueur_actuel() != possesseur){
        if(partie->transfert_argent(possesseur, partie->get_joueur_actuel(), 1+bonus)){
            return;
        }
    }
}



