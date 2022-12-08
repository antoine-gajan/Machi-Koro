#ifndef MACHI_KORO_EPICERIE_H
#define MACHI_KORO_EPICERIE_H

#include "../Batiment.h"
#include "Joueur.h"
#include "../controleur/utils.h"
#include <list>
#include <vector>

class Epicerie : public Batiment {
public:
    Epicerie();
    ~Epicerie() override = default;
    Epicerie(const Epicerie& epicerie) = default;
    Batiment* clone() const override {return new Epicerie(*this);};
    void declencher_effet() const override;

};

#endif //MACHI_KORO_EPICERIE_H
