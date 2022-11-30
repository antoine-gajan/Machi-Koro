#ifndef MACHI_KORO_MOONSTER_SODA_H
#define MACHI_KORO_MOONSTER_SODA_H

#include "../Batiment.h"
#include "Joueur.h"
#include "../controleur/utils.h"
#include <list>
#include <vector>

class MoonsterSoda : public Batiment {
public:
    MoonsterSoda();
    void declencher_effet();
};

#endif //MACHI_KORO_MONSTER_SODA_H
