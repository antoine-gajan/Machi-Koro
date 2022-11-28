#include "utils.h"


unsigned int count_type(Joueur *joueur, const string& type) {
    unsigned int count = 0;

    // pour chaque couleur de la liste de batissements du joueur
    for (auto it=joueur->get_liste_batiment().begin(); it!=joueur->get_liste_batiment().end(); ++it) {

        // pour chaque batiment de la couleur, (batiments sous forme de map(Batiment*, unsigned int))
        map<Batiment*, unsigned int>::iterator it2;
        for (it2=it->second.begin(); it2!=it->second.end(); ++it2) {
            if (it2->first->get_type() == type) {
                count += it2->second;
            }
        }
    }

    return count;
}

unsigned int selectionner_joueur(vector<Joueur*>& tab_joueurs, unsigned int joueur_actuel){
    unsigned int count = 0;
    string nom_joueur;
    auto it = tab_joueurs.begin();

    //Affichage de tous les joueus de tab_joueurs
    std::cout<<"Quel joueur voulez vous choisir parmis la liste suivante :";
    for(Joueur* curseur:tab_joueurs){
        std::cout<<"\n -"<<curseur->get_nom();
    }

    //Scan de tab_joueurs à la recherche du nom entré
    std::cin >> nom_joueur;
    while(tab_joueurs.at(count)->get_nom() != nom_joueur && it != tab_joueurs.end()){
        count++;
        it++;
    }

    //cas où erreur (nom entré pas dans la liste ou nom entré = joueur actuel)
    if(it == tab_joueurs.end()) throw invalid_argument("Le nom entré n'est pas valide");
    if(count == joueur_actuel) throw invalid_argument("On ne peut pas sélectionner le joueur actuel");

    return count;
}

Batiment* selectionner_batiment(Joueur *joueur){
    map<string, map<Batiment*, unsigned int>>::iterator it;
    map<Batiment*, unsigned int>::iterator it2;
    string nom_bat;
    unsigned int check = 0;
    Batiment* bat_a_retourner;

    std::cout<<"Quel batiment voulez-vous sélectionner parmis la liste ci-dessous :";
    // affichage des batiments que le joueur possède
    // pour chaque couleur de la liste de batiments du joueur
    for (it=joueur->get_liste_batiment().begin(); it!=joueur->get_liste_batiment().end(); ++it) {

        // pour chaque batiment de la couleur, (batiments sous forme de map(Batiment*, unsigned int))
        for (it2=it->second.begin(); it2!=it->second.end(); ++it2) {
            cout<<"\n -"<<it2->first->get_nom();
        }
    }

    cin >> nom_bat;

    it = joueur->get_liste_batiment().begin();
    it2 = it->second.begin();
    //on vient parcourir pour chaque couleur
    while(it!=joueur->get_liste_batiment().end() && check!=1){
        //on vient parcourir pour chaque carte dans un groupe de couleur
        while(it2!=it->second.end() && it2->first->get_nom()!=nom_bat){
            it2++;
        }
        //attribut check pour exit le premier while (à voir s'il n'est pas possible de faire plus simple?)
        if(it2->first->get_nom()==nom_bat){
            check = 1;
            bat_a_retourner = it2->first;
        }
        it++;
    }

    //cas où erreur (batiment entré pas dans la liste)
    if(it == joueur->get_liste_batiment().end()) throw invalid_argument("Le batiment entré n'est pas valide");

    return bat_a_retourner;
}

