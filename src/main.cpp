#include <iostream>
using namespace std;

#include "EditionDeJeu.h"
//#include "Shop.h"
#include <algorithm>
#include "Pioche.h"

int main() {
    EditionDeJeu edj("Standard");

    auto bat = edj.get_batiment();
    vector<Batiment*> batiments;

    for (auto it = bat.begin(); it != bat.end(); it++) {
        for (unsigned int i = 0; i < it->second; i++) {
            batiments.push_back(it->first);
        }
    }

    // on mélange la liste des batiments
    // Obtention d'un seed aléatoire
    random_device rd;
    mt19937 g(rd());
    // Mélange des batiments avec le seed
    shuffle(batiments.begin(), batiments.end(), g);

    // Création de la pioche
    Pioche pioche(batiments);

    Batiment * carte = pioche.getCarte();
    int i = 1;
    while (carte != nullptr) {
        cout << "Carte numero " << i << " tiree : " << carte->get_nom() << endl;
        carte = pioche.getCarte(); // affichera "la pioche est vide" à la fin
        i++;
    }

/*
    Shop shop(4);
    shop.affiche_shop();
    while (shop.get_nb_tas_reel() < shop.get_nb_tas_max() && !batiments.empty()) {
        shop.completer_shop(batiments.back());
        batiments.pop_back();
    }

    shop.affiche_shop();*/
    return 0;
}