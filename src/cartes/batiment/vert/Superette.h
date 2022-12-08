#ifndef MACHI_KORO_SUPERETTE_H
#define MACHI_KORO_SUPERETTE_H

#include "../Batiment.h"
#include "Joueur.h"
#include "../controleur/utils.h"
#include <list>
#include <vector>

class Superette : public Batiment {
public:
    Superette();
    ~Superette() override = default;
    Superette(const Superette& superette) = default;
    Batiment* clone() const override {return new Superette(*this);};
    void declencher_effet() const override;
};

#endif //MACHI_KORO_SUPERETTE_H
