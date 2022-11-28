#include "StandDeHamburger.h"

StandDeHamburger::StandDeHamburger(const string &path_image) :
            Batiment("Stand de hamburger",
                     1 ,
                     "Recevez 1 piece du joueur qui a lance les des.",
                     path_image,
                     Rouge,
                     {8},
                     "restaurant"){};