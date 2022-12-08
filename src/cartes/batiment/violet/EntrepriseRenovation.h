#ifndef SRC_ENTREPRISERENOVATION_H
#define SRC_ENTREPRISERENOVATION_H

#include "Batiment.h"

class EntrepriseRenovation : public Batiment {
public:
    EntrepriseRenovation();
    EntrepriseRenovation(const EntrepriseRenovation& entrepriseRenovation) = default;
    Batiment* clone() const override {return new EntrepriseRenovation(*this);};
    void declencher_effet() const;
};

#endif //SRC_ENTREPRISERENOVATION_H
