#include "MarcheDeFruitsEtLegumes.h"

MarcheDeFruitsEtLegumes::MarcheDeFruitsEtLegumes(string path_image)
        : Batiment("Marché de fruits et légumes",
                   2,
                   "Recevez 2 pièces de la banque pour chaque établissement de type champ que vous possédez.",
                   path_image,
                   Vert,
                   {11, 12},
                   "marche") {}

