#include "monument.h"
#include "carte.h"
#include <iostream>

using namespace std;

Monument::Monument(Moment_Effet moment, string nom, unsigned int prix, string description_effet, string path_image) : Carte(nom, prix, description_effet, path_image) {
    moment = moment;

}