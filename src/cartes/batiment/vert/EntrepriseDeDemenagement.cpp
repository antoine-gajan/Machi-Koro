#include "EntrepriseDeDemenagement.h"

EntrepriseDeDemenagement::EntrepriseDeDemenagement(string path_image)
        : Batiment("Entreprise de déménagement",
                   2,
                   "Donnez à un autre joueur un de vos établissements qui ne soit pas de type spécial. Puis recevez 4 pièces de la banque.",
                   path_image,
                   Vert,
                   {9, 10},
                   "Entreprise") {}

