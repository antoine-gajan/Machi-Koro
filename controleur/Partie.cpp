#include <QRadioButton>
#include <QCoreApplication>
#include <QTime>
#include "Partie.h"
#include "VuePartie.h"

Partie::Handler Partie::handler=Partie::Handler();


Partie* Partie::get_instance(const string &edition_name, const list<string> &extensions_names, const map<string, string>& joueurs, const string& shop_type, unsigned int shop_size) {
    if (handler.instance == nullptr) {
        int rep_ed = -1;
        EditionDeJeu * edition;
        vector<EditionDeJeu *> listing_extension;

        if (edition_name == "Standard") {
            edition = new EditionDeJeu("Standard");

            for (const auto & extensions_name : extensions_names) {
                listing_extension.push_back(new EditionDeJeu(extensions_name));
            }

        }
        else if (edition_name == "Deluxe") {
            edition = new EditionDeJeu("Deluxe");
        }
        else if (edition_name == "Custom") {
            edition = new EditionDeJeu("Custom");
        }
        else {
            throw gameException("Edition inconnue");
        }

        handler.instance = new Partie(edition, joueurs, shop_type, shop_size, listing_extension);

        delete edition;

        for (auto & extension : listing_extension)
            delete extension;
    }

    return handler.instance;
}


Partie* Partie::get_instance() {
    if (handler.instance == nullptr) {
        throw gameException("Partie non initialisee");
    }
    return handler.instance;
}

Partie::Partie(EditionDeJeu* edition, const map<string, string>& joueurs, const string& shop_type, unsigned int shop_size, const vector<EditionDeJeu *>& extensions) : nb_monuments_win(edition->get_nb_monuments_win()), joueur_actuel(0), de_1(0), de_2(0) {
    ///Constructeur de Partie

    //Initialisation des variables utiles
    rejouer = false;

    tab_nom_edition.push_back(edition->get_nom());
    for (auto & extension : extensions)
        tab_nom_edition.push_back(extension->get_nom());

    for (auto bat : edition->get_batiment()) {
        for (unsigned int i = 0; i < bat.second; i++) {
            ajout_batiment(bat.first);
        }
    }

    for (auto monu : edition->get_monument()) {
        list_monuments.push_back(monu->clone());
    }

    if (!extensions.empty()) {
        for (auto ext : extensions) {
            for (auto bat : ext->get_batiment()) {
                for (unsigned int i = 0; i < bat.second; i++) {
                    ajout_batiment(bat.first);
                }
            }
            for (auto monu : ext->get_monument()) {
                list_monuments.push_back(monu->clone());
            }

            if (ext->get_nb_monuments_win() > nb_monuments_win)
                nb_monuments_win = ext->get_nb_monuments_win();

        }
    }

    // Initialisation du starter
    vector<Batiment*> starter_bat = get_starter();

    // Ajout des joueurs
    for (auto & joueur : joueurs){

        if (joueur.second == "Humain") {
            //tab_joueurs.push_back(new Joueur(joueur.first, list_monuments, starter_bat, 3));
            tab_joueurs.push_back(new Joueur(joueur.first, list_monuments, starter_bat, 390));
        }
        else {
            if (joueur.second == "IA agressive") {
                tab_joueurs.push_back(new Joueur(joueur.first, list_monuments, starter_bat, 3, agressive));
            }
            else if (joueur.second == "IA défensive") {
                tab_joueurs.push_back(new Joueur(joueur.first, list_monuments, starter_bat, 3, defensif));
            }
            else if (joueur.second == "IA aléatoire") {
                tab_joueurs.push_back(new Joueur(joueur.first, list_monuments, starter_bat, 3, aleatoire));
            }
            else {
                throw gameException("Type de joueur inconnu");
            }
        }
    }

    pioche = new Pioche(map_to_vector(list_batiments));

    if (shop_type == "standard") {    // Construction du Shop
        shop = new Shop(shop_size);

        while (!pioche->est_vide() && shop->get_nb_tas_reel() < shop->get_nb_tas_max()){
            try  {
                shop->completer_shop(pioche->get_carte());
            }
            catch(exception const& e){
                cerr << "ERREUR : " << e.what() << endl;
            }
        }
    } else {
        shop = new Shop(list_batiments.size());

        while (!pioche->est_vide()){
            try  {
                shop->completer_shop(pioche->get_carte());
            }
            catch(exception const& e){
                cerr << "ERREUR : " << e.what() << endl;
            }
        }
    }
    vue_partie = nullptr;
}


vector<Batiment *> Partie::get_starter() {
    ///Renvoie le starter de la partie
    if (list_batiments.empty()) {
        throw gameException("Aucun batiment dans la liste");
    }
    vector<Batiment*> starter;

    for (auto bat : list_batiments) {
        if (bat.first->get_nom() == "Boulangerie" ||
            bat.first->get_nom() == "ChampBle")
            starter.push_back(bat.first);
        if (starter.size() == 2)
            break;
    }
    return starter;

}


