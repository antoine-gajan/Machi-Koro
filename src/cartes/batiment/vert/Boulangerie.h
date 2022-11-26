#ifndef MACHI_KORO_BOULANGERIE_H
#define MACHI_KORO_BOULANGERIE_H

#include "../Batiment.h"
#include "Joueur.h"
#include <list>
#include <vector>

class Boulangerie : public Batiment {
public:
    Boulangerie(const string& path_image);
    virtual void declencher_effet(vector<Joueur*>& tab_joueurs, unsigned int joueur_actuel);
};

#endif //MACHI_KORO_BOULANGERIE_H
