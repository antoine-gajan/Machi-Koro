#ifndef MACHI_KORO_VIGNOBLE_H
#define MACHI_KORO_VIGNOBLE_H

#include "Batiment.h"
//#include "Joueur.h"
#include <list>
#include <vector>

class Vignoble : public Batiment{
public:
    Vignoble();
    Vignoble(const Vignoble& vignoble) = default;
    Batiment* clone() const override {return new Vignoble(*this);};
    void declencher_effet() const;
};
#endif //MACHI_KORO_VIGNOBLE_H
