#ifndef MACHI_KORO_MOONSTER_SODA_H
#define MACHI_KORO_MOONSTER_SODA_H

#include "../Batiment.h"
#include "Joueur.h"
#include "../controleur/utils.h"
#include <list>
#include <vector>

class MoonsterSoda : public Batiment {
public:
    MoonsterSoda();
    ~MoonsterSoda() override = default;
    MoonsterSoda(const MoonsterSoda& moonsterSoda) = default;
    Batiment* clone() const override {return new MoonsterSoda(*this);};
    void declencher_effet(unigned int possesseur) const override;
};

#endif //MACHI_KORO_MOONSTER_SODA_H
