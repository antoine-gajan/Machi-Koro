#include <iostream>

/// Importation des classes monuments
#include "Aeroport.h"
#include "CentreCommercial.h"
#include "FabriqueDuPereNoel.h"
#include "Gare.h"
#include "HotelDeVille.h"
#include "ParcAttraction.h"
#include "Port.h"
#include "TourRadio.h"

using namespace std;

int main() {
    CentreCommercial x;
    cout << x.get_nom() << endl;
    cout << x.get_path_image() << endl;
    x.set_image("TEST");
    cout << x.get_path_image() << endl;
    cout << x.get_type() << endl;
    cout << x.get_description() << endl;
    cout << x.get_prix() << endl;
    cout << x.getMoment() << endl;


    return 0;
}