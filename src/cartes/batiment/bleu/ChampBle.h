#ifndef MACHI_KORO_CHAMPBLE_H
#define MACHI_KORO_CHAMPBLE_H

#include "../Batiment.h"
#include "Joueur.h"
#include <list>
#include <vector>

class ChampBle : public Batiment{
public:
    ChampBle();
    virtual void declencher_effet();
};

#endif //MACHI_KORO_CHAMPBLE_H
