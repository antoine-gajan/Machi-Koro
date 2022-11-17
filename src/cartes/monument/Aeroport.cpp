#include "Aeroport.h"
#include "../../Joueur/Joueur.h"

Aeroport::Aeroport(const string& path_image) :
    Monument(APRES, "Aéroport", 30, "Si rien n'a été construit durant le tour, la banque donne 10 au joueur", path_image) {
    ///Constructeur de Aeroport
}

void Aeroport::effet(Joueur& joueur) {
    /// Effet de Aeroport

    joueur.set_argent(joueur.get_argent() + 10);
}