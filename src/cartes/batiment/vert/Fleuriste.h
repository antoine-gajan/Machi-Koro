#ifndef MACHI_KORO_FLEURISTE_H
#define MACHI_KORO_FLEURISTE_H

#include "../Batiment.h"
#include "Joueur.h"
#include "../controleur/utils.h"
#include <list>
#include <vector>

class Fleuriste : public Batiment {
public:
    Fleuriste();
    virtual void declencher_effet();
};

#endif //MACHI_KORO_FLEURISTE_H