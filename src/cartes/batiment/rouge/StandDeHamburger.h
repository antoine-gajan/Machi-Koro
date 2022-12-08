#ifndef STAND_DE_HAMBURGER_H
#define STAND_DE_HAMBURGER_H

#include "Batiment.h"

class StandDeHamburger : public Batiment {
public:
    StandDeHamburger();
    ~StandDeHamburger() override = default;
    StandDeHamburger(const StandDeHamburger& standDeHamburger) = default;
    Batiment* clone() const override {return new StandDeHamburger(*this);};
    void declencher_effet() const override;
  
};

#endif 