#include "EntrepriseDeTravauxPublics.h"


EntrepriseDeTravauxPublics::EntrepriseDeTravauxPublics(const string& path_image)
        : Batiment("Entreprise de travaux publics",
                   2,
                   "Vous devez retourner une de vos cartes monuments sur sa face en travaux. Ce faisant, vous recevez 8 pièces de la banque.",
                   path_image,
                   Vert,
                   {4},
                   "entreprise") {}

void EntrepriseDeTravauxPublics::declencher_effet(vector<Joueur *> &tab_joueurs, unsigned int joueur_actuel) {
    /// Effet de l'EntrepriseDeTravauxPublics

    /// DESACTIVATION DU MONUMENT
    Joueur* j_actuel = tab_joueurs[joueur_actuel];

    // On demande à l'utilisateur de selectionner un de ses monuments
    Monument* monument = selectionner_monument(j_actuel);

    // On recupere la liste des monuments actifs du joueur
    vector<Monument*> monuments_jouables = j_actuel->get_monument_jouables();

    // On vérifie que le monument est jouable
    while (find(monuments_jouables.begin(), monuments_jouables.end(), monument) == monuments_jouables.end()){
        cout << "Vous ne pouvez pas retourner un monument qui n'est pas actif." << endl;
        monument = selectionner_monument(j_actuel);
    }

    // On desactive le monument
    j_actuel->desactiver_monument(monument);

    /// TRANSACTION AVEC LA BANQUE
    // On donne 8 pièces au joueur actuel
    j_actuel->set_argent(j_actuel->get_argent() + 8);


}