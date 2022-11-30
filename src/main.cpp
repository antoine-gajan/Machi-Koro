#include <iostream>

/// Importation des classes monuments
#include "Batiment.h"
#include "Carte.h"
#include "ChaineTelevision.h"
#include "MaisonEdition.h"
#include "Startup.h"

using namespace std;

int main() {
    Startup x;
    cout << x.get_nom();
    x.declencher_effet();


    return 0;
}