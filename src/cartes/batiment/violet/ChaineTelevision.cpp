#include "ChaineTelevision.h"
#include <algorithm>

using namespace std;

ChaineTelevision::ChaineTelevision():
    Batiment("ChaineTelevision",
             7,
             "Recevez 5 pieces du joueur de votre choix",
             "../../../assets/batiments/Violet/Chaine-de-television.jpg",
             Violet,
             list<unsigned int>{6},
             "special") {
    ///Constructeur de Chaine de Television
}

void ChaineTelevision::declencher_effet(unsigned int possesseur, int bonus = 0) const{
    /// Effet de ChaineTelevision
    std::cout << "Activation de l'effet de la chaine de television." << std::endl;

    /*
    Joueur* j_actuel = tab_joueurs[joueur_actuel];
    unsigned int num_joueur;
    // Affichage des joueurs
    cout << "Liste des joueurs : " << endl;
    for (int i = 0; i < tab_joueurs.size(); i++) {
        cout << i << ". " << tab_joueurs[i]->get_nom() << endl;
    }
    // Demande du nombre et validite de la saisie
    cout << "Entrez le numero associe au joueur qui va vous donner 5 pieces : ";
    cin >> num_joueur;
    while (num_joueur < 0 || num_joueur >= tab_joueurs.size() || num_joueur == joueur_actuel) {
        cout << "Erreur dans la saisie. Veuillez saisir un nombre valide : ";
        cin >> num_joueur;
    }
    // On regarde si le joueur a l'argent necessaire
    if (j_actuel->get_argent() >= 2){
        // Transaction
        tab_joueurs[num_joueur]->set_argent(tab_joueurs[num_joueur]->get_argent() - 2);
        cout << tab_joueurs[num_joueur]->get_nom() << " a donne 2 a " << j_actuel->get_nom() << endl;
        j_actuel->set_argent(j_actuel->get_argent() + 2);
        cout << j_actuel->get_nom() << "possede maintenant " << j_actuel->get_argent() << " credits." <<endl;
    }
    else{
        cout << tab_joueurs[num_joueur]->get_nom() << " n'a pas assez d'argent." << endl;
    }
     */
}

