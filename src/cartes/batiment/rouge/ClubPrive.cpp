#include "ClubPrive.h"
#include "Partie.h"

ClubPrive::ClubPrive() :
            Batiment("ClubPrive",
                     4 ,
                     "Recevez toutes les pieces du joueur qui a lance les des si celui-ci possede au moins trois monuments construits.",
                     "../../assets/batiments/Rouge/Club-prive.jpg",
                     Rouge ,
                     list<unsigned int>{12,13,14},
                     "restaurant"){};

void ClubPrive::declencher_effet(unsigned int possesseur, int bonus) const{
    cout << "Activation de l'effet du club prive" << endl;
    Partie * partie = Partie::get_instance();
    Joueur* joueur_actuel = partie->get_tab_joueurs().at(possesseur);
    //Trouver un joueur qui a cette carte
    if(joueur_actuel->get_monument_jouables().size()>=3){
        for (unsigned int i = 0; i < partie->get_tab_joueurs().size(); i++){
            if (partie->get_tab_joueurs().at(i)->possede_batiment("ClubPrive") && i!=possesseur){
                if(partie->transfert_argent(possesseur, i, joueur_actuel->get_argent())){
                    return;
                }
            }
        }
    }
}