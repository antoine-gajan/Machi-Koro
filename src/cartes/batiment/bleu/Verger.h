#ifndef MACHI_KORO_MASTER_VERGER_H
#define MACHI_KORO_MASTER_VERGER_H

#include "Batiment.h"
//#include "Joueur.h"
#include <list>
#include <vector>

class Verger : public Batiment{
public:
    Verger();
    ~Verger() override = default;
    Verger(const Verger& verger) = default;
    Batiment* clone() const override {return new Verger(*this);};
    void declencher_effet() const override;
};
#endif //MACHI_KORO_MASTER_VERGER_H
