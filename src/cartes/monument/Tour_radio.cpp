#include "Tour_radio.h"
#include "../../Joueur/Joueur.h"

Tour_radio::Tour_radio(const string& path_image) :
    Monument(APRES, "Tour radio", 22, "Une fois par tour vous pouvez relancer vos dés", path_image) {
    ///Constructeur de Tour_radio
}

void Tour_radio::effet(const Joueur& joueur) {
    /// Effet de la carte Tour_radio
}