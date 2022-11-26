#include "EntrepriseDeDemenagement.h"

EntrepriseDeDemenagement::EntrepriseDeDemenagement(string path_image)
        : Batiment("Entreprise de déménagement",
                   2,
                   "Donnez à un autre joueur un de vos établissements qui ne soit pas de type special. Puis recevez 4 pièces de la banque.",
                   path_image,
                   Vert,
                   {9, 10},
                   "entreprise") {}

void EntrepriseDeDemenagement::declencher_effet(vector<Joueur *> &tab_joueurs, unsigned int joueur_actuel) {
    /// Effet de l'EntrepriseDeDemenagement

    /// DON DE L'ETABLISSEMENT
    Joueur* j_actuel = tab_joueurs[joueur_actuel];

    // On demande à l'utilisateur de selectionner un joueur
    unsigned int joueur_selectionne = selectionner_joueur(tab_joueurs, joueur_actuel);

    // On demande à l'utilisateur de selectionner un de ses batiments
    pair<Batiment*, unsigned int>* batiment = selectionner_batiment(j_actuel);

    // On vérifie que le batiment n'est pas de type spécial
    while (batiment->first->get_type() == "special"){
        cout << "Vous ne pouvez pas donner un établissement de type spécial." << endl;
        batiment = selectionner_batiment(j_actuel);
    }

    // On retire le batiment du joueur actuel
    j_actuel->retirer_batiment(batiment->first);

    // On ajoute le batiment au joueur selectionné
    tab_joueurs[joueur_selectionne]->ajouter_batiment(batiment->first);


    /// TRANSACTION AVEC LA BANQUE
    // On donne 4 pièces au joueur actuel
    j_actuel->set_argent(j_actuel->get_argent() + 4);


}