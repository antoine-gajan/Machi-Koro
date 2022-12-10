#include "Joueur.h"
#include <map>

using namespace std;

Joueur::Joueur(const string& nom, const vector<Monument *>&list_mon, const vector<Batiment *>&list_bat, unsigned int arg_depart, strat_IA stratIa)
: strategie(stratIa), est_ia(stratIa != none), nom(nom), argent(arg_depart)
{
    /// Constructeur de Joueur
    for (auto mon : list_mon)
        liste_monument[mon] = false;
    for (auto bat : list_bat)
        liste_batiment[bat->get_couleur()][bat] = 1;
}

vector<unsigned int> Joueur::get_repartition_argent() const {
    /// Repartition de l'argent en fonction des types de pieces
    vector<unsigned int> repartition;
    unsigned int temp = argent;

    repartition.push_back(temp/10);
    temp = temp%10;
    repartition.push_back(temp/5);
    temp = temp%5;
    repartition.push_back(temp/1);

    return repartition;
}

Joueur::~Joueur() {
    /// Destructeur de Joueur
    liste_monument.clear();

    // Iteration sur les couleurs de batiments
    for (auto & it : liste_batiment) {
        // Iteration sur les batiments
        it.second.clear();
    }

    liste_batiment.clear();
}

vector<Monument*> Joueur::get_monument_jouables() const {
    /// Retourne la liste des monuments actifs
    vector<Monument*> liste_monument_jouables;

    for (auto it : liste_monument) {
        if (it.second)
            liste_monument_jouables.push_back(it.first);
    }

    return liste_monument_jouables;
}


void Joueur::activer_monument(Monument *mon) {
    /// Activer un monument passé en paramètre
    if (mon == nullptr) {
        throw invalid_argument("Le monument ne peut pas être nul");
    }

    // On active le monument
    auto it = liste_monument.find(mon);
    if (it != liste_monument.end()) {
        it->second = true;
        it->first->activer();
    }
}

void Joueur::desactiver_monument(Monument *mon) {
    /// Désactiver un monument passé en paramètre
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
    /// Ajout du batiment

    if (bat == nullptr) {
        throw invalid_argument("Le batiment ne peut pas être nul");
    }

    // Recuperation de la couleur du batiment
    couleur_bat couleur = bat->get_couleur();

    // On regarde si le joueur possede deja un exemplaire du batiment
    for (auto batiment : liste_batiment[couleur]){
        if (batiment.first == bat){
            // Si l'utilisateur a deja un exemplaire de ce batiment et qu'il est violet : erreur
            if (bat->get_couleur() == Violet){
                cout << "Le joueur" << nom << " possede deja un exemplaire du batiment violet" << bat->get_nom()<<endl;
                return;
            }
            // Sinon, on augmente le nombre d'exemplaires de celui-ci
            else{
                liste_batiment[couleur][batiment.first]++;
                cout << "Ajout du batiment " << bat->get_nom() << " au joueur " << nom << endl;
                cout << "Le joueur " << nom << " possede " << batiment.second << " exemplaires du batiment " << bat->get_nom() << endl;
                return;
            }
        }
    }

    // Si aucun exemplaire du batiment, on l'ajoute
    liste_batiment[couleur].insert(pair<Batiment*, unsigned int> (bat, 1));
    cout << "Ajout du batiment " << bat->get_nom() << " au joueur " << nom << endl;
    cout << "Le joueur " << nom << " possede 1 exemplaire du batiment " << bat->get_nom() << endl;
}


void Joueur::retirer_batiment(Batiment *bat) {
    /// Retire 1 exemplaire du batiment d'un joueur

    if (bat == nullptr) {
        throw invalid_argument("Le batiment ne peut pas être nul");
    }

    // Recuperation de la couleur du batiment
    couleur_bat couleur = bat->get_couleur();

    // On regarde si le joueur possede deja un exemplaire du batiment
    for (auto batiment : liste_batiment[couleur]){
        if (batiment.first == bat){
            // Si un seul exemplaire, on supprime l'element
            if (batiment.second == 1){
                liste_batiment[couleur].erase(batiment.first);
            }
            // Sinon, on decremente le nombre d'exemplaires
            else{
                liste_batiment[couleur][batiment.first]--;
            }
            cout << "Le batiment " << bat->get_nom() << " a ete retire du joueur " << nom << endl;
            return;
        }
    }
    // Sinon, aucun batiment correspondant pour le joueur, on renvoie une erreur
    cout << "Impossible de retirer le batiment. Le joueur " << nom << "ne possede aucun batiment " << bat->get_nom() << endl;
}

void Joueur::set_liste_batiment(map<couleur_bat, map<Batiment*, unsigned int>>& liste_bat){
    /// Mise a jour de la liste des batiments du joueur
    liste_batiment = liste_bat;
}


void Joueur::afficher_cartes() const {
    /// Affiche toutes les cartes du Joueur

    cout << "Cartes du joueur " << endl;

    cout << "Monuments : " << endl;
    for (const auto& monument : liste_monument){
        if (monument.second){
            cout << "[X]";
        }
        else{
            cout << "[ ]";
        }

        cout << " : " << monument.first->get_nom() << endl;
    }

    cout << "Batiments : " << endl;
    for (const auto& couleur : liste_batiment){
        for (const auto& batiment : couleur.second){
            cout << batiment.second << " : " << batiment.first->get_nom() << endl;
        }
    }
}

void Joueur::afficher_joueur() const {
    /// Affiche les informations d'un joueur

    cout << "\n********************" << endl;
    cout << "Joueur : \"" << nom ;
    if (est_ia){
        cout << "\" est une IA" << endl;
    }
    else{
        cout << "\" est un Humain" << endl;
    }
    cout << "Argent : " << argent << endl;
    afficher_cartes();
    cout << "********************\n" << endl;
}