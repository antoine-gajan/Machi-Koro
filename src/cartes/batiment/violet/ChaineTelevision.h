#ifndef MACHI_KORO_CHAINETELEVISION_H
#define MACHI_KORO_CHAINETELEVISION_H

#include <vector>
#include "Batiment.h"

class ChaineTelevision : public Batiment {
public:
    ChaineTelevision();
    ~ChaineTelevision() override = default;
    ChaineTelevision(const ChaineTelevision& chaineTelevision) = default;
    Batiment* clone() const override {return new ChaineTelevision(*this);};
    void declencher_effet(unigned int possesseur) const override;
};

#endif //MACHI_KORO_CHAINETELEVISION_H
