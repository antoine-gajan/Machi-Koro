#ifndef MACHI_KORO_MASTER_CHAMPFLEUR_H
#define MACHI_KORO_MASTER_CHAMPFLEUR_H

#include "Batiment.h"
//#include "Joueur.h"
#include <list>
#include <vector>

class ChampFleur : public Batiment{
public:
    ChampFleur();
    ChampFleur(const ChampFleur& champFleur) = default;
    Batiment* clone() const override {return new ChampFleur(*this);};
    void declencher_effet() const;
};

#endif //MACHI_KORO_MASTER_CHAMPFLEUR_H
