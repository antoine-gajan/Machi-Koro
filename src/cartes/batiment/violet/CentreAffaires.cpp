#include "CentreAffaires.h"

CentreAffaires::CentreAffaires(string& path_image):
    Batiment("Centre d'Affaires",
             8,
             "Vous pouvez échanger avec le joueur de votre choix un établissement qui n'est pas de type spécial",
             path_image,
             Violet,
             list<unsigned int>{6},
             "spécial") {
    ///Constructeur de Centre d'Affaires
}



map<Batiment*, unsigned int> get_liste_bat_non_special(Joueur* j){
    map<Batiment* ,unsigned int> liste;
    for (auto bat : j->get_liste_batiment()){
        if (bat.first->get_bat_type() != "spécial")
        {
            liste.insert(pair<Batiment*, unsigned int>(bat.first, bat.second));
        }
    }
    return liste;
}

void CentreAffaires::declencher_effet(vector<Joueur *> &tab_joueurs, unsigned int joueur_actuel) {
    /// Effet du Centre d'affaires
    Joueur* j_actuel = tab_joueurs[joueur_actuel];
    
    // Choix du joueur
    unsigned int num_joueur;
    // Affichage des joueurs
    cout << "Liste des joueurs : " << endl;
    for (int i = 0; i < tab_joueurs.size(); i++) {
        cout << i << ". " << tab_joueurs[i]->get_nom() << endl;
    }
    
    // Demande du nombre et validité de la saisie
    cout << "Entrez le numéro associé au joueur qui va vous donner 5 pièces : ";
    cin >> num_joueur;
    while (num_joueur < 0 || num_joueur >= tab_joueurs.size() || num_joueur == joueur_actuel) {
        cout << "Erreur dans la saisie. Veuillez saisir un nombre valide : ";
        cin >> num_joueur;
    }
    Joueur* joueur_echange = tab_joueurs[num_joueur];
    cout << "Vous allez procédé à un échange avec " << joueur_echange->get_nom() << endl;
    
    
    // Liste des batiments du joueur actuel et de l'autre joueur
    unsigned int bat_don;
    auto liste_batiments_echange = get_liste_bat_non_special(joueur_echange);
    auto liste_batiments_joueur = get_liste_bat_non_special(j_actuel);

    // Demande du batiment à échanger
    cout << "Les bâtiments que vous pouvez donner : " << endl;
    unsigned int i = 0;
    for (auto bat : liste_batiments_joueur){
            cout << i << ". " << bat.first->get_nom() << endl;
        i++;
    }
    
    // Demande du batiment à donner et validité de la saisie
    cout << "Entrez le numéro du batiment que vous voulez donnez : ";
    cin >> bat_don;
    while (bat_don < 0 || bat_don >= liste_batiments_joueur.size()) {
        cout << "Erreur dans la saisie. Veuillez saisir un nombre valide : ";
        cin >> bat_don;
    }
    // On trouve à partir du numéro le batiment associé
    pair<Batiment *, unsigned int> batiment_a_donner;
    i = 0;
    for (auto bat : liste_batiments_joueur){
        if (i == bat_don) batiment_a_donner = bat;
        i++;
    }
    // Affichage du récapitulatif
    cout << "Vous allez donner à " << joueur_echange->get_nom() << " le bâtiment " << batiment_a_donner.first->get_nom();


    // Demande du batiment à recevoir en échange
    unsigned int bat_recu;
    cout << "Les bâtiments que vous pouvez donner : " << endl;
    i = 0;
    for (auto bat : liste_batiments_joueur){
        cout << i << ". " << bat.first->get_nom() << endl;
        i++;
    }

    // Demande du batiment à recevoir en échange et validité de la saisie
    cout << "Entrez le numéro du batiment que vous voulez donnez : ";
    cin >> bat_recu;
    while (bat_recu < 0 || bat_recu >= liste_batiments_echange.size()) {
        cout << "Erreur dans la saisie. Veuillez saisir un nombre valide : ";
        cin >> bat_recu;
    }

    // On trouve à partir du numéro le batiment associé
    pair<Batiment *, unsigned int> batiment_a_recevoir;
    i = 0;
    for (auto bat : liste_batiments_joueur){
        if (i == bat_recu) batiment_a_recevoir = bat;
        i++;
    }
    // Affichage du récapitulatif
    cout << "Vous allez recevoir de " << joueur_echange->get_nom() << " le bâtiment " << batiment_a_recevoir.first->get_nom();


    // Echange des batiments

    // On retire le bat à donner du joueur actuel
    // Si un seul exemplaire du batiment, on le supprime
    if (batiment_a_donner.second == 1)
    {
        j_actuel->get_liste_batiment().erase(batiment_a_donner.first);
    }
    else
    {
        // Sinon, on décrémente sa quantité de 1
        j_actuel->get_liste_batiment().find(batiment_a_donner.first)->second--;
    }

    // Ajout du batiment à donner au joueur de l'échange
    auto element = joueur_echange->get_liste_batiment().find(batiment_a_donner.first);
    if (element != joueur_echange->get_liste_batiment().end()){
        element->second++;
    }
    else{
        joueur_echange->get_liste_batiment().insert(pair<Batiment*, unsigned int>(batiment_a_donner.first, 1));
    }

    // On retire le bat à recevoir du joueur échange
    // Si un seul exemplaire du batiment, on le supprime
    if (batiment_a_recevoir.second == 1)
    {
        joueur_echange->get_liste_batiment().erase(batiment_a_recevoir.first);
    }
    else
    {
        // Sinon, on décrémente sa quantité de 1
        joueur_echange->get_liste_batiment().find(batiment_a_recevoir.first)->second--;
    }

    // Ajout du batiment à recevoir au joueur actuel
    auto element2 = j_actuel->get_liste_batiment().find(batiment_a_recevoir.first);
    // S'il a déjà un exemplaire de ce bâtiment, on incrémente sa quantité
    if (element2 != j_actuel->get_liste_batiment().end()){
        element2->second++;
    }
    // Sinon, on ajoute le batiment à sa liste
    else{
        j_actuel->get_liste_batiment().insert(pair<Batiment*, unsigned int>(batiment_a_recevoir.first, 1));
    }
}