Partie::~Partie() {
    /// Destructeur de la classe Partie
    // Destruction des joueurs
    for (auto joueur : tab_joueurs){
        delete joueur;
    }

    // Destruction des batiments
    for (auto batiment : list_batiments){
        delete batiment.first;
    }

    // Destruction des monuments
    for (auto monument : list_monuments){
        delete monument;
    }

    delete shop;
    delete pioche;
}

void Partie::rejouer_tour() {
    rejouer = true;
}


void Partie::ajout_batiment(Batiment *batiment) {
    ///Ajoute un batiment dans la liste des batiments
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

/*
bool Partie::acheter_carte() {
    //fonction qui permet a un joueur donne d'acheter une carte (batiment ou monument)
    int choix = -1;
    int choix_ia = -1;
    bool visit[2] = {false, false};
    bool transaction_fin = false;

    // Si le joueur est humain
    if (!tab_joueurs[joueur_actuel]->get_est_ia()) {
        // Ouverture d'une fenetre de dialogue
        auto *window = new QDialog();

        window->setWindowTitle("Machi Koro - Acheter une carte");
        window->setContentsMargins(50, 30, 50, 50);
        // Création d'un formulaire
        auto *formLayout = new QFormLayout;

        auto *layout = new QVBoxLayout;

        layout->addWidget(new QLabel());
        layout->addLayout(formLayout);
        layout->addWidget(new QLabel());
        // Ajout des radio boutons pour le choix de batiment ou monument
        auto *batimentRadioButton = new QRadioButton("Batiment");
        auto *monumentRadioButton = new QRadioButton("Monument");
        formLayout->addWidget(batimentRadioButton);
        formLayout->addWidget(monumentRadioButton);

        layout->addWidget(new QLabel());
        auto *validateButton = new QPushButton("Valider");
        layout->addWidget(validateButton);
        // Connection entre boutons et slots
        QObject::connect(validateButton, &QPushButton::clicked, [this, window, batimentRadioButton, monumentRadioButton]() {
            window->accept();
            // Acheter un batiment
            if (batimentRadioButton->isChecked()){
                if (!acheter_bat()) {
                    return false;
                }
            }
            else if (monumentRadioButton->isChecked()){
            // Acheter un monument
                if (!acheter_monu()) {
                    return false;
                }
            }
            // Acheter rien
            else {
                return false;
            }
        });
        // Execution de la boite de dialogue et attente d'une réponse
        window->setLayout(layout);
        window->exec();

    } else {
        choix_ia = rand() % 5;
        if (choix_ia == 0) {
            visit[0] = true;
            transaction_fin = acheter_bat();
        } else {
            visit[1] = true;
            transaction_fin = acheter_monu();
        }

        if (!transaction_fin && !visit[0]) {
            visit[0] = true;
            transaction_fin = acheter_bat();
        }
        else if (!transaction_fin && !visit[1]) {
            visit[1] = true;
            transaction_fin = acheter_monu();
        }

        if (!transaction_fin) {
            return false;
        }
    }
    return true;
}
*/
/*bool Partie::acheter_carte() {
    //fonction qui permet a un joueur donne d'acheter une carte (batiment ou monument)
    int choix = -1;
    int choix_ia = -1;
    bool visit[2] = {false, false};
    bool transaction_fin = false;

    while (!transaction_fin){
        if (!tab_joueurs[joueur_actuel]->get_est_ia()) {
            cout << "Que voulez-vous acheter ? (1 : batiment, 2 : monument, 3 : quitter)" << endl;
            cin >> choix;
            while (choix < 1 || choix > 3) {
                cout << "Veuillez entrer 1, 2 ou 3" << endl;
                cin >> choix;
            }
            if (choix == 3) {
                return false;
            } else if (choix == 1) {
                visit[0] = true;
                transaction_fin = acheter_bat();
            } else if (choix == 2) {
                visit[1] = true;
                transaction_fin = acheter_monu();
            }

            if (!transaction_fin && visit[0]) {
                cout << "Vous n'avez pas assez de ressources pour acheter un batiment" << endl;
                choix = -1;
                while (choix < 0 || choix > 1) {
                    cout << "Voulez-vous acheter un monument ? (0 : non, 1 : oui)" << endl;
                    cin >> choix;
                }
                if (choix == 1) {
                    transaction_fin = acheter_monu();
                }
            }
            else if (!transaction_fin && visit[1]) {
                cout << "Vous n'avez pas assez de ressources pour acheter un monument" << endl;
                choix = -1;
                while (choix < 0 || choix > 1) {
                    cout << "Voulez-vous acheter un batiment ? (0 : non, 1 : oui)" << endl;
                    cin >> choix;
                }
                if (choix == 1) {
                    transaction_fin = acheter_bat();
                }
            }

            if (!transaction_fin) {
                return false;
            }

        } else {
            choix_ia = rand() % 5;
            if (choix_ia == 0) {
                visit[0] = true;
                transaction_fin = acheter_bat();
            } else {
                visit[1] = true;
                transaction_fin = acheter_monu();
            }

            if (!transaction_fin && !visit[0]) {
                visit[0] = true;
                transaction_fin = acheter_bat();
            }
            else if (!transaction_fin && !visit[1]) {
                visit[1] = true;
                transaction_fin = acheter_monu();
            }

            if (!transaction_fin) {
                return false;
            }
        }
    }
    return true;
}

bool Partie::acheter_monu() {
    //fonction qui permet a un joueur donne d'acheter un monument
    Monument* mon_picked;
    Joueur *joueur_act = tab_joueurs[joueur_actuel];
    int choix = -1;
    unsigned int pos = 1;
    vector<Monument*> monuments_dispo;

    if (!tab_joueurs[joueur_actuel]->get_est_ia()) {
        cout << "Quel est le numero du monument que vous voulez acheter?" << endl;
        cout << "0 : Annuler" << endl;
        for (auto mon_act: joueur_act->get_liste_monument()) {
            if (!mon_act.second && mon_act.first->get_prix() <= joueur_act->get_argent()) {
                cout << pos << " : " << mon_act.first->get_nom() << endl;
                pos++;
                monuments_dispo.push_back(mon_act.first);
            }
        }

        if (monuments_dispo.empty()) {
            cout << "Vous ne pouvez pas acheter de monument" << endl;
            return false;
        }

        while (choix < 0 || choix > monuments_dispo.size()) {
            cout << "Votre choix : " << endl;
            cin >> choix;
        }

        if (choix == 0)
            return false;

        mon_picked = monuments_dispo[choix - 1];

        joueur_act->activer_monument(mon_picked);
        joueur_act->set_argent(joueur_act->get_argent() - mon_picked->get_prix());
    } else {
        for (auto mon_act: joueur_act->get_liste_monument()) {
            if (!mon_act.second && mon_act.first->get_prix() <= joueur_act->get_argent()) {
                monuments_dispo.push_back(mon_act.first);
            }
        }

        if (monuments_dispo.empty()) {
            return false;
        }

        mon_picked = monuments_dispo[rand() % monuments_dispo.size()];

        joueur_act->activer_monument(mon_picked);
        joueur_act->set_argent(joueur_act->get_argent() - mon_picked->get_prix());
    }

    cout << "\n\nLe joueur \"" << tab_joueurs[joueur_actuel]->get_nom() << "\" a active le monument " << mon_picked->get_nom() << "\n\n";

    return true;
}

bool Partie::acheter_bat() {
    //fonction qui permet a un joueur donne d'acheter un batiment
    Batiment* bat_picked;
    Joueur *joueur_act = tab_joueurs[joueur_actuel];
    int choix = -1;
    vector<Batiment*> bat_shop = shop->get_contenu_v();

    if (!tab_joueurs[joueur_actuel]->get_est_ia()) {
        cout << "Quel est le numero du batiment que vous voulez acheter?" << endl;
        cout << "0 : Annuler" << endl;
        shop->affiche_shop();

        while (choix < 0 || choix > bat_shop.size()) {
            cout << "Votre choix : " << endl;
            cin >> choix;
        }

        if (choix == 0)
            return false;

        bat_picked = bat_shop[choix - 1];
        if (bat_picked->get_prix() > joueur_act->get_argent()) {
            cout << "Vous n'avez pas assez d'argent pour acheter ce batiment" << endl;
            return false;
        }

    } else {
        strat_IA strat = tab_joueurs[joueur_actuel]->get_strategie();
        vector<Batiment*> bat_shop_couleur;
        vector<Batiment*> bat_shop_prix_ok;
        for (auto bat_act: bat_shop) {
            if (bat_act->get_prix() <= joueur_act->get_argent()) {
                bat_shop_prix_ok.push_back(bat_act);
            }
        }

        if (strat == agressive) {
            for (auto bat_act: bat_shop) {
                if (bat_act->get_couleur() == Rouge && bat_act->get_prix() <= joueur_act->get_argent()) {
                    bat_shop_couleur.push_back(bat_act);
                }
            }
        }
        else if (strat == defensif) {
            for (auto bat_act: bat_shop) {
                if (bat_act->get_couleur() == Bleu && bat_act->get_prix() <= joueur_act->get_argent()) {
                    bat_shop_couleur.push_back(bat_act);
                }
            }
        }

        if (bat_shop_couleur.empty() && bat_shop_prix_ok.empty()) {
            return false;
        }
        else if (bat_shop_couleur.empty()) {
            bat_picked = bat_shop_prix_ok[rand() % bat_shop_prix_ok.size()];
        }
        else {
            bat_picked = bat_shop_couleur[rand() % bat_shop_couleur.size()];
        }
    }

    joueur_act->ajouter_batiment(bat_picked);

    try {
        shop->acheter_batiment(bat_picked);
    }
    catch(exception const& e){
        cerr << "ERREUR : " << e.what() << endl;
    }

    joueur_act->set_argent(joueur_act->get_argent() - bat_picked->get_prix());
    if (bat_picked->get_nom() == "BanqueDeMiniville") {
        joueur_act->set_argent(joueur_act->get_argent() + 5);
    }

    cout << "\nLe joueur \"" << tab_joueurs[joueur_actuel]->get_nom() << "\" a achete la carte " << bat_picked->get_nom() << "\n\n";

    return true;
}*/


bool Partie::acheter_carte(VueCarte *vue_carte) {
    ///Fonction qui permet a un joueur d'acheter une carte (batiment ou monument)
    int choix = -1;
    int choix_ia = -1;
    bool visit[2] = {false, false};
    bool transaction_fin = false;


    // Si le joueur est humain
    if (!tab_joueurs[joueur_actuel]->get_est_ia()) {

        if(vue_carte->getCarte()->get_type() != "Monument"){
            return acheter_bat(vue_carte);
        }
        else{
            return acheter_monu(vue_carte);
        }

    } else {
        choix_ia = rand() % 5;
        if (choix_ia == 0) {
            visit[0] = true;
            transaction_fin = acheter_bat(nullptr);
        } else {
            visit[1] = true;
            transaction_fin = acheter_monu(nullptr);
        }

        if (!transaction_fin && !visit[0]) {
            visit[0] = true;
            transaction_fin = acheter_bat(nullptr);
        }
        else if (!transaction_fin && !visit[1]) {
            visit[1] = true;
            transaction_fin = acheter_monu(nullptr);
        }

        if (!transaction_fin) {
            return false;
        }
    }
    return true;
}

bool Partie::acheter_monu(VueCarte* vue_carte) {
    //fonction qui permet a un joueur donne d'acheter un monument
    Monument* mon_picked;
    Joueur *joueur_act = tab_joueurs[joueur_actuel];
    int choix = -1;
    unsigned int pos = 1;
    vector<Monument*> monuments_dispo;

    if (!tab_joueurs[joueur_actuel]->get_est_ia()) {/*
        cout << "Quel est le numero du monument que vous voulez acheter?" << endl;
        cout << "0 : Annuler" << endl;
        // Ajout des monuments disponibles à la liste
        for (auto mon_act: joueur_act->get_liste_monument()) {
            if (!mon_act.second && mon_act.first->get_prix() <= joueur_act->get_argent()) {
                cout << pos << " : " << mon_act.first->get_nom() << endl;
                pos++;
                monuments_dispo.push_back(mon_act.first);
            }
        }
        // Si liste vide, on renvoie false
        if (monuments_dispo.empty()) {
            return false;
        }
        // Fenetre de dialogue pour l'achat
        QDialog* window = new QDialog();
        vector<VueCarte*> vue_monuments;
        QGridLayout* layout_monuments = new QGridLayout;
        int i = 0;
        for (auto& mon : monuments_dispo) {
            // Affichage du monument
            Monument* adresse_mon = mon;
            vue_monuments.push_back(new VueCarte(*mon, true, window));
            layout_monuments->addWidget(vue_monuments[i], i / 4, i % 4);
            QObject::connect(vue_monuments[i], &QPushButton::clicked, [window, adresse_mon, &mon_picked]() {
                window->accept();
                mon_picked = adresse_mon;
            });
            i++;
        }
        window->setLayout(layout_monuments);
        // Affichage de la fenêtre
        window->exec();
        // Activation du monument et update
        joueur_act->activer_monument(mon_picked);
        joueur_act->set_argent(joueur_act->get_argent() - mon_picked->get_prix());*/

        for (auto mon_act: joueur_act->get_liste_monument()) {
            if (!mon_act.second && mon_act.first->get_nom() == vue_carte->getCarte()->get_nom()) {
                mon_picked = mon_act.first;
            }
        }

        if (mon_picked == nullptr || mon_picked->get_prix() > joueur_act->get_argent()) {
            return false;
        }

        joueur_act->activer_monument(mon_picked);
        joueur_act->set_argent(joueur_act->get_argent() - mon_picked->get_prix());

    } else {
        for (auto mon_act: joueur_act->get_liste_monument()) {
            if (!mon_act.second && mon_act.first->get_prix() <= joueur_act->get_argent()) {
                monuments_dispo.push_back(mon_act.first);
            }
        }

        mon_picked = monuments_dispo[rand() % monuments_dispo.size()];

        joueur_act->activer_monument(mon_picked);
        joueur_act->set_argent(joueur_act->get_argent() - mon_picked->get_prix());
    }

    cout << "\n\nLe joueur \"" << tab_joueurs[joueur_actuel]->get_nom() << "\" a active le monument " << mon_picked->get_nom() << "\n\n";

    return true;
}

bool Partie::acheter_bat(VueCarte* vue_carte) {
    //fonction qui permet a un joueur donne d'acheter un batiment
    Batiment* bat_picked;
    Joueur *joueur_act = tab_joueurs[joueur_actuel];
    int choix = -1;
    vector<Batiment*> bat_shop = shop->get_contenu_v();
    // Si le joueur est humain
    if (!tab_joueurs[joueur_actuel]->get_est_ia()) {
        // Fenetre de dialogue pour l'achat

        /*
        QDialog* window = new QDialog();
        vector<VueCarte*> vue_shop;
        QGridLayout* layout_shop = new QGridLayout;
        int i = 0;
        for (auto& bat : bat_shop) {
            // Affichage du monument
            Batiment* adresse_bat = bat;
            vue_shop.push_back(new VueCarte(*bat, true, window));
            layout_shop->addWidget(vue_shop[i], i / 4, i % 4);
            QObject::connect(vue_shop[i], &QPushButton::clicked, [window, adresse_bat, &bat_picked]() {
                window->accept();
                bat_picked = adresse_bat;
            });
            i++;
        }
        window->setLayout(layout_shop);
        // Affichage de la fenêtre de dialogue
        window->exec();
*/
        for(auto& bat : bat_shop){
            if(bat->get_nom() == vue_carte->getCarte()->get_nom()){
                bat_picked = bat;
            }
        }

        //bat_picked = bat_shop[choix - 1];
        if (bat_picked->get_prix() > joueur_act->get_argent()) {
            QWidget* pop_up = new QWidget();
            pop_up->setWindowTitle("Erreur");
            QLabel* label = new QLabel("Vous n'avez pas assez d'argent pour acheter ce batiment", pop_up);
            QPushButton* ok = new QPushButton("OK", pop_up);
            QObject::connect(ok, &QPushButton::clicked, pop_up, &QWidget::close);

            return false;
        }

    } else {
        strat_IA strat = tab_joueurs[joueur_actuel]->get_strategie();
        vector<Batiment*> bat_shop_couleur;
        vector<Batiment*> bat_shop_prix_ok;
        for (auto bat_act: bat_shop) {
            if (bat_act->get_prix() <= joueur_act->get_argent()) {
                bat_shop_prix_ok.push_back(bat_act);
            }
        }

        if (strat == agressive) {
            for (auto bat_act: bat_shop) {
                if (bat_act->get_couleur() == Rouge && bat_act->get_prix() <= joueur_act->get_argent()) {
                    bat_shop_couleur.push_back(bat_act);
                }
            }
        }
        else if (strat == defensif) {
            for (auto bat_act: bat_shop) {
                if (bat_act->get_couleur() == Bleu && bat_act->get_prix() <= joueur_act->get_argent()) {
                    bat_shop_couleur.push_back(bat_act);
                }
            }
        }

        if (bat_shop_couleur.empty() && bat_shop_prix_ok.empty()) {
            return false;
        }
        else if (bat_shop_couleur.empty()) {
            bat_picked = bat_shop_prix_ok[rand() % bat_shop_prix_ok.size()];
        }
        else {
            bat_picked = bat_shop_couleur[rand() % bat_shop_couleur.size()];
        }
    }

    joueur_act->ajouter_batiment(bat_picked);

    try {
        shop->acheter_batiment(bat_picked);
    }
    catch(exception const& e){
        cerr << "ERREUR : " << e.what() << endl;
    }

    joueur_act->set_argent(joueur_act->get_argent() - bat_picked->get_prix());
    if (bat_picked->get_nom() == "BanqueDeMiniville") {
        joueur_act->set_argent(joueur_act->get_argent() + 5);
    }

    cout << "\nLe joueur \"" << tab_joueurs[joueur_actuel]->get_nom() << "\" a achete la carte " << bat_picked->get_nom() << "\n\n";

    return true;
}


vector<Batiment*> Partie::map_to_vector(const map<Batiment*, unsigned int>& map_batiments){
    /// Retourne un vecteur avec l'adresse des batiments
    vector<Batiment*> vector_batiments;

    for (auto batiment : map_batiments){
        for(unsigned int i = 0; i < batiment.second; i++){
            vector_batiments.push_back(batiment.first);
        }
    }

    // Melange du vecteur
    // Obtention d'un nombre aleatoire (seed)
    random_device rd;
    mt19937 g(rd());

    // Melange du vecteur avec le seed
    shuffle(vector_batiments.begin(), vector_batiments.end(), g);

    return vector_batiments;
}

bool Partie::est_gagnant(unsigned int j) const {
    ///Fonction pour verifier si un joueur a gagne
    Joueur * joueur = tab_joueurs[j];
    return joueur->get_monument_jouables().size() >= nb_monuments_win;
}

bool Partie::transfert_argent(unsigned int indice_joueur1, unsigned int indice_joueur2, unsigned int somme){
    //methode qui permet d'echanger une somme d'argent entre deux joueurs
    // Transfert de l'argent du joueur 1 au joueur 2

    Joueur *joueur1 = tab_joueurs[indice_joueur1];
    Joueur *joueur2 = tab_joueurs[indice_joueur2];
    if(somme == 0){
        return false;
    }

    if(joueur1->get_argent() < somme){
        unsigned int argent_joueur1 = joueur1->get_argent();
        joueur1->set_argent(0);
        joueur2->set_argent(joueur2->get_argent() + argent_joueur1);
    }
    else if(joueur1->get_argent() >= somme){
        joueur1->set_argent(joueur1->get_argent() - somme);
        joueur2->set_argent(joueur2->get_argent() + somme);
    }
    return true;
}

void Partie::jouer_partie() {
    /// Fonction pour jouer une partie
    // Création de la vue
    QWidget *fenetre = new QWidget;
    vue_partie = new VuePartie(fenetre);
    vue_partie->show();

    jouer_tour();
}

void Partie::jouer_tour() {
    /// ****************************************************************************************************************
    /// ****************************** ETAPE 1 : Variables + dés *******************************************************
    /// ****************************************************************************************************************
    unsigned int de_casse;
    unsigned int de_1_temp, de_2_temp;
    bool centre_c_act = false;
    bool centre_c_possesseur = false;
    vector < Monument * > monuments_joueurs = tab_joueurs[joueur_actuel]->get_monument_jouables();

    /// Variable de tour
    moment_achat = false;
    rejouer = false;

    /// On update toutes la vue
    vue_partie->update_vue_partie();
    cout << "Tour du joueur " << tab_joueurs[joueur_actuel]->get_nom() << endl;

    /// Lancer des des
    de_1 = Partie::lancer_de();
    //de_1 = 4; // DE POUR TESTER SES EFFETS ////!!!!\\\\\
    de_1_temp = de_1;

    de_2 = 0;
    de_casse = Partie::lancer_de() + Partie::lancer_de() + Partie::lancer_de() + Partie::lancer_de();

    /// ****************************************************************************************************************
    /// ****************************** ETAPE 2 : Effets des monuments **************************************************
    /// ****************************************************************************************************************

    /// Centre commercial
    auto it_cc = find_if(monuments_joueurs.begin(), monuments_joueurs.end(),
                         [](Monument *m) { return m->get_nom() == "CentreCommercial"; });
    if (it_cc != monuments_joueurs.end()) {
        // Si le monument est trouve, on le joue
        try {
            monuments_joueurs[it_cc - monuments_joueurs.begin()]->declencher_effet(joueur_actuel);
        }
        catch (exception const &e) {
            cerr << "ERREUR : " << e.what() << endl;
        }
        centre_c_act = true;
    }

    /// Gare
    auto it_gare = find_if(monuments_joueurs.begin(), monuments_joueurs.end(),
                           [](Monument *m) { return m->get_nom() == "Gare"; });
    if (it_gare != monuments_joueurs.end()) {
        // Si le monument est trouve, on le joue
        try {
            monuments_joueurs[it_gare - monuments_joueurs.begin()]->declencher_effet(joueur_actuel);
        }
        catch (exception const &e) {
            cerr << "ERREUR : " << e.what() << endl;
        }
    }

    //une fois que tout les effets en rapport avec les dés sont joués, on update l'affichage des dés
    vue_partie->update_des();

    /// Tour radio
    auto it_tr = find_if(monuments_joueurs.begin(), monuments_joueurs.end(),
                         [](Monument *m) { return m->get_nom() == "TourRadio"; });
    if (it_tr != monuments_joueurs.end()) {
        // Si le monument est trouve, on le joue
        try {
            monuments_joueurs[it_tr - monuments_joueurs.begin()]->declencher_effet(joueur_actuel);
        }
        catch (exception const &e) {
            cerr << "ERREUR : " << e.what() << endl;
        }
    }


    vue_partie->update_des();

    de_1_temp = de_1;
    de_2_temp = de_2;

    /// Port + Fabrique du père noel
    for (auto mon: monuments_joueurs) {
        if (mon->get_nom() == "Port" && ((de_1 + de_2) >= 10) ||
            mon->get_nom() == "FabriqueDuPereNoel" && de_casse == 16) {
            try {
                mon->declencher_effet(joueur_actuel);
            }
            catch (exception const &e) {
                cerr << "ERREUR : " << e.what() << endl;
            }
        }
    }

    vue_partie->update_des();

    /// ****************************************************************************************************************
    /// ****************************** ETAPE 3 : Effets des batiments **************************************************
    /// ****************************************************************************************************************


    /// Rouge
    unsigned int j_act_paiement = (joueur_actuel + tab_joueurs.size() - 1) % tab_joueurs.size();

    while (j_act_paiement != joueur_actuel) {
        // Regarde si le joueur possede un centre commercial
        vector < Monument * > monuments_j_act = tab_joueurs[j_act_paiement]->get_monument_jouables();
        for (auto mon: monuments_j_act) {
            if (mon->get_nom() == "CentreCommercial") {
                centre_c_possesseur = true;
            }
        }

        for (auto it: tab_joueurs[j_act_paiement]->get_liste_batiment(Rouge)) {
            if (find(it.first->get_num_activation().begin(), it.first->get_num_activation().end(), de_1 + de_2) !=
                it.first->get_num_activation().end()) {
                if (it.first->get_type() == "restaurant" && centre_c_possesseur) {
                    for (unsigned int effectif = 0; effectif < it.second; effectif++) {
                        try {
                            it.first->declencher_effet(j_act_paiement, 1);
                        }
                        catch (exception const &e) {
                            cerr << "ERREUR : " << e.what() << endl;
                        }
                    }
                } else {
                    for (unsigned int effectif = 0; effectif < it.second; effectif++) {
                        try {
                            it.first->declencher_effet(j_act_paiement);
                        }
                        catch (exception const &e) {
                            cerr << "ERREUR : " << e.what() << endl;
                        }
                    }
                }
            }
        }

        j_act_paiement = (j_act_paiement + tab_joueurs.size() - 1) % tab_joueurs.size();
    }


    /// Violet
    for (auto it: tab_joueurs[joueur_actuel]->get_liste_batiment(Violet)) {
        if (find(it.first->get_num_activation().begin(), it.first->get_num_activation().end(), de_1 + de_2) !=
            it.first->get_num_activation().end()) {
            for (unsigned int effectif = 0; effectif < it.second; effectif++) {
                try {
                    it.first->declencher_effet(joueur_actuel);
                }
                catch (exception const &e) {
                    cerr << "ERREUR : " << e.what() << endl;
                }
            }
        }
    }

    /// Bleu
    for (int i = 0; i < tab_joueurs.size(); i++) {
        for (auto it: tab_joueurs[i]->get_liste_batiment(Bleu)) {
            if (find(it.first->get_num_activation().begin(), it.first->get_num_activation().end(), de_1 + de_2) !=
                it.first->get_num_activation().end()) {
                for (unsigned int effectif = 0; effectif < it.second; effectif++) {
                    try {
                        it.first->declencher_effet(i);
                    }
                    catch (exception const &e) {
                        cerr << "ERREUR : " << e.what() << endl;
                    }
                }
            }
        }
    }

    /// Vert
    for (auto it: tab_joueurs[joueur_actuel]->get_liste_batiment(Vert)) {
        if (find(it.first->get_num_activation().begin(), it.first->get_num_activation().end(), de_1 + de_2) !=
            it.first->get_num_activation().end()) {
            if (it.first->get_type() == "commerce" && centre_c_act) {
                for (unsigned int effectif = 0; effectif < it.second; effectif++) {
                    try {
                        it.first->declencher_effet(joueur_actuel, 1);
                    }
                    catch (exception const &e) {
                        cerr << "ERREUR : " << e.what() << endl;
                    }
                }
            } else {
                for (unsigned int effectif = 0; effectif < it.second; effectif++) {
                    try {
                        it.first->declencher_effet(joueur_actuel);
                    }
                    catch (exception const &e) {
                        cerr << "ERREUR : " << e.what() << endl;
                    }
                }
            }
        }
    }

    /// ****************************************************************************************************************
    /// ****************************** ETAPE 4 : HotelDeVille + Achat **************************************************
    /// ****************************************************************************************************************

    /// Hotel de ville
    auto it_hdv = find_if(monuments_joueurs.begin(), monuments_joueurs.end(),
                          [](Monument *m) { return m->get_nom() == "HotelDeVille"; });
    if (it_hdv != monuments_joueurs.end()) {
        // Si le monument est trouve, on le joue
        try {
            monuments_joueurs[it_hdv - monuments_joueurs.begin()]->declencher_effet(joueur_actuel);
        }
        catch (exception const &e) {
            cerr << "ERREUR : " << e.what() << endl;
        }
    }

    /// Achat
    moment_achat = true;
    vue_partie->set_bouton_rien_faire(true);
    vue_partie->update_vue_joueur();
}

void Partie::suite_tour(bool achat_ok){
    vector < Monument * > monuments_joueurs = tab_joueurs[joueur_actuel]->get_monument_jouables();

    /// ****************************************************************************************************************
    /// ****************************** ETAPE 1 : Affichage achat + effet ***********************************************
    /// ****************************************************************************************************************

    if (!achat_ok) {
        vue_partie->get_vue_infos()->add_info("Vous n'avez rien achete");

        /// Banque
        if (tab_joueurs[joueur_actuel]->get_argent() < 2)
            tab_joueurs[joueur_actuel]->set_argent(2);

        /// Aeroport
        auto it_earo = find_if(monuments_joueurs.begin(), monuments_joueurs.end(), [](Monument* m){return m->get_nom() == "Aeroport";});
        if (it_earo != monuments_joueurs.end()){
            // Si le monument est trouve, on le joue
            try{
                monuments_joueurs[it_earo - monuments_joueurs.begin()]->declencher_effet(joueur_actuel);
            }
            catch(exception const& e){
                cerr << "ERREUR : " << e.what() << endl;
            }
        }

    }

    /// ****************************************************************************************************************
    /// ****************************** ETAPE 2 : Ouverture batiment ****************************************************
    /// ****************************************************************************************************************

    /// Ouverture
    for (auto bat : tab_joueurs[joueur_actuel]->get_liste_batiment_fermes()) {
        if (find(bat->get_num_activation().begin(), bat->get_num_activation().end(), de_1 + de_2) != bat->get_num_activation().end()) {
            try {
                tab_joueurs[joueur_actuel]->ouvrir_batiment(bat);
            }
            catch(exception const& e){
                cerr << "ERREUR : " << e.what() << endl;
            }
        }
    }

    /// ParcAtraction
    auto it_parc = find_if(monuments_joueurs.begin(), monuments_joueurs.end(), [](Monument* m){return m->get_nom() == "ParcAttraction";});
    if (it_parc != monuments_joueurs.end() && de_1 == de_2){
        // Si le monument est trouve, on le joue
        try{
            monuments_joueurs[it_parc - monuments_joueurs.begin()]->declencher_effet(joueur_actuel);
        }
        catch(exception const& e){
            cerr << "ERREUR : " << e.what() << endl;
        }
    }

    /// Complete le shop
    while (!pioche->est_vide() && shop->get_nb_tas_reel() < shop->get_nb_tas_max()) {
        try {
            shop->completer_shop(pioche->get_carte());
        }
        catch (exception const& e) {
            cerr << "ERREUR : " << e.what() << endl;
        }
    }

    /// Update la vue
    vue_partie->update_vue_partie();
    QTime endTime = QTime::currentTime().addSecs(5);

    // Figer l'affichage jusqu'à ce que l'heure actuelle soit supérieure à l'heure de fin
    while (QTime::currentTime() < endTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }

    /// Vérifie si la partie est finie
    if (est_gagnant(joueur_actuel)) {
        /// Fin de la partie
        QMessageBox::information(vue_partie, "Fin de la partie", "Le joueur " + QString::fromStdString(tab_joueurs[joueur_actuel]->get_nom()) + " a gagne !");
        vue_partie->close();
    } else {
        /// Fin du tour
        if (!rejouer) {
            joueur_actuel = (joueur_actuel + 1) % tab_joueurs.size();
        }
        jouer_tour();
    }
}

unsigned int Partie::selectionner_joueur(const vector<Joueur*>& tab_joueurs, unsigned int joueur_actuel){
    unsigned int count = 0;
    unsigned int selection = 0;

    //cas où la decision doit se faire par une ia
    if(tab_joueurs[joueur_actuel]->get_est_ia()){
        selection = rand() % tab_joueurs.size();
        if(selection == joueur_actuel) selection = (selection + 1)%tab_joueurs.size();
    }
    //cas où c'est un joueur reel qui prend la decision
    else{
        //Affichage de tous les joueus de tab_joueurs
        cout<<"Quel joueur voulez vous choisir parmis la liste suivante :" << endl;
        for(Joueur* curseur:tab_joueurs){
            cout<<count<<" : "<<curseur->get_nom()<<endl;
            count++;
        }

        //Scan de tab_joueurs a la recherche du nom entre
        cout<<"Indice du joueur a selectionner :"<<endl;
        cin >> selection;

        //cas où erreur (nom entre pas dans la liste ou nom entre = joueur actuel)
        if(selection > tab_joueurs.size()) throw gameException("L'indice entre n'est pas valide");
        if(selection == joueur_actuel) throw gameException("On ne peut pas selectionner le joueur actuel");
    }

    cout<<"joueur selectionne : "<<tab_joueurs[selection]->get_nom();
    return selection;
}

unsigned int Partie::lancer_de() {
    srand(time(nullptr));
    return (rand() % 6) + 1;
}

void Partie::acheter_carte_event(VueCarte* vc) {
    bool est_ok = Partie::get_instance()->acheter_carte(vc);
}