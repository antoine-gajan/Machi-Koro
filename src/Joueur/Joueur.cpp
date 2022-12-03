#include "Joueur.h"
#include <map>

using namespace std;

Joueur::Joueur(const string& name, Monument *list_mon[], Batiment *list_bat[], unsigned int arg_depart, strat_IA stratIa)
            : argent(arg_depart), nom(name), strategie(stratIa){
    /// Création d'un joueur IA ou non
    if (stratIa != none) {
        // Si c'est une IA, on met est_ia à true
        est_ia = true;
    } else {
        // Sinon, on met est_ia à false
        est_ia = false;
    }

    if (nom.empty()) {
        throw invalid_argument("Le nom du joueur ne peut pas être vide");
    }

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
}

unsigned int * Joueur::get_repartition_argent() const {
    /// Répartition de l'argent en fonction des types de pièces
    unsigned int *repartition = new unsigned int [3];
    // Pièces de 10
    repartition[0] = argent/10;
    // Pièces de 5
    repartition[1] = (argent%10)/5;
    //Pièces de 1
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

void Joueur::desactiver_monument(Monument *mon) {
    if (mon == nullptr) {
        throw invalid_argument("Le monument ne peut pas être nul");
    }

    // On active le monument
    auto it = liste_monument.find(mon);
    if (it != liste_monument.end()) {
        it->second = false;
    }
}

void Joueur::ajouter_batiment(Batiment *bat) {
    if (bat == nullptr) {
        throw invalid_argument("Le batiment ne peut pas être nul");
    }

    /// Ajout du batiment
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
    if (bat == nullptr) {
        throw invalid_argument("Le batiment ne peut pas être nul");
    }

    /// Enlever le batiment
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

    // On vérifie si le batiment est déjà présent
    auto it = bat_couleur.find(bat);
    if (it != bat_couleur.end()) {
        // On décrémente le nombre de batiment
        if (it->second > 1) {
            it->second--;
        }
        else {
            // On retire le batiment
            liste_batiment.at(couleur).erase(it);
        }
    }
    // Sinon on ne fait rien

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

const vector<Monument*> Joueur::get_monument_jouables() const {
    /// Fonction qui retourne la liste des monuments actifs d'un joueur
    vector<Monument*> liste;
    for (auto monument : liste_monument) {
        if (monument.second)
            liste.push_back(monument.first);
    }
    return liste;
}

void Joueur::set_argent(unsigned int arg){
    /// Mise à jour de l'argent du joueur
    argent = arg;
}
void Joueur::set_liste_batiment(const map<string, map<Batiment*, unsigned int>>& liste_bat){
    /// Mise à jour de la liste des batiments du joueur
    liste_batiment = liste_bat;
}