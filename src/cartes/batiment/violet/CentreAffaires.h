#ifndef MACHI_KORO_CENTREAFFAIRES_H
#define MACHI_KORO_CENTREAFFAIRES_H

#include "Batiment.h"
#include <list>
#include <vector>

class CentreAffaires : public Batiment {
public:
    CentreAffaires();
    CentreAffaires(const CentreAffaires& centreAffaires) = default;
    Batiment* clone() const override {return new CentreAffaires(*this);};
    void declencher_effet() const;
};

#endif //MACHI_KORO_CENTREAFFAIRES_H
