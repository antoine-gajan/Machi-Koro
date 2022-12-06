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
    /// Ajout du batiment

    if (bat == nullptr) {
        throw invalid_argument("Le batiment ne peut pas être nul");
    }
    // Récupération de la couleur du batiment
    couleur_bat couleur = bat->get_couleur();
    // On regarde si le joueur possède déjà un exemplaire du batiment
    for (auto batiment : liste_batiment[couleur]){
        if (batiment.first == bat){
            // Si l'utilisateur a déjà un exemplaire de ce batiment et qu'il est violet : erreur
            if (bat->get_couleur() == Violet){
                cout << "Le joueur" << nom << "possede deja un exemplaire du batiment violet" << bat->get_nom()<<endl;
                return;
            }
            // Sinon, on augmente le nombre d'exemplaires possédés
            else{
                liste_batiment[couleur][batiment.first]++;
                cout << "Ajout du batiment " << bat->get_nom() << " au joueur " << nom << endl;
                cout << "Le joueur " << nom << "possede " << batiment.second << " exemplaires du batiment " << bat->get_nom() << endl;
                return;
            }
        }
    }
    // Si aucun exemplaire du batiment, on l'ajoute
    liste_batiment[couleur].insert(pair<Batiment*, unsigned int> (bat, 1));
    cout << "Ajout du batiment " << bat->get_nom() << " au joueur " << nom << endl;
    cout << "Le joueur " << nom << "possede 1 exemplaire du batiment " << bat->get_nom() << endl;
}


void Joueur::retirer_batiment(Batiment *bat) {
    /// Retire 1 exemplaire du batiment d'un joueur
    if (bat == nullptr) {
        throw invalid_argument("Le batiment ne peut pas être nul");
    }

    // Récupération de la couleur du batiment
    couleur_bat couleur = bat->get_couleur();

    // On regarde si le joueur possède déjà un exemplaire du batiment
    for (auto batiment : liste_batiment[couleur]){
        if (batiment.first == bat){
            // Si un seul exemplaire, on supprime l'élément
            if (batiment.second == 1){
                liste_batiment[couleur].erase(batiment.first);
            }
            // Sinon, on décrémente le nombre d'exemplaires
            else{
                batiment.second --;
            }
            cout << "Le batiment " << bat->get_nom() << " a ete retire du joueur " << nom << endl;
            return;
        }
    }
    // Sinon, aucun batiment correspondant pour le joueur, on renvoie une erreur
    cout << "Impossible de retirer le batiment. Le joueur " << nom << "ne possede aucun batiment " << bat->get_nom() << endl;
}


void Joueur::acheter_carte(Carte *carte) {
    /// Permet à un joueur d'acheter une carte (monument ou batiment)
    if (carte == nullptr) {
        throw invalid_argument("La carte ne peut pas être nulle");
    }

    // On vérifie que le joueur a assez d'argent
    if (argent < carte->get_prix()) {
        cout << "Impossible d'acheter cette carte. Le joueur " << nom << "ne possede pas assez d'argent." << endl;
        return;
    }

    // Mise à jour l'argent
    set_argent(argent - carte->get_prix());

    // On ajoute la carte
    if (carte->get_type() == "Batiment") {
        ajouter_batiment(dynamic_cast<Batiment*>(carte));
    } else if (carte->get_type() == "Monument") {
        activer_monument(dynamic_cast<Monument*>(carte));
    }
}

void Joueur::set_liste_batiment(map<couleur_bat, map<Batiment*, unsigned int>>& liste_bat){
    /// Mise à jour de la liste des batiments du joueur
    liste_batiment = liste_bat;
}
