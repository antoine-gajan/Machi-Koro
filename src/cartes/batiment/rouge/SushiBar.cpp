#include "SushiBar.h"
#include "Partie.h"

SushiBar::SushiBar() :
            Batiment("SushiBar",
                     4 ,
                     "Si vous avez le port, recevez 3 pieces du joueur qui a lance les des.",
                     "../../assets/batiments/Rouge/Sushi-bar.jpg",
                     Rouge ,
                     list<unsigned int>{1},
                     "restaurant"){}

void SushiBar::declencher_effet(unsigned int possesseur, int bonus) const{
    Partie * partie = Partie::get_instance();
    Joueur* joueur_possesseur = partie->get_tab_joueurs()[possesseur];
    cout << "Activation de l'effet du Sushi bar du joueur " << joueur_possesseur->get_nom() << endl;
    //Trouver un joueur qui a cette carte
    if(partie->get_joueur_actuel() != possesseur && partie->get_tab_joueurs()[possesseur]->possede_batiment("Port")){
        if(partie->transfert_argent(possesseur, partie->get_joueur_actuel(), 3+bonus)){
            return;
        }
    }
    /*cout << "Activation de l'effet du Sushi Bar" << endl;
    Partie * partie = Partie::get_instance();
    Joueur* joueur_actuel = partie->get_tab_joueurs().at(possesseur);
    //Trouver un joueur qui a cette carte
    for (unsigned int i = 0; i < partie->get_tab_joueurs().size(); i++){
        if (partie->get_tab_joueurs().at(i)->possede_batiment("SushiBar") && partie->get_tab_joueurs().at(i)->possede_monument("Port") && i!=possesseur){
            if(partie->transfert_argent(possesseur, i, 3)){
                return;
            }
        }
    }*/
}