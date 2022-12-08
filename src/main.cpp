#include <iostream>
using namespace std;

#include "EditionDeJeu.h"
//#include "Shop.h"
#include <algorithm>
#include "Pioche.h"

int main() {


    auto * edj = new EditionDeJeu("Standard");

    auto bat = edj->get_batiment();
    vector<Batiment*> batiments;

    for (auto it = bat.begin(); it != bat.end(); it++) {
        for (unsigned int i = 0; i < it->second; i++) {
            batiments.push_back(it->first->clone());
        }
    }


    cout << "Taille du map de edj : " << edj->get_batiment().size() << endl;

    cout << "Taille du vector batiment contenant les clones : " << batiments.size() << endl;

    cout << "Suppression de edj et donc des cartes : " << endl;
    delete edj;

    //cout << edj->get_batiment().size() << endl; // Erreur, n'existe plus ou pointe vers un espace mémoire non alloué

    cout << "Taille du vector batiment contenant les clones : " << batiments.size() << endl;
    cout << batiments.size() << endl; // OK, batiments est toujours alloué


    return 0;
}