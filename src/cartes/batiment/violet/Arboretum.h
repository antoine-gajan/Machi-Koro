#ifndef SRC_ARBORETUM_H
#define SRC_ARBORETUM_H

#include "Batiment.h"

class Arboretum : public Batiment {
public:
    Arboretum();
    void declencher_effet() const;
};


#endif //SRC_ARBORETUM_H
