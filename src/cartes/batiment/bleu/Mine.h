#ifndef MACHI_KORO_MASTER_MINE_H
#define MACHI_KORO_MASTER_MINE_H

#include "../Batiment.h"
#include "Joueur.h"
#include <list>
#include <vector>

class Mine : public Batiment{
public:
    Mine();
    void declencher_effet() const;
};
#endif //MACHI_KORO_MASTER_MINE_H
