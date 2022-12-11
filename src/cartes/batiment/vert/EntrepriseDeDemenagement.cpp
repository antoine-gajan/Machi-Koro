#include "EntrepriseDeDemenagement.h"
#include "Partie.h"

EntrepriseDeDemenagement::EntrepriseDeDemenagement()
        : Batiment("EntrepriseDeDemenagement",
                   2,
                   "Donnez a un autre joueur un de vos etablissements qui ne soit pas de type special. Puis recevez 4 pieces de la banque.",
                   "../../../assets/batiments/Vert/Entreprise-de-demenagement.jpg",
                   Vert,
                   {9, 10},
                   "entreprise") {}

void EntrepriseDeDemenagement::declencher_effet(unsigned int possesseur, int bonus) const {
    cout << "Declenchement de l'effet de la carte Entreprise de demenagement" << endl;

    /// Effet de l'EntrepriseDeDemenagement

    /// DON DE L'ETABLISSEMENT
    unsigned int j_act_index = Partie::get_instance()->get_joueur_actuel();
    Joueur* j_actuel = Partie::get_instance()->get_tab_joueurs()[j_act_index];

    vector<Joueur*> tab_joueurs = Partie::get_instance()->get_tab_joueurs();

    // On demande a l'utilisateur de selectionner un joueur
    unsigned int joueur_selectionne = Partie::selectionner_joueur(tab_joueurs, j_act_index);

    // On demande a l'utilisateur de selectionner un de ses batiments
    Batiment* batiment = j_actuel->selectionner_batiment();

    // On verifie que le batiment n'est pas de type special
    while (batiment->get_type() == "special"){
        cout << "Vous ne pouvez pas donner un etablissement de type special." << endl;
        batiment = j_actuel->selectionner_batiment();
    }

    // On retire le batiment du joueur actuel
    j_actuel->retirer_batiment(batiment);

    // On ajoute le batiment au joueur selectionne
    tab_joueurs[joueur_selectionne]->ajouter_batiment(batiment);


    /// TRANSACTION AVEC LA BANQUE
    // On donne 4 pieces au joueur actuel
    j_actuel->set_argent(j_actuel->get_argent() + 4 + bonus);

}