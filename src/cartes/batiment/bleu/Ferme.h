#ifndef MACHI_KORO_MASTER_RANCH_H
#define MACHI_KORO_MASTER_RANCH_H

#include "../Batiment.h"
#include "Joueur.h"
#include <list>
#include <vector>

class Ferme : public Batiment{
public:
    Ferme();
    virtual void declencher_effet();
};

#endif //MACHI_KORO_MASTER_RANCH_H
