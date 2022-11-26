#include "Gare.h"
#include "Joueur.h"
#include <iostream>

using namespace std;

Gare::Gare()
    : Monument(AVANT,
               "Gare",
               4,
               "Vous pouvez lancer 2 dés",
               "../../assets/Monuments/Gare-travaux.png") {
    /// Constructeur de Gare
}