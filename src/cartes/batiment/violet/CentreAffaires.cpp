#include "CentreAffaires.h"
#include "Partie.h"
#include "Joueur.h"

CentreAffaires::CentreAffaires():
    Batiment("CentreAffaires",
             8,
             "Vous pouvez echanger avec le joueur de votre choix un etablissement qui n'est pas de type special",
             "../../../assets/batiments/Violet/Centre-d-'affaires.jpg",
             Violet,
             list<unsigned int>{6},
             "special") {
    ///Constructeur de Centre d'Affaires
}



void CentreAffaires::declencher_effet(unsigned int possesseur, int bonus) const{
    /// Effet du Centre d'affaires
    std::cout << "Activation de l'effet du centre d'affaires." << std::endl;
    const vector<Joueur*>& tab_joueurs = Partie::get_instance()->get_tab_joueurs();
    Joueur* j_actuel = tab_joueurs[possesseur];

    // Choix du joueur
    unsigned int num_joueur;
    // Affichage des joueurs
    cout << "Liste des joueurs : " << endl;
    for (int i = 0; i < tab_joueurs.size(); i++) {
        cout << i << ". " << tab_joueurs[i]->get_nom() << endl;
    }

    // Demande du nombre et validite de la saisie
    cout << "Entrez le numero associe au joueur qui va vous donner 5 pieces : ";
    cin >> num_joueur;
    while (num_joueur < 0 || num_joueur >= tab_joueurs.size() || num_joueur == possesseur) {
        while (num_joueur < 0 || num_joueur >= tab_joueurs.size() || num_joueur == possesseur) {
            cout << "Erreur dans la saisie. Veuillez saisir un nombre valide : ";
            cin >> num_joueur;
        }
        Joueur* joueur_echange = tab_joueurs[num_joueur];
        cout << "Vous allez procede a un echange avec " << joueur_echange->get_nom() << endl;

        // Liste des batiments du joueur actuel et de l'autre joueur
        unsigned int bat_don;
        auto liste_batiments_echange = joueur_echange->get_liste_bat_non_special();
        auto liste_batiments_joueur = j_actuel->get_liste_bat_non_special();

        // Demande du batiment a echanger
        cout << "Les batiments que vous pouvez donner : " << endl;
        unsigned int i = 0;
        for (auto bat : liste_batiments_joueur){
            cout << i << ". " << bat.first->get_nom() << endl;
            i++;
        }

        // Demande du batiment a donner et validite de la saisie
        cout << "Entrez le numero du batiment que vous voulez donnez : ";
        cin >> bat_don;
        while (bat_don < 0 || bat_don >= liste_batiments_joueur.size()) {
            cout << "Erreur dans la saisie. Veuillez saisir un nombre valide : ";
            cin >> bat_don;
        }
        // On trouve a partir du numero le batiment associe
        pair<Batiment *, unsigned int> batiment_a_donner;
        i = 0;
        for (auto bat : liste_batiments_joueur){
            if (i == bat_don) batiment_a_donner = bat;
            i++;
        }
        // Affichage du recapitulatif
        cout << "Vous allez donner a " << joueur_echange->get_nom() << " le batiment " << batiment_a_donner.first->get_nom();
        // Demande du batiment a recevoir en echange
        unsigned int bat_recu;
        cout << "Les batiments que vous pouvez donner : " << endl;
        i = 0;
        for (auto bat : liste_batiments_joueur){
            cout << i << ". " << bat.first->get_nom() << endl;
            i++;
        }
        // Demande du batiment a recevoir en echange et validite de la saisie
        cout << "Entrez le numero du batiment que vous voulez donnez : ";
        cin >> bat_recu;
        while (bat_recu < 0 || bat_recu >= liste_batiments_echange.size()) {
            cout << "Erreur dans la saisie. Veuillez saisir un nombre valide : ";
            cin >> bat_recu;
        }
        // On trouve a partir du numero le batiment associe
        pair<Batiment *, unsigned int> batiment_a_recevoir;
        i = 0;
        for (auto bat : liste_batiments_joueur){
            if (i == bat_recu) batiment_a_recevoir = bat;
            i++;
        }
        // Affichage du recapitulatif
        cout << "Vous allez recevoir de " << joueur_echange->get_nom() << " le batiment " << batiment_a_recevoir.first->get_nom();

        // Echange des batiments
        // Gestion du batiment 2 dans l'echange
        joueur_echange->retirer_batiment(batiment_a_recevoir.first);
        j_actuel->ajouter_batiment(batiment_a_recevoir.first);
        // Gestion du batiment 1 dans l'echange
        j_actuel->retirer_batiment(batiment_a_donner.first);
        joueur_echange->ajouter_batiment(batiment_a_donner.first);
        }
    }



