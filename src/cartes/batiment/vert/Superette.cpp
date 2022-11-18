#include "Superette.h"

Superette::Superette(string path_image)
        : Batiment("Supérette",
                   2,
                   "Recevez 3 pièce de la banque.",
                   path_image,
                   Vert,
                   {4},
                   "commerce") {}

