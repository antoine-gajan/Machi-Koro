#include "Chalutier.h"

Chalutier::Chalutier() :
        Batiment("Chalutier",
        5,
        "Le joueur dont c'est le tour lance deux des. Si vous avez le Port, recevez de la banque autant de pieces que le total des deux des",
        "../../assets/batiments/bleu/Chalutier.jpg",
        Bleu,
        list<unsigned int>{12,13,14},
        "Bateau"){}

///Constructeur de Chalutier

void Chalutier::declencher_effet(unsigned int possesseur, int bonus) const{
    //j'ai deliberement retire les parametres joueur actuel et val_des de declencher effet pour respecter la methode virtuelle declaree dans Batiment.h
    cout << "Activation de l'effet de Chalutier" << endl;
    /*
    if(possede_monument(joueur_actuel,"Port") != nullptr){
        unsigned int argent = joueur_actuel->get_argent();
        argent += val_des;
        joueur_actuel->set_argent(argent);
    }
     */
}
///A voir plus tard, methode declencher effet de chalutier
