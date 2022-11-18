#include "Fromagerie.h"

Fromagerie::Fromagerie(string path_image)
        : Batiment("Fromagerie",
                   5,
                   "Recevez 3 pièce de la banque pour chaque établissement de type vache que vous possédez.",
                   path_image,
                   Vert,
                   {7},
                   "usine") {}

