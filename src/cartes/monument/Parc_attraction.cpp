#include "Parc_attraction.h"
#include "../../Joueur/Joueur.h"

Parc_attraction::Parc_attraction(const string& path_image) :
    Monument(APRES, "Parc d'attractions", 16, "Si le jet de dé est un double vous pouvez les relancer", path_image) {
    /// Constructeur de Parc_attraction
}

void Parc_attraction::effet(const Joueur& joueur) {
    /// Effet de Parc_attraction
}