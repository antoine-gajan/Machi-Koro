#include <iostream>
using namespace std;

#include "EditionDeJeu.h"
#include "Shop.h"
#include <algorithm>
#include "Pioche.h"
#include "Partie.h"

int main() {

    EditionDeJeu *edj = new EditionDeJeu("Standard");
    vector<EditionDeJeu*> editions;
    editions.push_back(edj);

    Partie *partie = new Partie(editions);

    return 0;
}