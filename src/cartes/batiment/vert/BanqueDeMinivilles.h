#ifndef MACHI_KORO_BANQUE_DE_MINIVILLES_H
#define MACHI_KORO_BANQUE_DE_MINIVILLES_H

#include "../Batiment.h"
#include "Joueur.h"
#include "../controleur/utils.h"
#include <list>
#include <vector>

class BanqueDeMinivilles : public Batiment {
public:
    BanqueDeMinivilles();
    ~BanqueDeMinivilles() override = default;
    BanqueDeMinivilles(const BanqueDeMinivilles& banqueDeMinivilles) = default;
    Batiment* clone() const override {return new BanqueDeMinivilles(*this);};
    void declencher_effet() const override;

};

#endif //MACHI_KORO_BANQUE_DE_MINIVILLES_H
