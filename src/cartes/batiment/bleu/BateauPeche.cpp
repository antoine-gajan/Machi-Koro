#include "BateauPeche.h"
BateauPeche::BateauPeche(const string &path_image) :
        Batiment("Petit bateau de pêche",
                 2,
                 "Si vous avez le port, recevez 3 pièces",
                 path_image,
                 Bleu,
                 list<unsigned int>{8},
                 "Bateau"){};
///Constructeur de BateauPeche


void BateauPeche::declencher_effet(Joueur* joueur_actuel) {
    unsigned int argent = joueur_actuel->get_argent();
    argent+=3;
    joueur_actuel->set_argent(argent);
}
//L'effet est que le joueur reçoit 3 pièces de la banque si 8 tombe à tout moment de la partie
