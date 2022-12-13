#include "Restaurant.h"
#include "Partie.h"

Restaurant::Restaurant() :
            Batiment("Restaurant",
                     3,
                     "Recevez 2 pieces du joueur qui a lance les des",
                     "../../assets/batiments/Rouge/Restaurant.jpg",
                     Rouge ,
                     list<unsigned int>{ 9,10 },
                     "restaurant") {}


void Restaurant::declencher_effet(unsigned int possesseur, int bonus) const{
    Partie * partie = Partie::get_instance();
    Joueur* joueur_possesseur = partie->get_tab_joueurs()[possesseur];
    cout << "Activation de l'effet du Restaurant du joueur " << joueur_possesseur->get_nom() << endl;
    //Trouver un joueur qui a cette carte
    if(partie->get_joueur_actuel() != possesseur){
        if(partie->transfert_argent(possesseur, partie->get_joueur_actuel(), 2+bonus)){
            return;
        }
    }
    /*cout << "Activation de l'effet du restaurant" << endl;
    Partie * partie = Partie::get_instance();
    Joueur* joueur_actuel = partie->get_tab_joueurs().at(possesseur);
    //Trouver un joueur qui a cette carte
    for (unsigned int i = 0; i < partie->get_tab_joueurs().size(); i++){
        if (partie->get_tab_joueurs().at(i)->possede_batiment("Restaurant") && i!=possesseur){
            if(partie->transfert_argent(possesseur, i, 2)){
                return;
            }
        }
    }*/
}
