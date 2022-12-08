#ifndef MACHI_KORO_ENTREPRISE_DE_DEMENAGEMENT_H
#define MACHI_KORO_ENTREPRISE_DE_DEMENAGEMENT_H

#include "../Batiment.h"
#include "Joueur.h"
#include "../controleur/utils.h"
#include <list>
#include <vector>

class EntrepriseDeDemenagement : public Batiment {
public:
    EntrepriseDeDemenagement();
    EntrepriseDeDemenagement(const EntrepriseDeDemenagement& entrepriseDeDemenagement) = default;
    Batiment* clone() const override {return new EntrepriseDeDemenagement(*this);};
    void declencher_effet() const;
};

#endif //MACHI_KORO_ENTREPRISE_DE_DEMENAGEMENT_H
