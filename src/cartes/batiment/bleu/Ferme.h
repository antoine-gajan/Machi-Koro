#ifndef MACHI_KORO_MASTER_RANCH_H
#define MACHI_KORO_MASTER_RANCH_H

#include "Batiment.h"
//#include "Joueur.h"
#include <list>
#include <vector>

class Ferme : public Batiment{
public:
    Ferme();
    void declencher_effet() const;
};

#endif //MACHI_KORO_MASTER_RANCH_H
