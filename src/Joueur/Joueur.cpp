#include "Joueur.h"
#include <map>

using namespace std;

Joueur::Joueur(const string& nom, const vector<Monument *>&list_mon, const vector<Batiment *>&list_bat, unsigned int arg_depart, strat_IA stratIa)
: strategie(stratIa), est_ia(stratIa != none), nom(nom), argent(arg_depart)
{
    for (auto mon : list_mon)
        liste_monument[mon] = false;
    for (auto bat : list_bat)
        liste_batiment[bat->get_couleur()][bat] = 1;
}

vector<unsigned int> Joueur::get_repartition_argent() const {
    /// Répartition de l'argent en fonction des types de pièces
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
    liste_monument.clear();

    // Itération sur les couleurs de batiments
    for (auto it = liste_batiment.begin(); it != liste_batiment.end(); ++it) {
        // Itération sur les batiments
        it->second.clear();
    }
    liste_batiment.clear();
}

vector<Monument*> Joueur::get_monument_jouables() const {
    vector<Monument*> liste_monument_jouables;
    for (auto it : liste_monument) {
        if (!it.second)
            liste_monument_jouables.push_back(it.first);
    }
    return liste_monument_jouables;
}

void Joueur::set_argent(unsigned int arg){
    /// Mise à jour de l'argent du joueur
    argent = arg;
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
    cout << "Ajout du batiment " << bat->get_nom() << " au joueur " << nom << endl;

    if (bat == nullptr) {
        throw invalid_argument("Le batiment ne peut pas être nul");
    }

    /// Ajout du batiment
    map<Batiment *, unsigned int> bat_couleur_liste = liste_batiment.at(bat->get_couleur());

    if (bat->get_couleur() == Violet) {
        // On vérifie que le batiment n'est pas déjà dans la liste
        if (bat_couleur_liste.find(bat) == bat_couleur_liste.end()) {
            // On ajoute le batiment
            bat_couleur_liste.insert(pair<Batiment *, unsigned int>(bat, 1));
        }
        else{
            cout << "Vous ne pouvez posséder qu'un exemplaire d'un batiment violet" <<endl;
        }
    }
    else {
        // On traite le cas où le batiment est déjà dans la liste
        if (bat_couleur_liste.find(bat) != bat_couleur_liste.end()) {
            // On incrémente le nombre de batiment
            bat_couleur_liste.at(bat)++;
        }
        else {
            // On ajoute le batiment
            bat_couleur_liste.insert(pair<Batiment *, unsigned int>(bat, 1));
        }
    }

    cout << "Ajout du batiment " << bat->get_nom() << " au joueur " << nom << " termine" << endl;
}

/*
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


void Joueur::set_liste_batiment(const map<string, map<Batiment*, unsigned int>>& liste_bat){
    /// Mise à jour de la liste des batiments du joueur
    liste_batiment = liste_bat;
}
 */