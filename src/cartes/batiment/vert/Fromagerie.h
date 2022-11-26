#ifndef MACHI_KORO_FROMAGERIE_H
#define MACHI_KORO_FROMAGERIE_H

#include "../Batiment.h"
#include "Joueur.h"
#include "../controleur/utils.h"
#include <list>
#include <vector>

class Fromagerie : public Batiment {
public:
    Fromagerie(const string& path_image);
    virtual void declencher_effet(vector<Joueur*>& tab_joueurs, unsigned int joueur_actuel);
};

#endif //MACHI_KORO_FROMAGERIE_H
