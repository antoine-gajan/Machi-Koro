#ifndef MACHI_KORO_CENTREIMPOTS_H
#define MACHI_KORO_CENTREIMPOTS_H

#include "Batiment.h"

class CentreImpots : public Batiment {
public:
    CentreImpots();
    void declencher_effet() const;
};

#endif //MACHI_KORO_CENTREIMPOTS_H
