#include "CentreCommercial.h"
#include "Partie.h"

using namespace std;

CentreCommercial::CentreCommercial() :
    Monument(APRES,
             "CentreCommercial",
             10,
             "Les etablissement cafe et commerce vous rapportent une piece de plus",
             "../assets/monuments/Centre-commercial-travaux.png",
             "../assets/monuments/Centre-commercial-active.png") {
    /// Constructeur de Centre commercial
}

void CentreCommercial::declencher_effet(unsigned int possesseur, int bonus) const {
    Joueur * joueurs = Partie::get_instance()->get_tab_joueurs()[possesseur];
    cout << "Activation de l'efet du Centre commercial du joueur \"" << joueurs->get_nom() << "\"" << endl;
}
