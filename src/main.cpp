#include <iostream>
using namespace std;

#include "EditionDeJeu.h"

int main() {
    EditionDeJeu edj("Standard");

    cout << edj.get_nom() << endl;
    auto bat = edj.get_batiment();
    cout << "Batiments: " << bat.size() << endl;
    for (auto it = bat.begin(); it != bat.end(); ++it) {
        cout << it->first->get_nom() << " : " << it->second << endl;
    }

    cout << "\n\nMonuments: " << edj.get_monument().size() << endl;
    auto mon = edj.get_monument();
    for (auto it = mon.begin(); it != mon.end(); ++it) {
        cout << (*it)->get_nom() << endl;
    }


    return 0;
}