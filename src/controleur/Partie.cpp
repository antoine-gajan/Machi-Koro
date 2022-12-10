#include "Partie.h"
#include <algorithm>

Partie::Partie(EditionDeJeu* edition, const vector<EditionDeJeu *>& extensions) : nb_monuments_win(0), joueur_actuel(0), de_1(0), de_2(0) {
    ///Constructeur de Partie

    //Initialisation des variables utiles
    unsigned int max_joueurs = edition->get_nb_joueurs_max();
    unsigned int nb_monuments = edition->get_nb_monuments_win();
    unsigned int format = 0;
    unsigned int nb_tas = 0;


    for (auto bat : edition->get_batiment()) {
        for (unsigned int i = 0; i < bat.second; i++) {
            ajout_batiment(bat.first);
        }
    }
    for (auto monu : edition->get_monument()) {
        list_monuments.push_back(monu);
    }

    if (!extensions.empty()) {
        for (auto ext : extensions) {
            for (auto bat : ext->get_batiment()) {
                for (unsigned int i = 0; i < bat.second; i++) {
                    ajout_batiment(bat.first);
                }
            }
            for (auto monu : ext->get_monument()) {
                list_monuments.push_back(monu);
            }

            if (ext->get_nb_joueurs_max() > max_joueurs) {
                max_joueurs = ext->get_nb_joueurs_max();
            }

            if (ext->get_nb_monuments_win() > nb_monuments) {
                nb_monuments = ext->get_nb_monuments_win();
            }
        }
    }

    // Initialisation du starter
    vector<Batiment*> starter_bat = get_starter();

    // Ajout des joueurs
    for (unsigned int i = 0; i < max_joueurs; i++) {
        // Si plus de 2 joueurs, l'ajout devient optionnel
        if (i >= 2) {
            cout << "Voulez-vous ajouter un joueur ? (0 : non, 1 : oui)" << endl;
            int choix;
            cin >> choix;
            while (choix != 0 && choix != 1) {
                cout << "Veuillez entrer 0 ou 1" << endl;
                cin >> choix;
            }
            if (choix == 0) {
                break;
            }
        }
        // Info du joueur
        cout << "Nom du joueur " << i + 1 << " : "  << endl;
        string nom;
        cin >> nom;
        cout << "\nLe jouer est-il un humain ? (1 : oui, 0 : non)  :" << endl;
        bool humain;
        cin >> humain;
        if (humain) {
            tab_joueurs.push_back(new Joueur(nom, list_monuments, starter_bat, 3));
        }
        // Demande de la strategie IA
        else {
            unsigned int strategie;
            cout << "\nQuelle est la strategie du joueur ? (1 : aleatoire, 2 : agressive, 3 : defensif) :" << endl;
            cin >> strategie;
            while (strategie < 1 || strategie > 3) {
                cout << "\nQuelle est la strategie du joueur ? (1 : aleatoire, 2 : agressive, 3 : defensif) :" << endl;
                cin >> strategie;
            }
            // Ajout du joueur au tableau de joueurs
            switch (strategie) {
                case 1:
                    tab_joueurs.push_back(new Joueur(nom, list_monuments, starter_bat, 3, aleatoire));
                    break;
                case 2:
                    tab_joueurs.push_back(new Joueur(nom, list_monuments, starter_bat, 3, agressive));
                    break;
                case 3:
                    tab_joueurs.push_back(new Joueur(nom, list_monuments, starter_bat, 3, defensif));
                    break;
                default :
                    cout << "Erreur de strategie" << endl;
                    break;
            }
        }
    }

    pioche = new Pioche(map_to_vector(list_batiments));
    // Demande du format du shop
    while (format < 1 || format > 2) {
        cout << "Quel est le format du shop la partie ? (1 : standard, 2 : extended) :" << endl;
        cout <<"1 : standard :" << endl;
        cout << "\tAvec ce format vous pouvez choisir le nombre de tas de cartes que vous voulez." << endl;
        cout << "2 : extended :" << endl;
        cout << "\tAvec ce format toutes les cartes sont dans le shop." << endl;
        cout << "Votre choix : " << endl;
        cin >> format;
    }

    if (format == 1) {
        while (nb_tas < 9 || nb_tas > list_batiments.size() - 1) {
            cout << "Combien de tas voulez-vous ? (9 < tas < " << list_batiments.size() - 1 << ") :" << endl;
            cin >> nb_tas;
        }
    }
    else
        nb_tas = list_batiments.size();

    // Construction du Shop
    shop = new Shop(nb_tas);

    while (!pioche->est_vide() && shop->get_nb_tas_reel() < shop->get_nb_tas_max()){
        shop->completer_shop(pioche->get_carte());
    }

    cout << "Construction de la partie terminee" << endl;
    cout << "Bon jeu !" << endl;
}

