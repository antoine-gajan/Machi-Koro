#include "BanqueDeMinivilles.h"

BanqueDeMinivilles::BanqueDeMinivilles(const string& path_image)
        : Batiment("Banque de minivilles",
                   0,
                   "Lorsque vous achetez cet établissement, recevez 5 pièces de la banque. Payez 2 pièces à la banque.",
                   path_image,
                   Vert,
                   {5, 6},
                   "commerce") {}

