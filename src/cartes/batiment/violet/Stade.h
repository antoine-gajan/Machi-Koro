#ifndef MACHI_KORO_STADE_H
#define MACHI_KORO_STADE_H

#include <vector>
#include "Batiment.h"

class Stade : public Batiment {
public:
    Stade();
    Stade(const Stade& stade) = default;
    Batiment* clone() const override {return new Stade(*this);};
    void declencher_effet() const;
};

#endif //MACHI_KORO_STADE_H
