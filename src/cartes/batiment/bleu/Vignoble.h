#ifndef MACHI_KORO_VIGNOBLE_H
#define MACHI_KORO_VIGNOBLE_H

#include "Batiment.h"
//#include "Joueur.h"
#include <list>
#include <vector>

class Vignoble : public Batiment{
public:
    Vignoble();
    void declencher_effet() const;
};
#endif //MACHI_KORO_VIGNOBLE_H
