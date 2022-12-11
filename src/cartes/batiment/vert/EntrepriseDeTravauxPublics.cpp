#include "EntrepriseDeTravauxPublics.h"
#include "Partie.h"

EntrepriseDeTravauxPublics::EntrepriseDeTravauxPublics()
        : Batiment("EntrepriseDeTravauxPublics",
                   2,
                   "Vous devez retourner une de vos cartes monuments sur sa face en travaux. Ce faisant, vous recevez 8 pieces de la banque.",
                   "../../../assets/batiments/Vert/Entreprise-de-travaux-publics.jpg",
                   Vert,
                   {4},
                   "entreprise") {}

void EntrepriseDeTravauxPublics::declencher_effet(unsigned int possesseur, int bonus) const {
    cout << "Activation de l'effet de la carte Entreprise de travaux publics" << endl;

    /// Effet de l'EntrepriseDeTravauxPublics

    /// DESACTIVATION DU MONUMENT

    unsigned int j_act_index =  Partie::get_instance()->get_joueur_actuel();
    Joueur* j_actuel = Partie::get_instance()->get_tab_joueurs()[j_act_index];

    // On demande a l'utilisateur de selectionner un de ses monuments
    Monument* monument = j_actuel->selectionner_monument();

    // On recupere la liste des monuments actifs du joueur
    vector<Monument*> monuments_jouables = j_actuel->get_monument_jouables();

    // On verifie que le monument est jouable
    while (find(monuments_jouables.begin(), monuments_jouables.end(), monument) == monuments_jouables.end()){
        cout << "Vous ne pouvez pas retourner un monument qui n'est pas actif." << endl;
        monument = j_actuel->selectionner_monument();
    }

    // On desactive le monument
    j_actuel->desactiver_monument(monument);

    /// TRANSACTION AVEC LA BANQUE
    // On donne 8 pieces au joueur actuel
    j_actuel->set_argent(j_actuel->get_argent() + 8 + bonus);


}