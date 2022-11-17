#include "Centre_commercial.h"
#include "../../Joueur/Joueur.h"

Centre_commercial::Centre_commercial(const string& path_image) :
    Monument(APRES, "Centre commercial", 10, "Les établissement rouge et vert vous rapportent une pièce de plus", path_image) {
    ///Constructeur de Centre commercial
}

unsigned int Centre_commercial::effet(unsigned int coup_init) {
    /// Effet de Centre commercial
    return coup_init + 1;
}