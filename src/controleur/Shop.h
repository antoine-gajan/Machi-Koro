#ifndef MACHI_KORO_SHOP_H
#define MACHI_KORO_SHOP_H

#include <map>
#include "Batiment.h"

class Shop{
private:
    unsigned int nb_tas_possibles;
    unsigned int nb_tas_actuel;
    std::map<Batiment*, unsigned int> contenu;
    void completer_shop(Batiment* new_bat);
    Shop(unsigned int nb_tas);
    ~Shop() = default;
public:
    unsigned int get_nb_tas_possibles() const {return nb_tas_possibles;};
    const std::map<Batiment*, unsigned int>& get_contenu() const {return contenu;};
};

#endif //MACHI_KORO_SHOP_H
