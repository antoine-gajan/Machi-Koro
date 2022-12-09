#ifndef MACHI_KORO_FLEURISTE_H
#define MACHI_KORO_FLEURISTE_H

#include "../Batiment.h"
#include "Joueur.h"
#include "../controleur/utils.h"
#include <list>
#include <vector>

class Fleuriste : public Batiment {
public:
    Fleuriste();
    ~Fleuriste() override = default;
    Fleuriste(const Fleuriste& fleuriste) = default;
    Batiment* clone() const override {return new Fleuriste(*this);};
    void declencher_effet(unigned int possesseur) const override;
};

#endif //MACHI_KORO_FLEURISTE_H
