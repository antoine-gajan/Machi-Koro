#include <iostream>
using namespace std;

#include "EditionDeJeu.h"
#include "Shop.h"
#include <algorithm>
#include "Pioche.h"
#include "Partie.h"

int main() {

    EditionDeJeu edj = EditionDeJeu("Standard");

    Partie test = Partie(&edj);

    return 0;
}