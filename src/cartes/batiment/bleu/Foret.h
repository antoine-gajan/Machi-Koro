#ifndef MACHI_KORO_MASTER_FORET_H
#define MACHI_KORO_MASTER_FORET_H

#include "../Batiment.h"
#include "Joueur.h"
#include <list>
#include <vector>

class Foret : public Batiment{
public:
    Foret();
    virtual void declencher_effet();
};

#endif //MACHI_KORO_MASTER_FORET_H