Monument* selectionner_monument(Joueur *joueur){
    /// TODO
    /// ERREUR IT
    string nom_monu;
    Monument* monu_a_retourner;

    std::cout<<"Quel monument voulez-vous sélectionner parmis la liste ci-dessous :";
    // affichage des batiments que le joueur possède
    // pour chaque couleur de la liste de batiments du joueur
    for (auto it=joueur->get_liste_monument().begin(); it!=joueur->get_liste_monument().end(); ++it) {

        // pour chaque batiment de la couleur, (batiments sous forme de map(Batiment*, unsigned int))
            cout<<"\n -"<<it->first->get_nom();
    }

    cin >> nom_monu;

    auto it = joueur->get_liste_batiment().begin();
    //on vient parcourir pour chaque couleur
    while(it!=joueur->get_liste_monument().end() && it->first.get_nom()!=nom_monu){
        //on vient parcourir pour chaque carte dans un groupe de couleur
        it++;
    }

    //cas où erreur (batiment entré pas dans la liste)
    if(it == joueur->get_liste_monument().end()) {
        throw invalid_argument("Le monument entré n'est pas valide");
    }else{
        monu_a_retourner = it->first;
    }

    return monu_a_retourner;
}

map<Batiment*, unsigned int> get_liste_bat_non_special(Joueur* j){
    map<Batiment* ,unsigned int> liste;
    for (auto couleur : j->get_liste_batiment()){
        for (auto bat : couleur.second){
            if (bat.first->get_type() != "spécial")
            {
                liste.insert(pair<Batiment*, unsigned int>(bat.first, bat.second));
            }
        }
    }
    return liste;
}

void swap_bat_players(Joueur *j1, Joueur *j2, const string& bat1, const string& bat2){
    ///Fonction qui échange les batiments de 2 joueurs
    //Trouver le batiment dans la liste du joueur 1
    pair<Batiment*, unsigned int> batiment1;
    for (auto couleur : j1->get_liste_batiment()){
        for (auto bat : couleur.second){
            if (bat.first->get_nom() == bat1)
            {
                batiment1 = bat;
            }
        }
    }

    //Trouver le batiment dans la liste du joueur 2
    pair<Batiment*, unsigned int> batiment2;
    for (auto couleur : j1->get_liste_batiment()){
        for (auto bat : couleur.second){
            if (bat.first->get_nom() == bat2)
            {
                batiment2 = bat;
            }
        }
    }
    // On retire le bat à donner du joueur actuel
    // Si un seul exemplaire du batiment, on le supprime
    if (batiment1.second == 1)
    {
        j1->get_liste_batiment()[batiment1.first->get_couleur()].erase(batiment1.first);
    }
    else
    {
        // Sinon, on décrémente sa quantité de 1
        j1->get_liste_batiment()[batiment1.first->get_couleur()].find(batiment1.first)->second--;
    }

    // Ajout du batiment à donner au joueur de l'échange
    auto element = j2->get_liste_batiment()[batiment1.first->get_couleur()].find(batiment1.first);
    // Si le joueur a déjà un batiment de ce type
    if (element != j2->get_liste_batiment()[batiment1.first->get_couleur()].end()){
        element->second++;
    }
    // Sinon, on crée le batiment pour le joueur
    else{
        j2->get_liste_batiment()[batiment1.first->get_couleur()].insert(pair<Batiment*, unsigned int>(batiment1.first, 1));
    }

    // On retire le bat à recevoir du joueur échange
    // Si un seul exemplaire du batiment, on le supprime
    if (batiment2.second == 1)
    {
        j2->get_liste_batiment()[batiment2.first->get_couleur()].erase(batiment2.first);
    }
    else
    {
        // Sinon, on décrémente sa quantité de 1
        j2->get_liste_batiment()[batiment2.first->get_couleur()].find(batiment2.first)->second--;
    }

    // Ajout du batiment à recevoir au joueur actuel
    auto element2 = j2->get_liste_batiment()[batiment1.first->get_couleur()].find(batiment1.first);
    // Si le joueur a déjà un batiment de ce type
    if (element2 != j2->get_liste_batiment()[batiment1.first->get_couleur()].end()){
        element2->second++;
    }
        // Sinon, on crée le batiment pour le joueur
    else{
        j2->get_liste_batiment()[batiment1.first->get_couleur()].insert(pair<Batiment*, unsigned int>(batiment1.first, 1));
    }
}
