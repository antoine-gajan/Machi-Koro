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
    //Trouver un joueur qui a cette carte
    if(partie->get_joueur_actuel() != possesseur){
        if (partie->get_tab_joueurs()[possesseur]->possede_batiment("Port")){
            cout << "Activation de l'effet du Sushi bar du joueur \"" << joueur_possesseur->get_nom()<<"\"" << endl;
            partie->transfert_argent(possesseur, partie->get_joueur_actuel(), 3 + bonus) ;
        }
    }
    else{
        throw gameException("On ne peut pas se donner d'argent a soi meme");
    }
}