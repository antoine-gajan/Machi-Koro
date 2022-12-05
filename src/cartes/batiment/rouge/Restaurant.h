#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Batiment.h"

class Restaurant : public Batiment {
public:
    Restaurant();
    void declencher_effet() const;

};

#endif 
