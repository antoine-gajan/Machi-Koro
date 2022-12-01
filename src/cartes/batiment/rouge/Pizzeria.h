#ifndef PIZZERIA_H
#define PIZZERIA_H

#include "../Batiment.h"

class Pizzeria : public Batiment {
public:
    Pizzeria();
    void declencher_effet() const;
  
};

#endif 