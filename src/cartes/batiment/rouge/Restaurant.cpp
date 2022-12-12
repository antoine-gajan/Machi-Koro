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
    cout << "Activation de l'effet du restaurant" << endl;
    Partie * partie = Partie::get_instance();
    Joueur* joueur_actuel = partie->get_tab_joueurs().at(possesseur);
    //Trouver un joueur qui a cette carte
    for (unsigned int i = 0; i < partie->get_tab_joueurs().size(); i++){
        if (partie->get_tab_joueurs().at(i)->possede_batiment("Restaurant")){
            //si il y en a un enlever 1 piece au joueur actuel et ajouter 1 piece au joueur qui en a une
            joueur_actuel->set_argent(joueur_actuel->get_argent() - 2);
            partie->get_tab_joueurs().at(i)->set_argent(partie->get_tab_joueurs().at(i)->get_argent() + 2);
            break;
        }
    }
}
