#ifndef MACHI_KORO_MASTER_MINE_H
#define MACHI_KORO_MASTER_MINE_H

#include "../Batiment.h"
#include "Joueur.h"
#include <list>
#include <vector>

class Mine : public Batiment{
public:
    Mine(string& path_image);
    virtual void declencher_effet(Joueur* joueur_affecté);
};
#endif //MACHI_KORO_MASTER_MINE_H
