#ifndef MACHI_KORO_CHAINETELEVISION_H
#define MACHI_KORO_CHAINETELEVISION_H

#include <vector>
#include "Batiment.h"
#include "Joueur.h"

class ChaineTelevision : public Batiment {
public:
    ChaineTelevision();
    virtual void declencher_effet() const;
};

#endif //MACHI_KORO_CHAINETELEVISION_H
