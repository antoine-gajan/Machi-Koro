#ifndef MACHI_KORO_MASTER_FORET_H
#define MACHI_KORO_MASTER_FORET_H

#include "../Batiment.h"
#include "Joueur.h"
#include <list>
#include <vector>

class Foret : public Batiment{
public:
    Foret();
    void declencher_effet() const;
};

#endif //MACHI_KORO_MASTER_FORET_H
