#include "Stade.h"
#include "Partie.h"
#include "Joueur.h"

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

void Stade::declencher_effet(unsigned int possesseur, int bonus) const{
    /// Effet de la classe Stade
    cout << "Activation de l'effet du stade." << endl;

    // Variables utiles
    const vector<Joueur*> tab_joueurs = Partie::get_instance()->get_tab_joueurs();
    Joueur* j_actuel = tab_joueurs[possesseur];
    unsigned int argent_joueur;

    // Pour chaque joueur de la partie
    for (auto joueur : tab_joueurs) {
        // Si le joueur est different du joueur actuel
        if (joueur != j_actuel) {
            argent_joueur = joueur->get_argent();
            // On verifie qu'il a l'argent necessaire
            if (argent_joueur >= 2) {
                // Transaction
                joueur->set_argent(joueur->get_argent() - 2);
                j_actuel->set_argent(j_actuel->get_argent() + 2);
                cout << joueur->get_nom() << " a donne 2 a " << j_actuel->get_nom() << endl;
            } else if (argent_joueur > 0) {
                // On vide le compte de l'autre joueur
                // Transaction
                joueur->set_argent(joueur->get_argent() - argent_joueur);
                j_actuel->set_argent(j_actuel->get_argent() + argent_joueur);
                cout << joueur->get_nom() << " a donne" << argent_joueur << " a " << j_actuel->get_nom() << endl;
            } else {
                // S'il n'a pas d'argent
                cout << joueur->get_nom() << "n'a pas d'argent." << endl;
            }
        }
    }
    cout << j_actuel->get_nom() << "possede maintenant " << j_actuel->get_argent() << " credits." <<endl;
}