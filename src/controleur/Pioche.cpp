#include "Pioche.h"
#include "Batiment.h"

Pioche::Pioche(vector<Batiment*> batiments) {
    /// Constructeur de la classe Pioche

    for (size_t i = 0; i < batiments.size(); i++) {
        contenu.push_back(batiments[i]);
    }
}

Pioche::~Pioche() {
    /// Destructeur de la classe Pioche
    contenu.clear();
}