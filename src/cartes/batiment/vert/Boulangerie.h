#ifndef MACHI_KORO_BOULANGERIE_H
#define MACHI_KORO_BOULANGERIE_H

#include "../Batiment.h"
#include "Joueur.h"
#include <list>
#include <vector>

class Boulangerie : public Batiment {
public:
    Boulangerie();
    void declencher_effet();
};

#endif //MACHI_KORO_BOULANGERIE_H
