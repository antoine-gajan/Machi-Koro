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

void ChaineTelevision::declencher_effet(unsigned int possesseur, int bonus) const{
    /// Effet de ChaineTelevision
    std::cout << "Activation de l'effet de la chaine de television." << std::endl;
    // Choix de joueur
    int j_echange = Partie::selectionner_joueur();

    // Variables utiles
    const vector<Joueur*> tab_joueurs = Partie::get_instance().get_tab_joueurs();
    Joueur* joueur_echange = tab_joueurs[j_echange];
    Joueur* j_actuel = tab_joueurs[possesseur];

    // On regarde si le joueur a l'argent necessaire
    if (j_actuel->get_argent() >= 5){
        // Transaction
        joueur_echange->set_argent(joueur_echange->get_argent() - 5);
        cout << joueur_echange->get_nom() << " a donne 2 a " << joueur_echange->get_nom() << endl;
        j_actuel->set_argent(j_actuel->get_argent() + 5);
        cout << j_actuel->get_nom() << "possede maintenant " << j_actuel->get_argent() << " credits." <<endl;
    }
    else{
        cout << joueur_echange->get_nom() << " n'a pas assez d'argent." << endl;
    }
}

