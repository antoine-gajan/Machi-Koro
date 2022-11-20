#include "Chalutier.h"

Chalutier::Chalutier(string &path_image) : Batiment("Chalutier",5
        ,"Le joueur dont c'est le tour lance deux dés. Si vous avez le Port, recevez de la banque autant de pièces que le total des deux dés",
        path_image,Bleu
        ,list<unsigned int>{12,13,14},"Bateau"){};
///Constructeur de Chalutier

void Chalutier::declencher_effet(Joueur *joueur_actuel) {}
///A voir plus tard, méthode déclencher effet de chalutier