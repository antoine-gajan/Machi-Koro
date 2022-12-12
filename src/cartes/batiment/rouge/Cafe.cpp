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
    cout << "Activation de l'effet du cafe" << endl;
    Partie * partie = Partie::get_instance();
    Joueur* joueur_actuel = partie->get_tab_joueurs().at(possesseur);
    //Trouver un joueur qui a cette carte
    for (unsigned int i = 0; i < partie->get_tab_joueurs().size(); i++){
        if (partie->get_tab_joueurs().at(i)->possede_batiment("Cafe") && i!=possesseur){
            if(partie->transfert_argent(possesseur, i, 1)){
                return;
            }
        }
    }

}



