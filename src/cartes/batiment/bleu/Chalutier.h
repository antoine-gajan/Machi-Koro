#ifndef MACHI_KORO_MASTER_CHALUTIER_H
#define MACHI_KORO_MASTER_CHALUTIER_H

#include "Port.h"
#include "../Batiment.h"
#include "Joueur.h"
#include <list>
#include <vector>

class Chalutier : public Batiment{
public:
    Chalutier(const string& path_image);
    virtual void declencher_effet(Joueur* joueur_actuel);
};
#endif //MACHI_KORO_MASTER_CHALUTIER_H
