#include "EntrepriseRenovation.h"
#include "Joueur.h"
#include "Partie.h"

EntrepriseRenovation::EntrepriseRenovation() :
        Batiment("EntrepriseRenovation",
                 1,
                 "Choississez un de vos établissements qui ne soit pas de type spécial. Tous les établissements identiques de tous les joueurs sont fermés. Puis recevez une pièce de la banque pour chaque établissement fermé.",
                 "../../../assets/batiments/Violet/Entreprise-de-renovation.jpg",
                 Violet,
                 list<unsigned int>{10},
                 "special") {
    ///Constructeur de EntrepriseRenovation
}

void EntrepriseRenovation::declencher_effet(unsigned int possesseur, int bonus) const{
    /// Effet de la classe Entreprise de Renovation
    Partie* instance = Partie::get_instance();
    const vector<Joueur *> &tab_joueurs = instance->get_tab_joueurs();
    Joueur *j_actuel = tab_joueurs[possesseur];
    cout << "Activation de l'effet de l'entreprise de rénovation du joueur \"" << j_actuel->get_nom()<<"\"" << endl;

    // Selection du batiment du joueur
    Batiment *batiment;
    batiment = j_actuel->selectionner_batiment();
    while (batiment->get_couleur() == Violet) {
        cout << "Vous ne pouvez pas selectionner un batiment violet !" << endl;
        batiment = j_actuel->selectionner_batiment();
    }

    int nb_fermes = 0;
    // Fermeture des batiments correspondants
    for (auto joueur : tab_joueurs){
        for (auto& couleur : joueur->get_liste_batiment()) {
            for (auto bat: couleur.second) {
                if (bat.first->get_nom() == batiment->get_nom()) {
                    for (int nb = 0; nb < bat.second; nb++) {
                        // Fermeture des batiments
                        joueur->fermer_batiment(batiment);
                        nb_fermes++;
                    }
                }
            }
        }
    }
    cout << nb_fermes << "batiments " << batiment->get_nom() << " ont été fermés" << endl;
    cout << j_actuel->get_nom() << " va recevoir " << nb_fermes << "pièces" << endl;
    j_actuel->set_argent(j_actuel->get_argent() + nb_fermes);
    cout << j_actuel->get_nom() << "possède maintenant " << j_actuel->get_argent() << " pièces" <<endl;
}