void Partie::ajout_batiment(Batiment *batiment) {
    ///Ajoute un batiment dans la liste des batiments
    if (list_batiments.empty()) {
        list_batiments.insert(pair<Batiment* const, unsigned int>(batiment->clone(), 1));
    }
    else {
        bool est_present = false;
        for (auto bat : list_batiments){
            if (bat.first->get_nom() == batiment->get_nom()){
                list_batiments[bat.first] += 1;
                est_present = true;
            }
        }
        if (!est_present){
            list_batiments.insert(pair<Batiment* const, unsigned int>(batiment->clone(), 1));
        }
    }
}

vector<Batiment *> Partie::get_starter() {
    if (list_batiments.empty()) {
        cout << "Erreur : la liste des batiments est vide" << endl;
        return {};
    }
    else {
        vector<Batiment*> starter;
        for (auto bat : list_batiments) {
            if (bat.first->get_nom() == "Boulangerie" && bat.first->get_nom() == "ChampBle")
                starter.push_back(bat.first);
        }
        return starter;
    }
}

void Partie::jouer_partie() {
    ///Fonction principale pour jouer une partie

}


void Partie::jouer_tour() {
    unsigned int de_casse;
    bool deux_des = false;
    bool centre_c = false;
    vector <Monument*> monuments_joueurs = tab_joueurs[joueur_actuel]->get_monument_jouables();

    de_1 = rand() % 6 + 1;
    de_2 = 0;
    de_casse = rand() % 52 + 1;

    // Si le joueur a un centre commercial
    auto it_cc = find_if(monuments_joueurs.begin(), monuments_joueurs.end(), [](Monument* m){return m->get_nom() == "CentreCommercial";});
    if (it_cc != monuments_joueurs.end()){
        // Si le monument est trouvé, on le joue
        centre_c = true;
    }


    /// Monument avant le jet de dé
    auto it_gare = find_if(monuments_joueurs.begin(), monuments_joueurs.end(), [](Monument* m){return m->get_nom() == "Gare";});
    if (it_gare != monuments_joueurs.end()){
        // Si le monument est trouvé, on le joue
        monuments_joueurs[it_gare - monuments_joueurs.begin()]->declencher_effet(joueur_actuel);
    }
    if (de_2 != 0)
        deux_des = true;


    /// Monument apres le jet de dé
    for (auto mon : monuments_joueurs) {
        if (mon->get_nom() == "ParcAttraction" && deux_des && de_1 == de_2 ||
            mon->get_nom() == "TourRadio" ||
            mon->get_nom() == "Port" && deux_des && ((de_1 + de_2) >= 10) ||
            mon->get_nom() == "FabriqueDuPereNoel" && de_casse == 1){
            mon->declencher_effet(joueur_actuel);
        }
    }

    /// Activations des effets des batiments
    /// En premier ce sont les batiments rouges des autres joueurs
    int j_prec = (int)((joueur_actuel + tab_joueurs.size() - 1) % joueur_actuel);
    for (int i = j_prec; i >= 0; i--) {
        for (auto it : tab_joueurs[i]->get_liste_batiment(Rouge)) {
            if (it.first->get_type() == "Restaurant" && centre_c) {
                for (unsigned int effectif = 0; effectif < it.second; effectif++) {
                    it.first->declencher_effet(i, 1);
                }
            }
            else {
                for (unsigned int effectif = 0; effectif < it.second; effectif++) {
                    it.first->declencher_effet(i);
                }
            }
        }
    }
    for (unsigned int i  = joueur_actuel + 1 ; i < tab_joueurs.size(); i++) {
        for (auto it : tab_joueurs[i]->get_liste_batiment(Rouge)) {
            for (unsigned int effectif = 0; effectif < it.second; effectif++) {
                it.first->declencher_effet(i);
            }
        }
    }

    /// Ensuite ce sont les batiments violets du joueur actuel
    for (auto it : tab_joueurs[joueur_actuel]->get_liste_batiment(Violet)) {
        for (unsigned int effectif = 0; effectif < it.second; effectif++) {
            it.first->declencher_effet(joueur_actuel);
        }
    }

    /// Puis, les batiments bleus de tous les joueurs
    for (int i = 0; i < tab_joueurs.size(); i++) {
        for (auto it : tab_joueurs[i]->get_liste_batiment(Bleu)) {
            for (unsigned int effectif = 0; effectif < it.second; effectif++) {
                it.first->declencher_effet(i);
            }
        }
    }

    /// Enfin, les batiments verts du joueur actuel
    for (auto it : tab_joueurs[joueur_actuel]->get_liste_batiment(Vert)) {
        if (it.first->get_type() == "Commerce" && centre_c) {
            for (unsigned int effectif = 0; effectif < it.second; effectif++) {
                it.first->declencher_effet(joueur_actuel, 1);
            }
        }
        else {
            for (unsigned int effectif = 0; effectif < it.second; effectif++) {
                it.first->declencher_effet(joueur_actuel);
            }
        }
    }
    /// Fin des effets des batiments

    /// Début de la phase de construction
    auto it_hdv = find_if(monuments_joueurs.begin(), monuments_joueurs.end(), [](Monument* m){return m->get_nom() == "HotelDeVille";});
    if (it_hdv != monuments_joueurs.end()){
        // Si le monument est trouvé, on le joue
        monuments_joueurs[it_hdv - monuments_joueurs.begin()]->declencher_effet(joueur_actuel);
    }


    /// Fin de la phase de construction
    /// Fin du tour

    joueur_actuel = (joueur_actuel + 1) % tab_joueurs.size();
}

