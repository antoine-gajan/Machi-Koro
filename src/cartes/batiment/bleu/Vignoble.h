#ifndef MACHI_KORO_VIGNOBLE_H
#define MACHI_KORO_VIGNOBLE_H

#include "../Batiment.h"
#include "Joueur.h"
#include <list>
#include <vector>

class Vignoble : public Batiment{
public:
    Vignoble(string& path_image);
    virtual void declencher_effet(Joueur* joueur_affecté);
};
#endif //MACHI_KORO_VIGNOBLE_H
