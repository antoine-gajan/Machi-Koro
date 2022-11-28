#ifndef MACHI_KORO_CHAMPBLE_H
#define MACHI_KORO_CHAMPBLE_H

#include "../Batiment.h"
#include "Joueur.h"
#include <list>
#include <vector>

class ChampBle : public Batiment{
public:
    ChampBle(const string& path_image);
    virtual void declencher_effet(Joueur* joueur_affecté);
};

#endif //MACHI_KORO_CHAMPBLE_H
