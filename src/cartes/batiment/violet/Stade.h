#ifndef MACHI_KORO_STADE_H
#define MACHI_KORO_STADE_H

#include <vector>
#include "Batiment.h"
#include "Joueur.h"

class Stade : public Batiment {
public:
    Stade();
    virtual void declencher_effet() const;
};

#endif //MACHI_KORO_STADE_H
