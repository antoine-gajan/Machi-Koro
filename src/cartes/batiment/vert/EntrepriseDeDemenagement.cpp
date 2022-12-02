#include "EntrepriseDeDemenagement.h"

EntrepriseDeDemenagement::EntrepriseDeDemenagement()
        : Batiment("EntrepriseDeDemenagement",
                   2,
                   "Donnez a un autre joueur un de vos etablissements qui ne soit pas de type special. Puis recevez 4 pieces de la banque.",
                   "../../../assets/batiments/Vert/Entreprise-de-demenagement.jpeg",
                   Vert,
                   {9, 10},
                   "entreprise") {}

void EntrepriseDeDemenagement::declencher_effet() const {
    cout << "Declenchement de l'effet de la carte Entreprise de demenagement" << endl;
    /*
    /// Effet de l'EntrepriseDeDemenagement

    /// DON DE L'ETABLISSEMENT
    Joueur* j_actuel = tab_joueurs[joueur_actuel];

    // On demande a l'utilisateur de selectionner un joueur
    unsigned int joueur_selectionne = selectionner_joueur(tab_joueurs, joueur_actuel);

    // On demande a l'utilisateur de selectionner un de ses batiments
    Batiment* batiment = selectionner_batiment(j_actuel);

    // On verifie que le batiment n'est pas de type special
    while (batiment->get_type() == "special"){
        cout << "Vous ne pouvez pas donner un etablissement de type special." << endl;
        batiment = selectionner_batiment(j_actuel);
    }

    // On retire le batiment du joueur actuel
    j_actuel->retirer_batiment(batiment);

    // On ajoute le batiment au joueur selectionne
    tab_joueurs[joueur_selectionne]->ajouter_batiment(batiment);


    /// TRANSACTION AVEC LA BANQUE
    // On donne 4 pieces au joueur actuel
    j_actuel->set_argent(j_actuel->get_argent() + 4);
*/

}