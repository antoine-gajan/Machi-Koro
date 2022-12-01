#ifndef SRC_ENTREPRISERENOVATION_H
#define SRC_ENTREPRISERENOVATION_H

#include "Batiment.h"

class EntrepriseRenovation : public Batiment {
public:
    EntrepriseRenovation();
    void declencher_effet() const;
};

#endif //SRC_ENTREPRISERENOVATION_H
