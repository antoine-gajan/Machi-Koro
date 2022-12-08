#include "utils.h"
#define REP_ED_MIN 1
#define REP_ED_MAX 3

#define REP_EXT_MIN 1
#define REP_EXT_MAX 4

void menu () {
    int rep_ed = -1;
    vector<EditionDeJeu *> listing_edition;

    cout << "/********\tMenu\t********/" << endl;
    while (!(REP_ED_MIN <= rep_ed && rep_ed <= REP_ED_MAX)) {
        cout << "\nVeuillez-choisir une edition :\n"
                "\t1. Standard\n"
                "\t2. Deluxe\n"
                "\t3. Quitter\n"
                "Votre choix :" << endl;
        cin >> rep_ed;
    }

    if (rep_ed == 1) {
        listing_edition.push_back(new EditionDeJeu("Standard"));
        int rep_ext = -1;
        while (!(REP_EXT_MIN <= rep_ext && rep_ext <= REP_EXT_MAX)) {
            cout << "Vous avez choisi l'edition standard\n"
                    "Vous pouvez jouer avec des extensions\n"
                    "Avec laquelle voulez-vous jouer ?\n"
                    "\t1. Green-Valley\n"
                    "\t2. Marina\n"
                    "\t3. Les deux (Marina + Green-Valley)\n"
                    "\t4. Aucune\n"
                    "Votre choix :" << endl;
            cin >> rep_ext;
        }
        if (rep_ext == 1)
            listing_edition.push_back(new EditionDeJeu("GreenValley"));
        else if (rep_ext == 2)
            listing_edition.push_back(new EditionDeJeu("Marina"));
        else if (rep_ext == 3) {
            listing_edition.push_back(new EditionDeJeu("GreenValley"));
            listing_edition.push_back(new EditionDeJeu("Marina"));
        }
        else
            cout << "Vous avez choisi de jouer sans extension"<< endl;


    } else if (rep_ed == 2) {
        listing_edition.push_back(new EditionDeJeu("Deluxe"));
    } else if (rep_ed == 3) {
        cout << "Vous avez choisi de quitter." << endl;
    }


    vector<Monument*> list_total_monument;
    map<Monument*, unsigned int> list_total_batiment;

    /// Ajout des monuments :
    for (auto edj : listing_edition) {
        for (Monument * mon : edj->get_monument())
            list_total_monument.push_back(mon);
    }

    /// Ajout des batiments :
    for (auto edj : listing_edition) {
        for (auto bat_it : edj->get_batiment()) {
            /// TODO
            // si pas deja present simple ajout
            // sinon on augmente le nombre
        }
    }

    /// Creation de la partie

    cout << "/********\tFin\t********/" << endl;
}

unsigned int count_type(Joueur *joueur, const string& type) {
    unsigned int count = 0;
    auto liste_bat = joueur->get_liste_batiment();
    // pour chaque couleur de la liste de batiments du joueur
    for (auto couleur : liste_bat) {
        // pour chaque batiment de la couleur, (batiments sous forme de map(Batiment*, unsigned int))
        for (auto batiment : liste_bat[couleur.first]) {
            if (batiment.first->get_type() == type) {
                count += batiment.second;
            }
        }
    }
    return count;
}

unsigned int selectionner_joueur(vector<Joueur*>& tab_joueurs, unsigned int joueur_actuel){
    unsigned int count = 0;
    string nom_joueur;
    vector<Joueur*>::iterator it = tab_joueurs.begin();

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
    map<couleur_bat, map<Batiment*, unsigned int>>::iterator it;
    map<Batiment*, unsigned int>::iterator it2;
    string nom_bat;
    unsigned int check = 0;
    Batiment* bat_a_retourner;

    std::cout<<"Quel batiment voulez-vous sélectionner parmis la liste ci-dessous :";
    // affichage des monuments que le joueur possède
    // pour chaque couleur de la liste de batiment du joueur
    for (it=joueur->get_liste_batiment().begin();it!=joueur->get_liste_batiment().end();++it) {

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

Batiment* possede_batiment(Joueur *joueur,string nom_bat){
    auto liste_bat = joueur->get_liste_batiment();
    // pour chaque couleur de la liste de batiments du joueur
    for (auto couleur : liste_bat) {
        // pour chaque batiment de la couleur, (batiments sous forme de map(Batiment*, unsigned int))
        for (auto batiment : liste_bat[couleur.first]) {
            // Si c'est l'élement qu'on recherche, on le renvoie
            if (batiment.first->get_nom() == nom_bat) {
                 return batiment.first;
            }
        }
    }
    // Sinon, retourne nullptr
    return nullptr;
}

Monument* selectionner_monument(Joueur *joueur){
    string nom_monu;
    Monument* monu_a_retourner;
    auto it = joueur->get_liste_monument().begin();

    std::cout<<"Quel monument voulez-vous sélectionner parmis la liste ci-dessous :";
    // affichage des monuments que le joueur possède
    // pour chaque monument du joueur
    for (it; it!=joueur->get_liste_monument().end(); ++it) {
            cout<<"\n -"<<it->first->get_nom();
    }

    cin >> nom_monu;

    //parcours des monuments du joueur à la recherche du monument à trouver
    it = joueur->get_liste_monument().begin();
    while(it!=joueur->get_liste_monument().end() && it->first->get_nom()!=nom_monu){
        it++;
    }

    //cas où erreur (monument entré pas dans la liste)
    if(it == joueur->get_liste_monument().end()) {
        throw invalid_argument("Le monument entré n'est pas valide");
    }else{
        monu_a_retourner = it->first;
    }

    return monu_a_retourner;
}

Monument* possede_monument(Joueur *joueur,string nom_mon){
    auto liste_mon = joueur->get_liste_monument();
    // pour chaque monument dans la liste de monuments du joueur
    for (auto mon : liste_mon) {
        if (mon.first->get_nom() == nom_mon) {
            return mon.first;
        }
    }
    // Sinon, retourne nullptr
    return nullptr;
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

void swap_bat_players(Joueur *j1, Joueur *j2, Batiment* bat1, Batiment* bat2){
    ///Fonction qui échange les batiments de 2 joueurs
    // Gestion du batiment 2 dans l'échange
    j2->retirer_batiment(bat2);
    j1->ajouter_batiment(bat2);
    // Gestion du batiment 1 dans l'échange
    j1->retirer_batiment(bat1);
    j2->ajouter_batiment(bat1);
}

void don_argent(Joueur* j1, unsigned int argent, Joueur* j2){
    /// Don d'argent du joueur j1 au joueur j2
    if (j1->get_argent() - argent >= 0){
        j1->set_argent(j1->get_argent() - argent);
        j2->set_argent(j2->get_argent() + argent);
    }
    else{
        cout << "Impossible, le joueur " << j1->get_nom() << " n'a pas assez d'argent." << endl;
    }
}

void echange_argent(Joueur* j1, unsigned int arg1, Joueur* j2, unsigned int arg2){
    /// Echange d'argent entre j1 et j2
    // Don d'arg1 de j1 à j2
    don_argent(j1, arg1, j2);
    // Don d'arg2 de j2 à j1
    don_argent(j2, arg2, j1);
}

