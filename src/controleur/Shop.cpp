#include "Shop.h"

Shop::Shop(unsigned int nb_tas) : nb_tas_max(nb_tas), nb_tas_reel(0), contenu() {
    ///Constructeur de Shop
}

void Shop::completer_shop(Batiment *new_bat) {
    ///Complète le shop en ajoutant des cartes
    if (nb_tas_reel == nb_tas_max) {
        auto it = contenu.find(new_bat);
        if (it != contenu.end()) {
            it->second++;
        } else {
            cout << "Le tas est plein, vous ne pouvez pas ajouter de carte non deja presente." << endl;
        }
    } else {
        auto it = contenu.find(new_bat);
        if (it != contenu.end()) {
            it->second++;
        } else {
            contenu.insert(pair<Batiment*, unsigned int>(new_bat, 1));
            nb_tas_reel++;
        }
    }
}

Shop::~Shop() {
    ///Destructeur de Shop
    contenu.clear();
}

Batiment * Shop::acheter_batiment(Batiment *bat) {
    ///Achète un batiment
    auto it = contenu.find(bat);
    if (it != contenu.end()) {
        if (it->second > 1) {
            it->second--;
            return bat;
        } else {
            contenu.erase(it);
            nb_tas_reel--;
            return bat;
        }
    } else {
        cout << "Il n'y a pas de carte de ce type dans le shop." << endl;
        return nullptr;
    }
}

void Shop::affiche_shop() {
    ///Affiche le shop
    cout << "Shop :" << endl;
    for (auto it = contenu.begin(); it != contenu.end(); it++) {
        cout << it->first->get_nom() << " : " << it->second << endl;
    }
}

const vector<Batiment *> &Shop::get_contenu() const {
    ///Retourne le contenu du shop
    vector<Batiment*> contenu_vect;
    for (auto it = contenu.begin(); it != contenu.end(); it++) {
        contenu_vect.push_back(it->first);
    }
    return contenu_vect;
}