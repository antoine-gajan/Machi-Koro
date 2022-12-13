#include "StandDeHamburger.h"
#include "Partie.h"

StandDeHamburger::StandDeHamburger() :
            Batiment("StandDeHamburger",
                     1 ,
                     "Recevez 1 piece du joueur qui a lance les des.",
                     "../../assets/batiments/Rouge/Monster-burger.jpg",
                     Rouge,
                     list<unsigned int>{8},
                     "restaurant"){}

void StandDeHamburger::declencher_effet(unsigned int possesseur, int bonus) const{
    Partie * partie = Partie::get_instance();
    Joueur* joueur_possesseur = partie->get_tab_joueurs()[possesseur];
    cout << "Activation de l'effet du cafe du Moonster burger de \"" << joueur_possesseur->get_nom()<<"\"" << endl;
    //Trouver un joueur qui a cette carte
    if(partie->get_joueur_actuel() != possesseur){
        if(partie->transfert_argent(possesseur, partie->get_joueur_actuel(), 1+bonus)){
            return;
        }
    }

    /*//j'ai deliberement retire le parametre joueur actuel de declencher effet pour respecter la methode virtuelle declaree dans Batiment.h
    cout << "Activation de l'effet du stand de hamburger" << endl;
    Partie * partie = Partie::get_instance();
    Joueur* joueur_actuel = partie->get_tab_joueurs().at(possesseur);
    //Trouver un joueur qui a cette carte
    for (unsigned int i = 0; i < partie->get_tab_joueurs().size(); i++){
        if (partie->get_tab_joueurs().at(i)->possede_batiment("StandDeHamburger") && i!=possesseur){
            if(partie->transfert_argent(possesseur, i, 1)){
                return;
            }
        }
    }*/
}