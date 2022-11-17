#ifndef MACHI_KORO_SHOP_H
#define MACHI_KORO_SHOP_H

#include <map>
#include "Batiment.h"

class Shop{
private:
    unsigned int nb_tas_possibles;
    std::map<Batiment*, unsigned int> contenu;
    void completer_shop(Batiment* new_bat);
    Shop();
    ~Shop() = default;
public:
    unsigned int get_nb_tas_possibles() const {return nb_tas_possibles;};
    std::map<Batiment*, unsigned int> get_contenu() {return contenu;};
};

#endif //MACHI_KORO_SHOP_H
