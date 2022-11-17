#include "Pioche.h"
#include "../cartes/batiment/Batiment.h"

Pioche::Pioche(Batiment *batiments[]) {
    /// Constructeur de la classe Pioche
    if (batiments != nullptr) {
        for (int i = 0; i < 10; i++) {
            contenu.push_back(batiments[i]);
        }
    }
}