void Partie::rejouer_tour() {
    joueur_actuel = (joueur_actuel + tab_joueurs.size() - 1) % tab_joueurs.size();
}

void Partie::acheter_carte() {

    //fonction qui permet a un joueur donne d'acheter une carte (batiment ou monument)
    string choix;
    //Joueur *joueur_actuel = tab_joueurs[indice_joueur_actuel];

    cout<<"Que voulez vous faire, acheter un batiment (b), un monument (m), ou rien (r)?\n"<<endl;
    cin>>choix;

    if(choix == "b"){
        acheter_bat();
    }else if(choix == "m"){
        acheter_monu();
    }else{
        return;
    }
}

void Partie::acheter_bat() {
    //fonction qui permet a un joueur donne d'acheter un batiment
    string nom_bat;
    Batiment* bat_picked;
    Joueur *joueur_act = tab_joueurs[joueur_actuel];
    unsigned int choix = 0;
    auto it = shop->get_contenu().begin();

    while(choix != 1){
        cout<<"Quelle carte voulez vous acheter parmis celles-ci :"<<endl;
        shop->affiche_shop();
        cout<<"Veuillez rentrer le nom de la carte : \n"<<endl;
        cin>>nom_bat;

        while(it != shop->get_contenu().end() || it->first->get_nom() != nom_bat) {it++;}

        if(it == shop->get_contenu().end()) throw invalid_argument("Le batiment entre n'est pas dans le shop");

        if(bat_picked->get_prix() < joueur_act->get_argent()){
            bat_picked = shop->acheter_batiment(bat_picked);
            if(!pioche->est_vide()){
                shop->completer_shop(pioche->get_carte());
            }else{
                cout<<"Plus de cartes dans la pioche"<<endl;
            }

            joueur_act->ajouter_batiment(bat_picked);
            joueur_act->set_argent(joueur_act->get_argent() - bat_picked->get_prix());
        }else{
            cout<<"Vous n'avez pas assez d'argent pour acheter ce batiment"<<endl;
        }

        cout<<"Voulez vous acheter a nouveau un batiment (1 pour non 0 pour oui)?"<<endl;
        cin>>choix;
    }
}

