#include "CentreImpots.h"
#include "Partie.h"
#include "Joueur.h"

CentreImpots::CentreImpots():
        Batiment("CentreImpots",
                 4,
                 "Recevez la moitie (arrondie a l'inferieur) des pieces de chaque joueur qui en possede 10 ou plus.",
                 "../../../assets/batiments/Violet/Centre-des-impots.jpg",
                 Violet,
                 list<unsigned int>{8,9},
                 "special") {
    ///Constructeur du Centre des Impots
}



void CentreImpots::declencher_effet(unsigned int possesseur, int bonus) const {
    /// Effet du Centre des Impots
    cout << "Activation de l'effet du centre des impots." << endl;
    // Variables utiles pour la fonction
    const vector<Joueur *> &tab_joueurs = Partie::get_instance()->get_tab_joueurs();
    Joueur *j_actuel = tab_joueurs[possesseur];
    Joueur *j_echange;
    int argent_donne;
    // Parcours du tableau de joueurs
    for (int i = 0; i < tab_joueurs.size(); i++) {
        if (j_actuel != tab_joueurs[i] && tab_joueurs[i]->get_argent() >= 10) {
            // Si le joueur d'echange a suffisamment d'argent
            if (j_actuel != j_echange && j_echange->get_argent() >= 10) {
                argent_donne = j_echange->get_argent() % 2;
                // Transaction
                j_actuel->set_argent(j_actuel->get_argent() + argent_donne);
                j_echange->set_argent(j_echange->get_argent() - argent_donne);
                cout << "Le joueur " << j_echange->get_nom() << " donne " << argent_donne << " a "
                     << j_actuel->get_nom() << endl;
            }
        }
    }
}



