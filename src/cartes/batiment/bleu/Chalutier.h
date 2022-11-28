#ifndef MACHI_KORO_MASTER_CHALUTIER_H
#define MACHI_KORO_MASTER_CHALUTIER_H

#include "Port.h"
#include "../Batiment.h"
#include "Joueur.h"
#include "utils.h"
#include <list>
#include <vector>

class Chalutier : public Batiment{
public:
    Chalutier(const string& path_image);
    virtual void declencher_effet(Joueur* joueur_actuel,unsigned int val_des);
};
#endif //MACHI_KORO_MASTER_CHALUTIER_H
