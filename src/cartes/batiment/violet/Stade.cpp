#include "Stade.h"

Stade::Stade() :
Batiment("Stade",
         6,
         "Recevez 2 pieces de la part de chaque autre joueur",
         "../../../assets/batiments/Violet/Stade.jpg",
         Violet,
         list<unsigned int>{6},
         "special") {
    ///Constructeur de Stade
}

void Stade::declencher_effet(unsigned int possesseur) const{
    /// Effet de la classe Stade
    std::cout << "Activation de l'effet du stade." << std::endl;
    /*Joueur* j_actuel = tab_joueurs[joueur_actuel];
    // Pour chaque joueur de la partie
    for (auto joueur : tab_joueurs){
        // Si le joueur est different du joueur actuel
        if (joueur != j_actuel){
            // On verifie qu'il a l'argent necessaire
            if (joueur->get_argent() >= 2) {
                // Transaction
                joueur->set_argent(joueur->get_argent() - 2);
                j_actuel->set_argent(j_actuel->get_argent() + 2);
                cout << joueur->get_nom() << " a donne 2 a " << j_actuel->get_nom() << endl;
            }
            else{
                cout << joueur->get_nom() << " n'a pas assez d'argent." << endl;
            }
        }
    }
    cout << j_actuel->get_nom() << "possede maintenant " << j_actuel->get_argent() << " credits." <<endl;
     */
}
