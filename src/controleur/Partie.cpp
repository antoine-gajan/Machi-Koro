#include "Partie.h"

Partie::Partie(vector<Joueur*> liste_joueurs, vector<EditionDeJeu *> editions) : tab_joueurs(liste_joueurs), nb_monuments_win(0), joueur_actuel(0){
    ///Constructeur de Partie

    // On détermine le nombre de monuments pour gagner
    for (auto& edition : editions){
        if (edition->get_nb_monuments_win() > nb_monuments_win){
            nb_monuments_win = edition->get_nb_monuments_win();
        }
    }
}

void Partie::jouer_partie() {
    ///Fonction principale pour jouer une partie

}
