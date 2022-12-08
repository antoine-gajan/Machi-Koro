#ifndef MACHI_KORO_MARCHE_DE_FRUITS_ET_LEGUMES_H
#define MACHI_KORO_MARCHE_DE_FRUITS_ET_LEGUMES_H

#include "../Batiment.h"
#include "Joueur.h"
#include "../controleur/utils.h"
#include <list>
#include <vector>

class MarcheDeFruitsEtLegumes : public Batiment {
public:
    MarcheDeFruitsEtLegumes();
    ~MarcheDeFruitsEtLegumes() override = default;
    MarcheDeFruitsEtLegumes(const MarcheDeFruitsEtLegumes& marcheDeFruitsEtLegumes) = default;
    Batiment* clone() const override {return new MarcheDeFruitsEtLegumes(*this);};
    void declencher_effet() const override;
};

#endif //MACHI_KORO_MARCHE_DE_FRUITS_ET_LEGUMES_H
