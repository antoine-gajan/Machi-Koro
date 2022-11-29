#ifndef MACHI_KORO_MASTER_VERGER_H
#define MACHI_KORO_MASTER_VERGER_H

#include "../Batiment.h"
#include "Joueur.h"
#include <list>
#include <vector>

class Verger : public Batiment{
public:
    Verger();
    virtual void declencher_effet();
};
#endif //MACHI_KORO_MASTER_VERGER_H
