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
    cout << "Activation de l'effet du Sushi Bar" << endl;
    Partie * partie = Partie::get_instance();
    Joueur* joueur_actuel = partie->get_tab_joueurs().at(possesseur);
    //Trouver un joueur qui a cette carte
    for (unsigned int i = 0; i < partie->get_tab_joueurs().size(); i++){
        if (partie->get_tab_joueurs().at(i)->possede_batiment("SushiBar") && partie->get_tab_joueurs().at(i)->possede_monument("Port") && i!=possesseur){
            if(partie->transfert_argent(possesseur, i, 3)){
                return;
            }
        }
    }
}