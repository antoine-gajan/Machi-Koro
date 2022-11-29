#ifndef MACHI_KORO_MASTER_CHALUTIER_H
#define MACHI_KORO_MASTER_CHALUTIER_H

//#include "Port.h"
#include "../Batiment.h"
#include "Joueur.h"
//#include "utils.h"
#include <list>
#include <vector>

class Chalutier : public Batiment{
public:
    Chalutier();
    virtual void declencher_effet();
};
#endif //MACHI_KORO_MASTER_CHALUTIER_H
