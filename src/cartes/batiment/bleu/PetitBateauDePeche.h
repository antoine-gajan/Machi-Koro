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
    void declencher_effet() const;
};

#endif //MACHI_KORO_MASTER_BATEAUPECHE_H