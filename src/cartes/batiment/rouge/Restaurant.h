#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Batiment.h"

class Restaurant : public Batiment {
public:
    Restaurant();
    ~Restaurant() override = default;
    Restaurant(const Restaurant& restaurant) = default;
    Batiment* clone() const override {return new Restaurant(*this);};
    void declencher_effet(unigned int possesseur) const override;

};

#endif 
