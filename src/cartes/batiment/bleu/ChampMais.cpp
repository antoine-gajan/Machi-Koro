#include "ChampMais.h"

ChampMais::ChampMais() :
    Batiment("Champs de mais",
         2,
        "Recevez une piece de la banque si vous avez moins de deux monuments construits",
        "../../assets/batiments/bleu/ChampMais.jpg",
        Bleu,
        list<unsigned int>{3,4},
        "Champ"){};
///Constructeur de Ferme

void ChampMais::declencher_effet() {
    //j'ai délibérément retiré le paramètre joueur actuel de declencher effet pour respecter la méthode virtuelle déclarée dans Batiment.h
    cout<<"declencher effet de ChampMais";
    /*
    if(joueur_affecté->get_liste_monument().size() < 2){
        joueur_affecté->set_argent(joueur_affecté->get_argent() + 1);
        //On augmente de un l'argent du joueur pointé s'il a moins de deux monuments construits
    }
     */
}
