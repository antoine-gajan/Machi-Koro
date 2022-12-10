#ifndef MACHI_KORO_BOULANGERIE_H
#define MACHI_KORO_BOULANGERIE_H

#include "../Batiment.h"
#include "Joueur.h"
#include <list>
#include <vector>

class Boulangerie : public Batiment {
public:
    Boulangerie();
    ~Boulangerie() override = default;
    Boulangerie(const Boulangerie& boulangerie) = default;
    Batiment* clone() const override {return new Boulangerie(*this);};
    void declencher_effet(unsigned int possesseur) const override;
};

#endif //MACHI_KORO_BOULANGERIE_H
