#include "Partie.h"
#include <algorithm>

Partie::Partie(EditionDeJeu* edition, vector<EditionDeJeu *> extensions) : nb_monuments_win(0), joueur_actuel(0) {
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

vector<Batiment*> Partie::map_to_vector(map<Batiment*, unsigned int> map_batiments){
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
    ///Fonction pour jouer un tour
    Joueur *j_actuel = tab_joueurs[joueur_actuel];
    if (est_gagnant(j_actuel)) {
        cout << "Le joueur " << j_actuel->get_nom() << " a gagne la partie !" << endl;
        return;
    }

    /// Jet de de pour le joueur
    vector<Monument*> monuments_jouables = j_actuel->get_monument_jouables();


    unsigned int res_de1 = rand() % 6 + 1;
    unsigned int res_de2 = 0;
    unsigned int res_tot = res_de1;

    cout << "Le joueur " << j_actuel->get_nom() << " a fait " << res_de1 << endl;



    /// Activation des bâtiments


    /// Phase d'achat
}

void Partie::acheter_carte(unsigned int indice_joueur_actuel) {

    //fonction qui permet a un joueur donne d'acheter une carte (batiment ou monument)
    string choix;
    //Joueur *joueur_actuel = tab_joueurs[indice_joueur_actuel];

    cout<<"Que voulez vous faire, acheter un batiment (b), un monument (m), ou rien (r)?\n"<<endl;
    cin>>choix;

    if(choix == "b"){
        acheter_bat(indice_joueur_actuel);
    }else if(choix == "m"){
        acheter_monu(indice_joueur_actuel);
    }else{
        return;
    }

}

void Partie::acheter_bat(unsigned int indice_joueur_actuel) {
    //fonction qui permet a un joueur donne d'acheter un batiment
    string nom_bat;
    Batiment* bat_picked;
    Joueur *joueur_actuel = tab_joueurs[indice_joueur_actuel];
    unsigned int choix = 0;
    auto it = shop->get_contenu().begin();

    while(choix != 1){
        cout<<"Quelle carte voulez vous acheter parmis celles-ci :"<<endl;
        shop->affiche_shop();
        cout<<"Veuillez rentrer le nom de la carte : \n"<<endl;
        cin>>nom_bat;

        while(it != shop->get_contenu().end() || it->first->get_nom() != nom_bat) {it++;}

        if(it == shop->get_contenu().end()) throw invalid_argument("Le batiment entre n'est pas dans le shop");

        if(bat_picked->get_prix() < joueur_actuel->get_argent()){
            bat_picked = shop->acheter_batiment(bat_picked);
            if(!pioche->est_vide()){
                shop->completer_shop(pioche->get_carte());
            }else{
                cout<<"Plus de cartes dans la pioche"<<endl;
            }

            joueur_actuel->ajouter_batiment(bat_picked);
            joueur_actuel->set_argent(joueur_actuel->get_argent() - bat_picked->get_prix());
        }else{
            cout<<"Vous n'avez pas assez d'argent pour acheter ce batiment"<<endl;
        }

        cout<<"Voulez vous acheter a nouveau un batiment (1 pour non 0 pour oui)?"<<endl;
        cin>>choix;
    }
}

void Partie::acheter_monu(unsigned int indice_joueur_actuel) {
    //fonction qui permet a un joueur donne d'acheter un monument
    string nom_monu;
    Monument* monu_picked;
    Joueur *joueur_actuel = tab_joueurs[indice_joueur_actuel];
    unsigned int choix = 0;
    auto it = list_monuments.begin();

    while(choix != 1){
        cout<<"Quel est le nom du monument que vous voulez acheter?"<<endl;
        for(auto mon : list_monuments) cout<<mon->get_nom()<<"\n"<<endl;
        cin>>nom_monu;

        while(it != list_monuments.end() || (*it)->get_nom() != nom_monu) {it++;}
        if(it == list_monuments.end()) throw invalid_argument("Erreur de frappe, ce monument n'existe pas");

        monu_picked = *it;
        if(monu_picked->get_prix() < joueur_actuel->get_argent()){
            joueur_actuel->set_argent(joueur_actuel->get_argent() - monu_picked->get_prix());
            joueur_actuel->activer_monument(monu_picked);
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

bool Partie::est_gagnant(Joueur *joueur) {
    ///Fonction pour verifier si un joueur a gagne
    return joueur->get_monument_jouables().size() >= nb_monuments_win;
}