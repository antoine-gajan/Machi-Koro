#include <iostream>

#include "BanqueDeMinivilles.h"
#include "Boulangerie.h"
#include "EntrepriseDeDemenagement.h"
#include "EntrepriseDeTravauxPublics.h"
#include "Epicerie.h"
#include "FabriqueDeMeubles.h"
#include "Fleuriste.h"
#include "Fromagerie.h"
#include "HalleDeMarche.h"
#include "MarcheDeFruitsEtLegumes.h"
#include "MoonsterSoda.h"
#include "Superette.h"
using namespace std;

int main() {
    BanqueDeMinivilles x;
    x.declencher_effet();
    cout << x.get_nom() << endl;
    cout << x.get_path_image() << endl;
//    x.set_image("TEST");
//    cout << x.get_path_image() << endl;
    cout << x.get_type() << endl;
    cout << x.get_description() << endl;
    cout << x.get_prix() << endl;
//    cout << x.getMoment() << endl;


    return 0;
}