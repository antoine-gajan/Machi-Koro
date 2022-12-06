#include <iostream>
using namespace std;

#include "EditionDeJeu.h"
#include "Shop.h"
#include <random>

int main() {
    EditionDeJeu edj("Standard");

    auto bat = edj.get_batiment();
    vector<Batiment*> batiments;

    for (auto it = bat.begin(); it != bat.end(); it++) {
        for (unsigned int i = 0; i < it->second; i++) {
            batiments.push_back(it->first);
        }
    }

    random_shuffle(batiments.begin(), batiments.end());

    Shop shop(4);
    shop.affiche_shop();
    while (shop.get_nb_tas_reel() < shop.get_nb_tas_max() && !batiments.empty()) {
        shop.completer_shop(batiments.back());
        batiments.pop_back();
    }

    shop.affiche_shop();
    return 0;
}