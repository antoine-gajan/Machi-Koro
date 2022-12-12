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
    //j'ai deliberement retire le parametre joueur actuel de declencher effet pour respecter la methode virtuelle declaree dans Batiment.h
    cout << "Activation de l'effet du restaurant 5 etoiles" << endl;
    Partie * partie = Partie::get_instance();
    Joueur* joueur_actuel = partie->get_tab_joueurs().at(possesseur);
    //Trouver un joueur qui a cette carte
    if(joueur_actuel->get_monument_jouables().size()>=2){
        for (unsigned int i = 0; i < partie->get_tab_joueurs().size(); i++){
            if (partie->get_tab_joueurs().at(i)->possede_batiment("Restaurant5Etoiles")) {
                //si il y en a un enlever 1 piece au joueur actuel et ajouter toutes les pieces au joueur qui en a une
                joueur_actuel->set_argent(joueur_actuel->get_argent() - 5);
                partie->get_tab_joueurs().at(i)->set_argent(
                        partie->get_tab_joueurs().at(i)->get_argent() + 5);
                break;
            }
        }
    }
}