#include "ChaineTelevision.h"
#include <algorithm>

using namespace std;

ChaineTelevision::ChaineTelevision(cosnt string& path_image):
    Batiment("Chaine de télévision",
             7,
             "Recevez 5 pièces du joueur de votre choix",
             path_image,
             Violet,
             list<unsigned int>{6},
             "spécial") {
    ///Constructeur de Chaine de Television
}

void ChaineTelevision::declencher_effet(vector<Joueur *>& tab_joueurs, unsigned int joueur_actuel) {
    /// Effet de ChaineTelevision
    Joueur* j_actuel = tab_joueurs[joueur_actuel];
    unsigned int num_joueur;
    // Affichage des joueurs
    cout << "Liste des joueurs : " << endl;
    for (int i = 0; i < tab_joueurs.size(); i++) {
        cout << i << ". " << tab_joueurs[i]->get_nom() << endl;
    }
    // Demande du nombre et validité de la saisie
    cout << "Entrez le numéro associé au joueur qui va vous donner 5 pièces : ";
    cin >> num_joueur;
    while (num_joueur < 0 || num_joueur >= tab_joueurs.size() || num_joueur == joueur_actuel) {
        cout << "Erreur dans la saisie. Veuillez saisir un nombre valide : ";
        cin >> num_joueur;
    }
    // On regarde si le joueur a l'argent nécessaire
    if (j_actuel->get_argent() >= 2){
        // Transaction
        tab_joueurs[num_joueur]->set_argent(tab_joueurs[num_joueur]->get_argent() - 2);
        cout << tab_joueurs[num_joueur]->get_nom() << " a donné 2 à " << j_actuel->get_nom() << endl;
        j_actuel->set_argent(j_actuel->get_argent() + 2);
        cout << j_actuel->get_nom() << "possède maintenant " << j_actuel->get_argent() << " crédits." <<endl;
    }
    else{
        cout << tab_joueurs[num_joueur]->get_nom() << " n'a pas assez d'argent." << endl;
    }
}

