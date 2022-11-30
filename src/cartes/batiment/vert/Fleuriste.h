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
    void declencher_effet() const;
};

#endif //MACHI_KORO_FLEURISTE_H
