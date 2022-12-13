#include "ClubPrive.h"
#include "Partie.h"

ClubPrive::ClubPrive() :
            Batiment("ClubPrive",
                     4 ,
                     "Recevez toutes les pieces du joueur qui a lance les des si celui-ci possede au moins trois monuments construits.",
                     "../../assets/batiments/Rouge/Club-prive.jpg",
                     Rouge ,
                     list<unsigned int>{12,13,14},
                     "restaurant"){}

void ClubPrive::declencher_effet(unsigned int possesseur, int bonus) const{
    Partie * partie = Partie::get_instance();
    Joueur* joueur_possesseur = partie->get_tab_joueurs()[possesseur];
    Joueur* joueur_actuel = partie->get_tab_joueurs()[partie->get_joueur_actuel()];

    if (partie->get_joueur_actuel() != possesseur){
        if(joueur_actuel->get_monument_jouables().size()>=3){
            cout << "Activation de l'effet du Club Prive du joueur \"" << joueur_possesseur->get_nom()<< "\"" << endl;
            partie->transfert_argent(possesseur, partie->get_joueur_actuel(), joueur_actuel->get_argent());
        }
    }
    else{
        throw gameException("On ne peut pas se donner d'argent a soi meme");
    }
}