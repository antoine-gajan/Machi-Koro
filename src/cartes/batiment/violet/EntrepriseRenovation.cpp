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
    const vector<Joueur *> &tab_joueurs = Partie::get_instance()->get_tab_joueurs();
    Joueur *j_actuel = tab_joueurs[possesseur];
    cout << "Activation de l'effet de l'entreprise de rénovation du joueur \"" << j_actuel->get_nom()<<"\"" << endl;

    // Liste des batiments du joueur actuel et de l'autre joueur
    unsigned int bat_choisi;
    auto liste_batiments_joueur = j_actuel->get_liste_bat_non_special();

    // Demande du batiment a echanger
    cout << "Les batiments que vous pouvez donner : " << endl;
    unsigned int i = 0;
    for (auto bat: liste_batiments_joueur) {
        cout << i << ". " << bat.first->get_nom() << endl;
        i++;
    }
    // Demande du batiment a donner et validite de la saisie
    if (!j_actuel->get_est_ia()) {
        cout << "Entrez le numero du batiment que vous voulez donnez : ";
        cin >> bat_choisi;
        while (bat_choisi < 0 || bat_choisi >= liste_batiments_joueur.size()) {
            cout << "Erreur dans la saisie. Veuillez saisir un nombre valide : ";
            cin >> bat_choisi;
        }
    }
    else {
        bat_choisi = rand() % liste_batiments_joueur.size();
    }
    // On trouve a partir du numero le batiment associe
    pair<Batiment *, unsigned int> batiment;
    i = 0;
    for (auto bat: liste_batiments_joueur) {
        if (i == bat_choisi) batiment = bat;
        i++;
    }
    // Affichage du recapitulatif
    cout << "Vous voulez fermer toutes les " << batiment.first->get_nom()<<endl;

    int nb_fermes = 0;
    // Fermeture des batiments correspondants
    for (auto joueur : tab_joueurs){
        for (auto& couleur : joueur->get_liste_batiment()) {
            for (auto bat: couleur.second) {
                if (bat.first->get_nom() == batiment.first->get_nom()) {
                    for (int nb = 0; nb < bat.second; nb++) {
                        // Fermeture des batiments
                        joueur->fermer_batiment(bat.first);
                        nb_fermes++;
                    }
                }
            }
        }
    }
    cout << nb_fermes << "batiments " << batiment.first->get_nom() << " ont été fermés" << endl;
    cout << j_actuel->get_nom() << " va recevoir " << nb_fermes << "pièces" << endl;
    j_actuel->set_argent(j_actuel->get_argent() + nb_fermes);
    cout << j_actuel->get_nom() << "possède maintenant " << j_actuel->get_argent() << " pièces" <<endl;
}
