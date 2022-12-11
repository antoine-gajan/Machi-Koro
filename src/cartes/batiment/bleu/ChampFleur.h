#ifndef MACHI_KORO_MASTER_CHAMPFLEUR_H
#define MACHI_KORO_MASTER_CHAMPFLEUR_H

#include "Batiment.h"

class ChampFleur : public Batiment{
public:
    ChampFleur();
    ~ChampFleur() override = default;
    ChampFleur(const ChampFleur& champFleur) = default;
    Batiment* clone() const override {return new ChampFleur(*this);};
    void declencher_effet(unsigned int possesseur, int bonus = 0) const override;
};

#endif //MACHI_KORO_MASTER_CHAMPFLEUR_H
