#ifndef MACHI_KORO_CHAMPBLE_H
#define MACHI_KORO_CHAMPBLE_H

#include "Batiment.h"
//#include "Joueur.h"
#include <list>
#include <vector>

class ChampBle : public Batiment{
public:
    ChampBle();
    ~ChampBle() override = default;
    ChampBle(const ChampBle& champBle) = default;
    Batiment* clone() const override {return new ChampBle(*this);};
    void declencher_effet(unsigned int possesseur, int bonus = 0) const override;
};

#endif //MACHI_KORO_CHAMPBLE_H
