#ifndef MACHI_KORO_MASTER_FORET_H
#define MACHI_KORO_MASTER_FORET_H

#include "Batiment.h"
//#include "Joueur.h"
#include <list>
#include <vector>

class Foret : public Batiment{
public:
    Foret();
    ~Foret() override = default;
    Foret(const Foret& foret) = default;
    Batiment* clone() const override {return new Foret(*this);};
    void declencher_effet(unigned int possesseur) const override;
};

#endif //MACHI_KORO_MASTER_FORET_H
