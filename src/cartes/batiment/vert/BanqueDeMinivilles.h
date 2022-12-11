#ifndef MACHI_KORO_BANQUE_DE_MINIVILLES_H
#define MACHI_KORO_BANQUE_DE_MINIVILLES_H

#include "../Batiment.h"
#include "Joueur.h"
#include <list>
#include <vector>

class BanqueDeMinivilles : public Batiment {
public:
    BanqueDeMinivilles();
    ~BanqueDeMinivilles() override = default;
    BanqueDeMinivilles(const BanqueDeMinivilles& banqueDeMinivilles) = default;
    Batiment* clone() const override {return new BanqueDeMinivilles(*this);};
    void declencher_effet(unsigned int possesseur, int bonus = 0) const override;

};

#endif //MACHI_KORO_BANQUE_DE_MINIVILLES_H
