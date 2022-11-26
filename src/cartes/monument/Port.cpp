#include "Port.h"
#include "Joueur.h"

Port::Port()
        : Monument(PENDANT,
                   "Port",
                   2,
                   "Si le résultat du jet de dé est supérieur ou égal à 10, vous pouvez ajouter 2 à ce résultat.",
                   "../../assets/Monuments/Port-travaux.png") {
    /// Constructeur de Port
}