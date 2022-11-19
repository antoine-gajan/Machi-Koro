#ifndef MACHI_KORO_STADE_H
#define MACHI_KORO_STADE_H

#include <vector>
#include "../Batiment.h"
#include "./././Joueur.h"

class Stade : public Batiment {
public:
    Stade(string& path_image);
    virtual void declencher_effet(vector<Joueur*>& tab_joueurs, unsigned int joueur_actuel);
};

#endif //MACHI_KORO_STADE_H
