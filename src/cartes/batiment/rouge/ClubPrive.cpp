#include "ClubPrive.h"

ClubPrive::ClubPrive(const string &path_image) :
            Batiment("Club prive",
                     4 ,
                     "Recevez toutes les pieces du joueur qui a lance les des si celui-ci possede au moins trois monuments construits.",
                     path_image,
                     Rouge ,
                     {12,13,14},
                     "restaurant"){};