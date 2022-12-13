#include "Restaurant5Etoiles.h"
#include "Partie.h"

Restaurant5Etoiles::Restaurant5Etoiles() :
            Batiment("Restaurant5Etoiles",
                     3 ,
                     "Recevez 5 pieces du joueur qui a lance les des si celui-ci possede au moins deux monuments construits.",
                     "../../assets/batiments/Rouge/Restaurant-5-etoiles.jpg",
                     Rouge,
                     list<unsigned int>{5},
                     "restaurant"){}


void Restaurant5Etoiles::declencher_effet(unsigned int possesseur, int bonus) const{
    Partie * partie = Partie::get_instance();
    Joueur* joueur_possesseur = partie->get_tab_joueurs()[possesseur];
    cout << "Activation de l'effet du Restaurant 5 Etoiles du joueur \"" << joueur_possesseur->get_nom()<<"\"" << endl;
    Joueur* joueur_actuel = partie->get_tab_joueurs()[partie->get_joueur_actuel()];
    if(joueur_actuel->get_monument_jouables().size()>=2 && partie->get_joueur_actuel() != possesseur){
        partie->transfert_argent(possesseur, partie->get_joueur_actuel(), 5+bonus);
    }
    return;

    /*//j'ai deliberement retire le parametre joueur actuel de declencher effet pour respecter la methode virtuelle declaree dans Batiment.h
    cout << "Activation de l'effet du restaurant 5 etoiles" << endl;
    Partie * partie = Partie::get_instance();
    Joueur* joueur_actuel = partie->get_tab_joueurs().at(possesseur);
    //Trouver un joueur qui a cette carte
    if(joueur_actuel->get_monument_jouables().size()>=2){
        for (unsigned int i = 0; i < partie->get_tab_joueurs().size(); i++){
            if (partie->get_tab_joueurs().at(i)->possede_batiment("Restaurant5Etoiles") && i!=possesseur) {
                if(partie->transfert_argent(possesseur, i, 5)){
                    return;
                }
            }
        }
    }*/
}