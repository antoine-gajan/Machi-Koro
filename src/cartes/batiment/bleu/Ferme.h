#ifndef MACHI_KORO_MASTER_RANCH_H
#define MACHI_KORO_MASTER_RANCH_H

#include "Batiment.h"
//#include "Joueur.h"
#include <list>
#include <vector>

class Ferme : public Batiment{
public:
    Ferme();
    ~Ferme() override = default;
    Ferme(const Ferme& ferme) = default;
    Batiment* clone() const override {return new Ferme(*this);};
    void declencher_effet() const override;
};

#endif //MACHI_KORO_MASTER_RANCH_H
