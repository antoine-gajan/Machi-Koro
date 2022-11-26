#include "FabriqueDeMeubles.h"

FabriqueDeMeubles::FabriqueDeMeubles(string path_image)
        : Batiment("Fabrique de meubles",
                   3,
                   "Recevez 3 pièce de la banque pour chaque établissement de type engrenage que vous possédez.",
                   path_image,
                   Vert,
                   {8},
                   "usine") {}

