#include "Epicerie.h"

Epicerie::Epicerie(string path_image)
        : Batiment("Épicerie",
                   0,
                   "Si vous possédez moins de deux monuments, recevez 2 pièces de la banque.",
                   path_image,
                   Vert,
                   {2},
                   "commerce") {}

