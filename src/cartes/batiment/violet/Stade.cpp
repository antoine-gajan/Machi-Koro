#include "Stade.h"

Stade::Stade(string path_image)
        : Batiment("Stade", 6, "Recevez 2 pièces de la part de chaque autre joueur", path_image, Violet, list<unsigned int>{6}, "spécial") {
    ///Constructeur de Stade
}