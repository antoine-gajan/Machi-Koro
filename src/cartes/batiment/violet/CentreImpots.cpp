#include "CentreImpots.h"


CentreImpots::CentreImpots():
        Batiment("CentreImpots",
                 4,
                 "Recevez la moitie (arrondie a l'inferieur) des pieces de chaque joueur qui en possede 10 ou plus.",
                 "../../../assets/batiments/Violet/Centre-des-impots.jpg",
                 Violet,
                 list<unsigned int>{8,9},
                 "special") {
    ///Constructeur du Centre des Impots
}



void CentreImpots::declencher_effet(unsigned int possesseur, int bonus) const{
    /// Effet du Centre des Impots
    std::cout << "Activation de l'effet du centre des impots." << std::endl;
    const vector<Joueur*>& tab_joueurs = Partie::get_instance().get_tab_joueurs();
    Joueur *j_actuel = tab_joueurs[possesseur];
    // Parcours du tableau de joueurs
    for (int i = 0; i < tab_joueurs.size(); i++){
        if (j_actuel != tab_joueurs[i] && tab_joueurs[i]->get_argent() >= 10){
            // A FAIRE
        }
    }

}



