#include "Stade.h"

Stade::Stade() :
Batiment("Stade",
         6,
         "Recevez 2 pièces de la part de chaque autre joueur",
         "../../../assets/batiments/Violet/Stade.jpg",
         Violet,
         list<unsigned int>{6},
         "spécial") {
    ///Constructeur de Stade
}

void Stade::declencher_effet() {
    /// Effet de la classe Stade
    std::cout << "Activation de l'effet du stade." << std::endl;

    /*
    Joueur* j_actuel = tab_joueurs[joueur_actuel];
    // Pour chaque joueur de la partie
    for (auto joueur : tab_joueurs){
        // Si le joueur est différent du joueur actuel
        if (joueur != j_actuel){
            // On vérifie qu'il a l'argent nécessaire
            if (joueur->get_argent() >= 2) {
                // Transaction
                joueur->set_argent(joueur->get_argent() - 2);
                j_actuel->set_argent(j_actuel->get_argent() + 2);
                cout << joueur->get_nom() << " a donné 2 à " << j_actuel->get_nom() << endl;
            }
            else{
                cout << joueur->get_nom() << " n'a pas assez d'argent." << endl;
            }
        }
    }
    cout << j_actuel->get_nom() << "possède maintenant " << j_actuel->get_argent() << " crédits." <<endl;
     */
}
