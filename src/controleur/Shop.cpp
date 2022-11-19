#include "Shop.h"

Shop::Shop(unsigned int nb_tas) : nb_tas_possibles(nb_tas), nb_tas_actuel(0){
    ///Constructeur de Shop

}

void Shop::completer_shop(Batiment *new_bat) {
    ///Complète le shop en ajoutant des cartes
    // On récupère l'élément dans le contenu du shop
    auto it = contenu.find(new_bat);
    // On augmente de 1 son nombre d'exemplaire dans le shop
    it->second ++;
}
