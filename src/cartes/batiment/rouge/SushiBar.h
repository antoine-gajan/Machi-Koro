#ifndef SUSHI_BAR_H
#define SUSHI_BAR_H

#include "Batiment.h"

class SushiBar : public Batiment {
public:
    SushiBar();
    SushiBar(const SushiBar& sushiBar) = default;
    Batiment* clone() const override {return new SushiBar(*this);};
    void declencher_effet() const;
  
};

#endif 