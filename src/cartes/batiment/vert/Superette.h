#ifndef MACHI_KORO_SUPERETTE_H
#define MACHI_KORO_SUPERETTE_H

#include "../Batiment.h"
#include "Joueur.h"
#include "../controleur/utils.h"
#include <list>
#include <vector>

class Superette : public Batiment {
public:
    Superette();
    void declencher_effet() const;
};

#endif //MACHI_KORO_SUPERETTE_H
