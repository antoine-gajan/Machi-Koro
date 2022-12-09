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
    void declencher_effet(unigned int possesseur) const override;
};

#endif //MACHI_KORO_MASTER_BATEAUPECHE_H
