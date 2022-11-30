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
    void declencher_effet() const;
};

#endif //MACHI_KORO_HALLE_DE_MARCHE_H
