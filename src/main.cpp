#include <iostream>

/// Importation des classes monuments
#include "Batiment.h"
#include "Carte.h"
#include "ChaineTelevision.h"
#include "MaisonEdition.h"
#include "Stade.h"

using namespace std;

int main() {
    Stade x;
    cout << x.get_nom();
    x.declencher_effet();


    return 0;
}