#ifndef MACHI_KORO_MASTER_CHAMPSMAIS_H
#define MACHI_KORO_MASTER_CHAMPSMAIS_H

#include "Batiment.h"
//#include "Joueur.h"
#include <list>
#include <vector>

class ChampMais : public Batiment{
public:
    ChampMais();
    ChampMais(const ChampMais& champMais) = default;
    Batiment* clone() const override {return new ChampMais(*this);};
    void declencher_effet() const;
};

#endif //MACHI_KORO_MASTER_CHAMPSMAIS_H
