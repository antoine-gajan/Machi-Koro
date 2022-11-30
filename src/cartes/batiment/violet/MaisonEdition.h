#ifndef MACHI_KORO_MAISONEDITION_H
#define MACHI_KORO_MAISONEDITION_H

#include "Batiment.h"

class MaisonEdition : public Batiment {
public:
    MaisonEdition();
    void declencher_effet() const;
};

#endif //MACHI_KORO_MAISONEDITION_H
