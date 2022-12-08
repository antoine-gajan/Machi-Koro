#ifndef PIZZERIA_H
#define PIZZERIA_H

#include "Batiment.h"

class Pizzeria : public Batiment {
public:
    Pizzeria();
    ~Pizzeria() override = default;
    Pizzeria(const Pizzeria& pizzeria) = default;
    Batiment* clone() const override {return new Pizzeria(*this);};
    void declencher_effet() const override;
  
};

#endif 