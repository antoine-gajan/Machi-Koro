#include "MgaGameCenter.h"
#include "Partie.h"

MgaGameCenter::MgaGameCenter() :
        Batiment("MgaGameCenter",
                 7,
                 "Choississez un de vos etablissements qui ne soit pas de type special et activez son effet. Puis fermez le MGA game center.",
                 "../../../assets/batiments/Violet/MgaGameCenter.jpg",
                 Violet,
                 {10},
                 "special") {
    ///Constructeur de MgaGameCenter
}

void MgaGameCenter::declencher_effet(unsigned int possesseur, int bonus) const{
    /// Effet de la classe MGA Game Center
    Partie* instance = Partie::get_instance();
    const vector<Joueur *> &tab_joueurs = instance->get_tab_joueurs();
    Joueur *j_actuel = tab_joueurs[possesseur];
    cout << "Activation de l'effet de l'entreprise de renovation du joueur \"" << j_actuel->get_nom()<<"\"" << endl;

    // Selection du batiment du joueur
    Batiment *batiment = j_actuel->selectionner_batiment();
    while (batiment->get_couleur() == Violet) {
        cout << "Vous ne pouvez pas selectionner un batiment violet !" << endl;
        batiment = j_actuel->selectionner_batiment();
    }

    batiment->declencher_effet(possesseur, bonus);

    j_actuel->fermer_batiment(j_actuel->possede_batiment("MgaGameCenter"));
}
