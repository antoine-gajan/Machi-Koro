#ifndef MACHI_KORO_MASTER_VERGER_H
#define MACHI_KORO_MASTER_VERGER_H

#include "../Batiment.h"
#include "Joueur.h"
#include <list>
#include <vector>

class Verger : public Batiment{
public:
    Verger(string& path_image);
    virtual void declencher_effet(Joueur* joueur_affecté);
};
#endif //MACHI_KORO_MASTER_VERGER_H
