#include "Gare.h"
#include "../../Joueur/Joueur.h"
#include <iostream>

using namespace std;

Gare::Gare(const string& path_image)
    : Monument(AVANT, "Gare", 4, "Vous pouvez lancer 2 dés", path_image) {
}

void Gare::effet(Joueur *joueur) {
    /// Effet de Gare
    // Laisser le joueur lancer 2 dés
}