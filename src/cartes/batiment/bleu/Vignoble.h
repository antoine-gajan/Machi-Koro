#ifndef MACHI_KORO_VIGNOBLE_H
#define MACHI_KORO_VIGNOBLE_H

#include "Batiment.h"
//#include "Joueur.h"
#include <list>
#include <vector>

class Vignoble : public Batiment{
public:
    Vignoble();
    ~Vignoble() override = default;
    Vignoble(const Vignoble& vignoble) = default;
    Batiment* clone() const override {return new Vignoble(*this);};
    void declencher_effet(unsigned int possesseur, int bonus = 0) const override;
};
#endif //MACHI_KORO_VIGNOBLE_H
