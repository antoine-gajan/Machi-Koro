#ifndef MACHI_KORO_MASTER_VERGER_H
#define MACHI_KORO_MASTER_VERGER_H

#include "../Batiment.h"
#include "Joueur.h"
#include <list>
#include <vector>

class Verger : public Batiment{
public:
    Verger();
    void declencher_effet() const;
};
#endif //MACHI_KORO_MASTER_VERGER_H
