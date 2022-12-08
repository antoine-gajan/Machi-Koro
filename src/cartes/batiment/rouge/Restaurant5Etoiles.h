#ifndef RESTAURANT_5_ETOILES_H
#define RESTAURANT_5_ETOILES_H

#include "Batiment.h"

class Restaurant5Etoiles : public Batiment {
public:
    Restaurant5Etoiles();
    ~Restaurant5Etoiles() override = default;
    Restaurant5Etoiles(const Restaurant5Etoiles& restaurant5Etoiles) = default;
    Batiment* clone() const override {return new Restaurant5Etoiles(*this);};
    void declencher_effet() const override;
  
};

#endif 