#ifndef MACHI_KORO_CENTREAFFAIRES_H
#define MACHI_KORO_CENTREAFFAIRES_H

#include "Batiment.h"
#include "Joueur.h"
#include <list>
#include <vector>

class CentreAffaires : public Batiment {
public:
    CentreAffaires();
    virtual void declencher_effet() const;
};

#endif //MACHI_KORO_CENTREAFFAIRES_H
