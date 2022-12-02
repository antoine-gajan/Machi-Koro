#include "Partie.h"

Partie::Partie(vector<Joueur*> liste_joueurs, vector<EditionDeJeu *> editions) : nb_monuments_win(0), joueur_actuel(0){
    ///Constructeur de Partie

    // On détermine le nombre de monuments pour gagner
    for (auto& edition : editions){
        if (edition->get_nb_monuments_win() > nb_monuments_win){
            nb_monuments_win = edition->get_nb_monuments_win();
        }
    }

    for (auto& joueur : liste_joueurs){
        tab_joueurs.push_back(joueur);
    }

    joueur_actuel = 0;
}

void Partie::jouer_partie() {
    ///Fonction principale pour jouer une partie

}


void Partie::jouer_tour(Joueur *joueur_actuel) {
    ///Fonction pour jouer un tour
    if (est_gagnant(joueur_actuel)) {
        cout << "Le joueur " << joueur_actuel->get_nom() << " a gagné la partie !" << endl;
        return;
    }

    /// Jet de dé pour le joueur
    vector<Monument*> monuments_jouables = joueur_actuel->get_monument_jouables();


    unsigned int res_de1 = rand() % 6 + 1;
    unsigned int res_de2 = 0;
    unsigned int res_tot = res_de1;

    cout << "Le joueur " << joueur_actuel->get_nom() << " a fait " << res_de1 << endl;



    /// Activation des bâtiments


    /// Phase d'achat
}

bool Partie::est_gagnant(Joueur *joueur) {
    ///Fonction pour vérifier si un joueur a gagné
    return joueur->get_monument_jouables().size() >= nb_monuments_win;
}