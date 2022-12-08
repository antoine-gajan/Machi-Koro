#include "Partie.h"

Partie::Partie(vector<EditionDeJeu *> editions) {
    ///Constructeur de Partie

    //Initialisation des attributs


}

void Partie::jouer_partie() {
    ///Fonction principale pour jouer une partie

}


void Partie::jouer_tour() {
    ///Fonction pour jouer un tour
    Joueur *j_actuel = tab_joueurs[joueur_actuel];
    if (est_gagnant(j_actuel)) {
        cout << "Le joueur " << j_actuel->get_nom() << " a gagné la partie !" << endl;
        return;
    }

    /// Jet de dé pour le joueur
    vector<Monument*> monuments_jouables = j_actuel->get_monument_jouables();


    unsigned int res_de1 = rand() % 6 + 1;
    unsigned int res_de2 = 0;
    unsigned int res_tot = res_de1;

    cout << "Le joueur " << j_actuel->get_nom() << " a fait " << res_de1 << endl;



    /// Activation des bâtiments


    /// Phase d'achat
}

bool Partie::est_gagnant(Joueur *joueur) {
    ///Fonction pour vérifier si un joueur a gagné
    return joueur->get_monument_jouables().size() >= nb_monuments_win;
}