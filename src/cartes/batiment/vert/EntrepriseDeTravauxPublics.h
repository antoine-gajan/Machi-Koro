#ifndef MACHI_KORO_ENTREPRISE_DE_TRAVAUX_PUBLICS_H
#define MACHI_KORO_ENTREPRISE_DE_TRAVAUX_PUBLICS_H

#include "Batiment.h"
#include "Joueur.h"
#include "utils.h"
#include "algorithm"
#include <list>
#include <vector>

class EntrepriseDeTravauxPublics : public Batiment {
public:
    EntrepriseDeTravauxPublics();
    EntrepriseDeTravauxPublics(const EntrepriseDeTravauxPublics& entrepriseDeTravauxPublics) = default;
    Batiment* clone() const override {return new EntrepriseDeTravauxPublics(*this);};
    void declencher_effet() const;
};

#endif //MACHI_KORO_ENTREPRISE_DE_TRAVAUX_PUBLICS_H
