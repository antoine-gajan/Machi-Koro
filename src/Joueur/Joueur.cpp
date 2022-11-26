#include "Joueur.h"
#include <map>

using namespace std;

Joueur::Joueur(string name, Monument *list_mon[], Batiment *list_bat[], unsigned int arg_depart) {
    /// Création d'un joueur non IA

    if (name.empty()) {
        throw invalid_argument("Le nom du joueur ne peut pas être vide");
    }
    nom = name;

    if (list_mon == nullptr || list_bat == nullptr) {
        throw invalid_argument("Les listes de cartes ne peuvent pas être nulles");
    }

    // Ajout des batiments initiaux
    size_t i = 0;
    while (list_bat[i] != nullptr) {
        ajouter_batiment(list_bat[i]);
        i++;
    }

    // Ajout des monuments initiaux
    Monument * mon = list_mon[0];
    i = 0;
    while (mon != nullptr) {
        liste_monument.insert(pair<Monument*, bool>(mon, false));
        i++;
        mon = list_mon[i];
    }

    argent = arg_depart;
    est_ia = false;
}

Joueur::Joueur(string name, Monument *list_mon[], Batiment *list_bat[], unsigned int arg_depart, strat_IA stratIa) {
    /// Création d'un joueur IA

    if (name.empty()) {
        throw invalid_argument("Le nom du joueur ne peut pas être vide");
    }
    nom = name;

    if (list_mon == nullptr || list_bat == nullptr) {
        throw invalid_argument("Les listes de cartes ne peuvent pas être nulles");
    }

    // Ajout des batiments initiaux
    size_t i = 0;
    while (list_bat[i] != nullptr) {
        ajouter_batiment(list_bat[i]);
        i++;
    }

    // Ajout des monuments initiaux
    Monument * mon = list_mon[0];
    i = 0;
    while (mon != nullptr) {
        liste_monument.insert(pair<Monument*, bool>(mon, false));
        i++;
        mon = list_mon[i];
    }

    argent = arg_depart;
    est_ia = true;
    strategie = stratIa;
}

Joueur::~Joueur() {
    /// Destructeur de Joueur

    // Destruction des monuments
    liste_monument.clear();
    // Destruction des batiments
    for (auto it = liste_batiment.begin(); it != liste_batiment.end(); ++it) {
        it->second.clear();
    }
    liste_batiment.clear();
}

unsigned int * Joueur::get_repartition_argent() const {
    /// Répartition de l'argent en fonction des types de pièces
    unsigned int *repartition = new unsigned int [3];
    repartition[0] = argent/10;
    repartition[1] = (argent%10)/5;
    repartition[2] = (argent%10)%5;

    return repartition;
}

void Joueur::activer_monument(Monument *mon) {
    if (mon == nullptr) {
        throw invalid_argument("Le monument ne peut pas être nul");
    }

    // On active le monument
    auto it = liste_monument.find(mon);
    if (it != liste_monument.end()) {
        it->second = true;
    }
}

void Joueur::ajouter_batiment(Batiment *bat) {
    if (bat == nullptr) {
        throw invalid_argument("Le batiment ne peut pas être nul");
    }

    // On ajoute le batiment
    couleur_bat coul_bat = bat->get_couleur();
    string couleur;

    if (coul_bat == Bleu)
        couleur = "Bleu";
    else if (coul_bat == Rouge)
        couleur = "Rouge";
    else if (coul_bat == Vert)
        couleur = "Vert";
    else if (coul_bat == Violet)
        couleur = "Violet";

    auto bat_couleur = liste_batiment.at(couleur);
    if (couleur == "Violet") {
        // On vérifie que le batiment n'est pas déjà présent
        auto it = bat_couleur.find(bat);
        if (it == bat_couleur.end()) {
            // On ajoute le batiment
            liste_batiment.at(couleur).insert(pair<Batiment*, unsigned int>(bat, 1));
        }
        // Sinon on ne fait rien
    }
    else {
        // On vérifie si le batiment est déjà présent
        auto it = bat_couleur.find(bat);
        if (it == bat_couleur.end()) {
            // On ajoute le batiment
            liste_batiment.at(couleur).insert(pair<Batiment*, unsigned int>(bat, 1));
        }
        else {
            // On incrémente le nombre de batiment
            it->second++;
        }
    }
}

void Joueur::retirer_batiment(Batiment *bat) {
    // on vérifie si le joueur possède le batiment et si oui on retire 1 à sa quantité
    // si la quantité est nulle on retire le batiment de la liste
}

void Joueur::acheter_carte(Carte *carte) {
    if (carte == nullptr) {
        throw invalid_argument("La carte ne peut pas être nulle");
    }

    // On vérifie que le joueur a assez d'argent
    if (argent < carte->get_prix()) {
        return;
    }

    // On retire l'argent
    argent -= carte->get_prix();

    // On ajoute la carte
    if (carte->get_type() == "Batiment") {
        ajouter_batiment((Batiment*) carte);
    } else if (carte->get_type() == "Monument") {
        activer_monument((Monument*) carte);
    }
}

vector<Monument*> Joueur::get_monument_jouables() const {
    vector<Monument*> liste;
    for (auto it = liste_monument.begin(); it != liste_monument.end(); it++) {
        if (it->second)
            liste.push_back(it->first);
    }
    return liste;
}