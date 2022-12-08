#ifndef MACHI_KORO_CAFE_H
#define MACHI_KORO_CAFE_H

#include "Batiment.h"

class Cafe : public Batiment {
public:
    Cafe();
    Cafe(const Cafe& cafe) = default;
    Batiment* clone() const override {return new Cafe(*this);};
    void declencher_effet() const;

};

#endif //MACHI_KORO_CAFE_H

