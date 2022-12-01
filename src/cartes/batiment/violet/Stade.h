#ifndef MACHI_KORO_STADE_H
#define MACHI_KORO_STADE_H

#include <vector>
#include "Batiment.h"

class Stade : public Batiment {
public:
    Stade();
    void declencher_effet() const;
};

#endif //MACHI_KORO_STADE_H
