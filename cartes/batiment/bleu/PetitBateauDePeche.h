#ifndef MACHI_KORO_MASTER_BATEAUPECHE_H
#define MACHI_KORO_MASTER_BATEAUPECHE_H

#include "Batiment.h"
//#include "Port.h"
//#include "Joueur.h"
//#include "Partie.h"
#include <list>
#include <vector>

class PetitBateauDePeche : public Batiment{
public:
    PetitBateauDePeche();
    ~PetitBateauDePeche() override = default;
    PetitBateauDePeche(const PetitBateauDePeche& petitBateauDePeche) = default;
    Batiment* clone() const override {return new PetitBateauDePeche(*this);};
    void declencher_effet(unsigned int possesseur, int bonus = 0) const override;
};

#endif //MACHI_KORO_MASTER_BATEAUPECHE_H
