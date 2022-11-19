#include "Fleuriste.h"

Fleuriste::Fleuriste(const string& path_image)
        : Batiment("Fleuriste",
                   1,
                   "Recevez 1 pièce de la banque pour chaque Champ de fleurs que vous possédez.",
                   path_image,
                   Vert,
                   {6},
                   "commerce") {}

