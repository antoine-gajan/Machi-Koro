#ifndef MACHI_KORO_HALLE_DE_MARCHE_H
#define MACHI_KORO_HALLE_DE_MARCHE_H

#include "../Batiment.h"
#include "Joueur.h"
#include "../controleur/utils.h"
#include <list>
#include <vector>

class HalleDeMarche : public Batiment {
public:
    HalleDeMarche();
    virtual void declencher_effet();
};

#endif //MACHI_KORO_HALLE_DE_MARCHE_H
