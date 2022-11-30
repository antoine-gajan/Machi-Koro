#ifndef MACHI_KORO_MASTER_CHAMPSMAIS_H
#define MACHI_KORO_MASTER_CHAMPSMAIS_H

#include "../Batiment.h"
#include "Joueur.h"
#include <list>
#include <vector>

class ChampMais : public Batiment{
public:
    ChampMais();
    void declencher_effet();
};

#endif //MACHI_KORO_MASTER_CHAMPSMAIS_H
