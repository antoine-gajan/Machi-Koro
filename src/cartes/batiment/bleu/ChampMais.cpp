#include "ChampMais.h"

ChampMais::ChampMais() :
    Batiment("ChampMais",
         2,
        "Recevez une piece de la banque si vous avez moins de deux monuments construits",
        "../../assets/batiments/bleu/ChampMais.jpg",
        Bleu,
        list<unsigned int>{3,4},
        "Champ"){};
///Constructeur de Ferme

void ChampMais::declencher_effet(unsigned int possesseur, int bonus) const{
    //j'ai deliberement retire le parametre joueur actuel de declencher effet pour respecter la methode virtuelle declaree dans Batiment.h
    cout << "Activation de l'effet de ChampMais" << endl;
    /*
    if(joueur_affecte->get_liste_monument().size() < 2){
        joueur_affecte->set_argent(joueur_affecte->get_argent() + 1);
        //On augmente de un l'argent du joueur pointe s'il a moins de deux monuments construits
    }
     */
}
