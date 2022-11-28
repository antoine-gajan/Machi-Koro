#include "Aeroport.h"
#include "Joueur.h"

Aeroport::Aeroport() :
    Monument(APRES,
                "Aéroport",
                30,
                "Si rien n'a été construit durant le tour, la banque donne 10 au joueur",
                "../../assets/Monuments/Aeroport-travaux.jpeg") {
    /// Constructeur de Aeroport
}