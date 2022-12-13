#include "ChaineTelevision.h"
#include <algorithm>
#include "Partie.h"
#include "Joueur.h"

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
    // Variables utiles
    const vector<Joueur*> tab_joueurs = Partie::get_instance()->get_tab_joueurs();
    Joueur* j_actuel = tab_joueurs[possesseur];
    cout << "Activation de l'effet de la Chaine de Television du joueur \"" << j_actuel->get_nom()<<"\"" << endl;

    // Choix de joueur
    int j_echange = Partie::selectionner_joueur(tab_joueurs, possesseur);
    Joueur* joueur_echange = tab_joueurs[j_echange];

    unsigned int num_joueur;
    // Affichage des joueurs
    cout << "Liste des joueurs : " << endl;
    for (int i = 0; i < tab_joueurs.size(); i++) {
        cout << i << ". " << tab_joueurs[i]->get_nom() << endl;
    }
    if (!j_actuel->get_est_ia()){
        // Demande du nombre et validite de la saisie
        cout << "Entrez le numero associe au joueur qui va vous donner 5 pieces : ";
        cin >> num_joueur;
        while (num_joueur < 0 || num_joueur >= tab_joueurs.size() || num_joueur == possesseur) {
            cout << "Erreur dans la saisie. Veuillez saisir un nombre valide : ";
            cin >> num_joueur;
        }
    }
    else{
        num_joueur = rand() % tab_joueurs.size();
    }

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

