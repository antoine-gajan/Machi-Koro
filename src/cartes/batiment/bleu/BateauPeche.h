#ifndef MACHI_KORO_MASTER_BATEAUPECHE_H
#define MACHI_KORO_MASTER_BATEAUPECHE_H

#include "../Batiment.h"
#include "Port.h"
#include "Joueur.h"
#include <list>
#include <vector>

class BateauPeche : public Batiment{
public:
    BateauPeche(string& path_image);
    void declencher_effet(Joueur* joueur_actuel);
};

#endif //MACHI_KORO_MASTER_BATEAUPECHE_H