void Partie::acheter_monu() {
    //fonction qui permet a un joueur donne d'acheter un monument
    string nom_monu;
    Monument* monu_picked;
    Joueur *joueur_act = tab_joueurs[joueur_actuel];
    unsigned int choix = 0;
    auto it = list_monuments.begin();

    while(choix != 1){
        cout<<"Quel est le nom du monument que vous voulez acheter?"<<endl;
        for(auto mon : list_monuments) cout<<mon->get_nom()<<"\n"<<endl;
        cin>>nom_monu;

        while(it != list_monuments.end() || (*it)->get_nom() != nom_monu) {it++;}
        if(it == list_monuments.end()) throw invalid_argument("Erreur de frappe, ce monument n'existe pas");

        monu_picked = *it;
        if(monu_picked->get_prix() < joueur_act->get_argent()){
            joueur_act->set_argent(joueur_act->get_argent() - monu_picked->get_prix());
            joueur_act->activer_monument(monu_picked);
        }else{
            cout<<"Vous n'avez pas assez d'argent pour acheter ce monument"<<endl;
        }
        cout<<"Voulez vous acheter a nouveau un monument (1 pour non 0 pour oui)?"<<endl;
        cin>>choix;
    }
}

bool Partie::echanger_argent(unsigned int indice_joueur1, unsigned int indice_joueur2, unsigned int somme){
    //methode qui permet d'echanger une somme d'argent entre deux joueurs

    Joueur *joueur1 = tab_joueurs[indice_joueur1];
    Joueur *joueur2 = tab_joueurs[indice_joueur2];
    if(somme == 0){
        return false;
    }
    if(joueur1->get_argent() == somme) {
        joueur1->set_argent(0);
        joueur2->set_argent(joueur2->get_argent() + somme);
    }
    else if(joueur1->get_argent() < somme){
        unsigned int argent_joueur1 = joueur1->get_argent();
        joueur1->set_argent(0);
        joueur2->set_argent(joueur2->get_argent() + argent_joueur1);
    }
    else if(joueur1->get_argent() > somme){
        joueur1->set_argent(joueur1->get_argent() - somme);
        joueur2->set_argent(joueur2->get_argent() + somme);
    }
    return true;
    /*cout<<"Dans quel sens souhaitez faire l'echange (1) pour "<<joueur1->get_nom()<<" vers "<<joueur2->get_nom()<<" ou (2) pour "<<joueur2->get_nom()<<" vers "<< joueur1->get_nom()<<endl;
    cin>>sens;
    cout<<"Quelle somme souhaitez vous transferer?"<<endl;
    cin>>somme;
    if(sens == 1){
        joueur1->set_argent(max((unsigned int)0,joueur1->get_argent() - somme));
        joueur2->set_argent(joueur2->get_argent() + somme);
    }else if(sens == 2){
        joueur2->set_argent(max((unsigned int)0,joueur2->get_argent() - somme));
        joueur1->set_argent(joueur1->get_argent() + somme);
    }else{
        cout<<"On ne peut choisir que (1) ou (2)"<<endl;
    }*/
}

bool Partie::est_gagnant(Joueur *joueur) const {
    ///Fonction pour verifier si un joueur a gagne
    return joueur->get_monument_jouables().size() >= nb_monuments_win;
}

/* Methodes statiques */

unsigned int Partie::count_type(Joueur *joueur, const string& type) {
    unsigned int count = 0;
    auto liste_bat = joueur->get_liste_batiment();
    // pour chaque couleur de la liste de batiments du joueur
    for (const auto& couleur : liste_bat) {
        // pour chaque batiment de la couleur, (batiments sous forme de map(Batiment*, unsigned int))
        for (auto batiment : liste_bat[couleur.first]) {
            if (batiment.first->get_type() == type) {
                count += batiment.second;
            }
        }
    }
    return count;
}

unsigned int Partie::selectionner_joueur(vector<Joueur*>& tab_joueurs, unsigned int joueur_actuel){
    unsigned int count = 0;
    string nom_joueur;
    auto it = tab_joueurs.begin();

    //Affichage de tous les joueus de tab_joueurs
    std::cout<<"Quel joueur voulez vous choisir parmis la liste suivante :";
    for(Joueur* curseur:tab_joueurs){
        std::cout<<"\n -"<<curseur->get_nom();
    }

    //Scan de tab_joueurs a la recherche du nom entre
    std::cin >> nom_joueur;
    while(tab_joueurs.at(count)->get_nom() != nom_joueur && it != tab_joueurs.end()){
        count++;
        it++;
    }

    //cas où erreur (nom entre pas dans la liste ou nom entre = joueur actuel)
    if(it == tab_joueurs.end()) throw invalid_argument("Le nom entre n'est pas valide");
    if(count == joueur_actuel) throw invalid_argument("On ne peut pas selectionner le joueur actuel");

    return count;
}

