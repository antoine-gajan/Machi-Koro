#ifndef MACHI_KORO_MASTER_CHALUTIER_H
#define MACHI_KORO_MASTER_CHALUTIER_H

//#include "Port.h"
#include "Batiment.h"
//#include "Joueur.h"
//#include "utils.h"
#include <list>
#include <vector>

class Chalutier : public Batiment{
public:
    Chalutier();
    ~Chalutier() override = default;
    Chalutier(const Chalutier& chalutier) = default;
    Batiment* clone() const override {return new Chalutier(*this);};
    void declencher_effet() const override;
};
#endif //MACHI_KORO_MASTER_CHALUTIER_H
