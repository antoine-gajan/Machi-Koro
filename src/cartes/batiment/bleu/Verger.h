#ifndef MACHI_KORO_MASTER_VERGER_H
#define MACHI_KORO_MASTER_VERGER_H

#include "Batiment.h"

class Verger : public Batiment{
public:
    Verger();
    ~Verger() override = default;
    Verger(const Verger& verger) = default;
    Batiment* clone() const override {return new Verger(*this);};
    void declencher_effet(unsigned int possesseur, int bonus = 0) const override;
};
#endif //MACHI_KORO_MASTER_VERGER_H
