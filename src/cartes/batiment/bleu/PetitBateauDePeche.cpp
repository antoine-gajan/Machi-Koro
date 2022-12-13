#include "PetitBateauDePeche.h"
#include "Partie.h"

PetitBateauDePeche::PetitBateauDePeche() :
        Batiment("PetitBateauDePeche",
                 2,
                 "Si vous avez le port, recevez 3 pieces",
                 "../../assets/batiments/bleu/Petit-bateau-peche.jpg",
                 Bleu,
                 list<unsigned int>{8},
                 "Bateau"){}
///Constructeur de BateauPeche


void PetitBateauDePeche::declencher_effet(unsigned int possesseur, int bonus) const{

    //creation de l'instance de partie
    Partie * partie = Partie::get_instance();
    Joueur* joueur_actuel = partie->get_tab_joueurs()[possesseur];

    if(joueur_actuel->possede_monument("Port")){
        cout << "Activation de l'effet de BateauPeche" << endl;//on affiche seulement si le joueur possede le port
        unsigned int argent = joueur_actuel->get_argent();
        argent+=3;
        joueur_actuel->set_argent(argent);
    }

}