Batiment* Partie::selectionner_batiment(Joueur *joueur){
    map<couleur_bat, map<Batiment*, unsigned int>>::iterator it;
    map<Batiment*, unsigned int>::iterator it2;
    string nom_bat;
    unsigned int check = 0;
    Batiment* bat_a_retourner;

    std::cout<<"Quel batiment voulez-vous selectionner parmis la liste ci-dessous :";
    // affichage des monuments que le joueur possede
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
        //attribut check pour exit le premier while (a voir s'il n'est pas possible de faire plus simple?)
        if(it2->first->get_nom()==nom_bat){
            check = 1;
            bat_a_retourner = it2->first;
        }
        it++;
    }

    //cas où erreur (batiment entre pas dans la liste)
    if(it == joueur->get_liste_batiment().end()) throw invalid_argument("Le batiment entre n'est pas valide");

    return bat_a_retourner;
}

Batiment* Partie::possede_batiment(Joueur *joueur, const string& nom_bat){
    auto liste_bat = joueur->get_liste_batiment();
    // pour chaque couleur de la liste de batiments du joueur
    for (const auto& couleur : liste_bat) {
        // pour chaque batiment de la couleur, (batiments sous forme de map(Batiment*, unsigned int))
        for (auto batiment : liste_bat[couleur.first]) {
            // Si c'est l'element qu'on recherche, on le renvoie
            if (batiment.first->get_nom() == nom_bat) {
                return batiment.first;
            }
        }
    }
    // Sinon, retourne nullptr
    return nullptr;
}

Monument* Partie::selectionner_monument(Joueur *joueur){
    string nom_monu;
    Monument* monu_a_retourner;

    std::cout<<"Quel monument voulez-vous selectionner parmis la liste ci-dessous :";
    // affichage des monuments que le joueur possede
    // pour chaque monument du joueur
    for (auto monu : joueur->get_liste_monument()) {
        cout << "\n -" << monu.first->get_nom();
    }

    cin >> nom_monu;

    //parcours des monuments du joueur a la recherche du monument a trouver
    auto it = joueur->get_liste_monument().begin();
    while(it!=joueur->get_liste_monument().end() && it->first->get_nom()!=nom_monu){
        it++;
    }

    //cas où erreur (monument entre pas dans la liste)
    if(it == joueur->get_liste_monument().end()) {
        throw invalid_argument("Le monument entre n'est pas valide");
    }else{
        monu_a_retourner = it->first;
    }

    return monu_a_retourner;
}

Monument* Partie::possede_monument(Joueur *joueur, const string& nom_mon){
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
    for (const auto& couleur : j->get_liste_batiment()){
        for (auto bat : couleur.second){
            if (bat.first->get_type() != "special")
            {
                liste.insert(pair<Batiment*, unsigned int>(bat.first, bat.second));
            }
        }
    }
    return liste;
}

void Partie::swap_bat_players(Joueur *j1, Joueur *j2, Batiment* bat1, Batiment* bat2){
    ///Fonction qui echange les batiments de 2 joueurs
    // Gestion du batiment 2 dans l'echange
    j2->retirer_batiment(bat2);
    j1->ajouter_batiment(bat2);
    // Gestion du batiment 1 dans l'echange
    j1->retirer_batiment(bat1);
    j2->ajouter_batiment(bat1);
}

void Partie::don_argent(Joueur* j1, unsigned int argent, Joueur* j2){
    /// Don d'argent du joueur j1 au joueur j2
    if (j1->get_argent() - argent >= 0){
        j1->set_argent(j1->get_argent() - argent);
        j2->set_argent(j2->get_argent() + argent);
    }
    else{
        cout << "Impossible, le joueur " << j1->get_nom() << " n'a pas assez d'argent." << endl;
    }
}

vector<Batiment*> Partie::map_to_vector(const map<Batiment*, unsigned int>& map_batiments){
    /// Retourne un vecteur avec l'adresse des batiments
    vector<Batiment*> vector_batiments;
    for(auto batiment : map_batiments){
        for(unsigned int i = 0; i < batiment.second; i++){
            vector_batiments.push_back(batiment.first);
        }
    }

    // Mélange du vecteur
    // Obtention d'un nombre aleatoire (seed)
    random_device rd;
    mt19937 g(rd());

    // Mélange du vecteur avec le seed
    shuffle(vector_batiments.begin(), vector_batiments.end(), g);

    return vector_batiments;
}