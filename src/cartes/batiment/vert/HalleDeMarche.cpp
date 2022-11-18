#include "HalleDeMarche.h"

HalleDeMarche::HalleDeMarche(string path_image)
        : Batiment("Halle de marché",
                   2,
                   "Recevez 2 pièces de la banque pour chaque établissement de type café que vous possédez",
                   path_image,
                   Vert,
                   {12, 13},
                   "usine") {}

