#include "Chalutier.h"

Chalutier::Chalutier(const string &path_image) : Batiment("Chalutier",5
        ,"Le joueur dont c'est le tour lance deux dés. Si vous avez le Port, recevez de la banque autant de pièces que le total des deux dés",
        path_image,
        Bleu
        ,list<unsigned int>{12,13,14},
        "Bateau"){};
///Constructeur de Chalutier

void Chalutier::declencher_effet(Joueur *joueur_actuel,unsigned int val_des) {
    if(possede_monument(joueur_actuel,"Port") != nullptr){
        unsigned int argent = joueur_actuel->get_argent();
        argent += val_des;
        joueur_actuel->set_argent(argent);
    }
}
///A voir plus tard, méthode déclencher effet de chalutier