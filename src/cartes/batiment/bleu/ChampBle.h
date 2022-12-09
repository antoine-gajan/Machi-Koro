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
    void declencher_effet(unigned int possesseur) const override;
};

#endif //MACHI_KORO_CHAMPBLE_H
