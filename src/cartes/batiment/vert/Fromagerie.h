#ifndef MACHI_KORO_FROMAGERIE_H
#define MACHI_KORO_FROMAGERIE_H

#include "../Batiment.h"
#include "Joueur.h"
#include "../controleur/utils.h"
#include <list>
#include <vector>

class Fromagerie : public Batiment {
public:
    Fromagerie();
    void declencher_effet();
};

#endif //MACHI_KORO_FROMAGERIE_H
