#ifndef MACHI_KORO_EPICERIE_H
#define MACHI_KORO_EPICERIE_H

#include "../Batiment.h"
#include "Joueur.h"
#include "../controleur/utils.h"
#include <list>
#include <vector>

class Epicerie : public Batiment {
public:
    Epicerie(string path_image);
    virtual void declencher_effet(vector<Joueur*>& tab_joueurs, unsigned int joueur_actuel);

};

#endif //MACHI_KORO_EPICERIE_H
