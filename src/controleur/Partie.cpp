#include "Partie.h"

Partie::Partie(vector<EditionDeJeu *> editions) : nb_monuments_win(0), joueur_actuel(0) {
    ///Constructeur de Partie

    //Initialisation des attributs
    unsigned int max_joueurs = 0;

    vector<Batiment*> starter_bat;
    // Détermination du nombre de monuments pour gagner et des batiments de départ
    for(auto edition : editions){
        if(edition->get_nb_joueurs_max() > max_joueurs){
            max_joueurs = edition->get_nb_joueurs_max();
        }
        if(edition->get_nb_monuments_win() > nb_monuments_win){
            nb_monuments_win = edition->get_nb_monuments_win();
        }
        // Ajout des monuments et des batiments starter
        list_monuments.insert(list_monuments.end(), edition->get_monument().begin(), edition->get_monument().end());
        starter_bat.insert(starter_bat.end(), edition->get_starter().begin(), edition->get_starter().end());
        // Ajout des batiments à acheter au fil de la partie
        for (auto batiment : edition->get_batiment()){
            // On vérifie que c'est pas un batiment starter
            if (batiment.first->get_nom() != "Boulangerie" && batiment.first->get_nom() != "Boulangerie"){
                bool est_present = false;
                // Si le batiment n'est pas dans la list_batiments, on l'ajoute
                for (auto bat : list_batiments){
                    // Si le batiment est déjà dans la liste, on augmente le nombre d'exemplaires
                    if (bat.first->get_nom() == batiment.first->get_nom()){
                        bat.second += batiment.second;
                        est_present = true;
                    }
                }
                // Sinon, on ajoute le batiment à la liste des batiments
                if (!est_present){
                    list_batiments.insert(pair<Batiment* const, unsigned int>(batiment.first->clone(), batiment.second));
                }
            }
        }
    }
    // Ajout des joueurs
    for (unsigned int i = 0; i < max_joueurs; i++) {
        // Si plus de 2 joueurs, l'ajout devient optionnel
        if (i > 2) {
            cout << "Voulez-vous ajouter un joueur ? (0 : non, 1 : oui)" << endl;
            int choix;
            cin >> choix;
            if (choix == 0) {
                break;
            }
        }
        // Info du joueur
        cout << "Nom du joueur " << i + 1 << " : " ;
        string nom;
        cin >> nom;
        cout << "\nLe jouer est-il un humain ? (1 : oui, 0 : non)  :";
        bool humain;
        cin >> humain;
        if (humain) {
            tab_joueurs.push_back(new Joueur(nom, list_monuments, starter_bat, 3));
        }
        // Demande de la stratégie IA
        else {
            cout << "\nQuelle est la strategie du joueur ? (1 : aleatoire, 2 : agressive, 3 : defensif) :";
            unsigned int strategie;
            cin >> strategie;
            while (strategie < 1 || strategie > 3) {
                cout << "\nQuelle est la strategie du joueur ? (1 : aleatoire, 2 : agressive, 3 : defensif) :";
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
            }
        }
    }

    pioche = new Pioche(map_to_vector(list_batiments));
    // Demande du format du shop
    cout << "Quel est le format du shop la partie ? (1 : standard, 2 : extended) :" << endl;
    cout <<"1 : standard :" << endl;
    cout << "\tAvec ce format vous pouvez choisir le nombre de tas de cartes que vous voulez." << endl;
    cout << "2 : extended :" << endl;
    cout << "\tAvec ce format toutes les cartes sont dans le shop." << endl;
    cout << "Votre choix : ";
    unsigned int format;
    cin >> format;
    unsigned int nb_tas;

    if (format == 1) {
        cout << "Combien de tas voulez-vous ? (9 < tas < " << list_batiments.size() - 1 << ") :";
        cin >> nb_tas;
        while (nb_tas < 9 || nb_tas > list_batiments.size() - 1) {
            cout << "Combien de tas voulez-vous ? (9 < tas < " << list_batiments.size() - 1 << ") :";
            cin >> nb_tas;
        }
    }
    else
        nb_tas = list_batiments.size();
    // Construction du Shop
    shop = new Shop(nb_tas);

    while (!pioche->est_vide() && shop->get_nb_tas_reel() < shop->get_nb_tas_max()){
        shop->completer_shop(pioche->getCarte());
    }

    cout << "Construction de la partie terminée" << endl;
}

void Partie::ajout_batiment(Batiment *batiment) {
    ///Ajoute un batiment dans la liste des batiments
    for (auto bat: list_batiments) {
        if (batiment->get_nom() == bat.first->get_nom()) {
            bat.second++;
        }
        else {
            list_batiments.insert(pair<Batiment*, unsigned int>(batiment->clone(), 1));
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
    return vector_batiments;
}

void Partie::jouer_partie() {
    ///Fonction principale pour jouer une partie

}


void Partie::jouer_tour() {
    ///Fonction pour jouer un tour
    Joueur *j_actuel = tab_joueurs[joueur_actuel];
    if (est_gagnant(j_actuel)) {
        cout << "Le joueur " << j_actuel->get_nom() << " a gagné la partie !" << endl;
        return;
    }

    /// Jet de dé pour le joueur
    vector<Monument*> monuments_jouables = j_actuel->get_monument_jouables();


    unsigned int res_de1 = rand() % 6 + 1;
    unsigned int res_de2 = 0;
    unsigned int res_tot = res_de1;

    cout << "Le joueur " << j_actuel->get_nom() << " a fait " << res_de1 << endl;



    /// Activation des bâtiments


    /// Phase d'achat
}

bool Partie::est_gagnant(Joueur *joueur) {
    ///Fonction pour vérifier si un joueur a gagné
    return joueur->get_monument_jouables().size() >= nb_monuments_win;
}