#include "Aeroport.h"
#include "../../Joueur/Joueur.h"

Aeroport::Aeroport(string path_image) :
    Monument(APRES, "Aéroport", 30, "Si rien n'a été construit durant le tour, la banque donne 10 au joueur", path_image) {
    ///Constructeur de Aeroport
}

void Aeroport::effet(Joueur *joueur) {
    /// Effet de Aeroport
    if (joueur == nullptr) {
        return;
    }

    joueur->setArgent(joueur->getArgent() + 10);
}