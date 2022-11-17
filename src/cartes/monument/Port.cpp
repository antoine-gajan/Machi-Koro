#include "Port.h"
#include "../../Joueur/Joueur.h"

Port::Port(const string& path_image)
        : Monument(PENDANT, "Port", 2,
                   "Si le résultat du jet de dé est supérieur ou égal à 10, vous pouvez ajouter 2 à ce résultat.", path_image) {
    ///Constructeur de Port
}

void Port::effet(const Joueur& joueur) {
    /// Effet de Port
    // Test si le joueur a la possibilite de jeter deux des
    // Si oui, test si le résultat est supérieur à 10
    // Si oui, le joueur peut ajouter 2 à son lancer de dé
}