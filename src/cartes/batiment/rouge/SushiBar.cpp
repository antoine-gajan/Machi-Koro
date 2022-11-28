#include "SushiBar.h"

SushiBar::SushiBar(const string &path_image) :
            Batiment("Sushi bar",
                     4 ,
                     "Si vous avez le port, recevez 3 pieces du joueur qui a lance les des.",
                     path_image,
                     Rouge ,
                     {1},
                     "restaurant"){};