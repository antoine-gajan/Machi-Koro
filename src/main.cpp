#include <iostream>
using namespace std;


#include "Cafe.h"
#include "ClubPrive.h"
#include "Pizzeria.h"
#include "Restaurant5Etoiles.h"
#include "RestaurantFamilial.h"
#include "StandDeHamburger.h"
#include "SushiBar.h"


int main() {
    SushiBar x;
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