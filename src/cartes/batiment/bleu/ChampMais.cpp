#include "ChampMais.h"

ChampMais::ChampMais(string &path_image) : Batiment("Champs de maïs",2
        ,"Recevez une pièce de la banque si vous avez moins de deux monuments construits",path_image,Bleu
        ,list<unsigned int>{3,4},"Champ"){};
///Constructeur de Ferme

void ChampMais::declencher_effet(Joueur *joueur_affecté) {
    if(joueur_affecté->get_liste_monument().size() < 2){
        joueur_affecté->set_argent(joueur_affecté->get_argent() + 1);
        //On augmente de un l'argent du joueur pointé s'il a moins de deux monuments construits
    }
}
