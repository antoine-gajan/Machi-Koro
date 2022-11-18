#include "Boulangerie.h"

Boulangerie::Boulangerie(string path_image)
        : Batiment("Boulangerie",
                   1,
                   "Recevez une pièce de la banque.",
                   path_image,
                   Vert,
                   {2, 3},
                   "commerce") {}

