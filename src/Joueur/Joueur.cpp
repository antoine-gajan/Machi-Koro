#include "Joueur.h"

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
    Batiment * bat = list_bat[0];
    size_t i = 0;
    while (bat != nullptr) {
        liste_batiment.insert(pair<unsigned int, Batiment*>(1, bat));
        i++;
        bat = list_bat[i];
    }

    // Ajout des monuments initiaux
    Monument * mon = list_mon[0];
    i = 0;
    while (mon != nullptr) {
        liste_monument.insert(pair<bool, Monument*>(false, mon));
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
    Batiment * bat = list_bat[0];
    size_t i = 0;
    while (bat != nullptr) {
        liste_batiment.insert(pair<Batiment*, unsigned int>(bat, 1));
        i++;
        bat = list_bat[i];
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
    liste_batiment.clear();
    liste_monument.clear();
}

unsigned int * Joueur::get_repartition_argent() const {
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
    auto it = liste_batiment.find(bat);
    if (it != liste_batiment.end())
        it->second++;
    else
        liste_batiment.insert(pair<Batiment*, unsigned int>(bat, 1));
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