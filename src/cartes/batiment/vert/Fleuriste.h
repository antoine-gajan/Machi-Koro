#ifndef MACHI_KORO_FLEURISTE_H
#define MACHI_KORO_FLEURISTE_H

#include "../Batiment.h"
#include "Joueur.h"
#include "../controleur/utils.h"
#include <list>
#include <vector>

class Fleuriste : public Batiment {
public:
    Fleuriste(const string& path_image);
    virtual void declencher_effet(vector<Joueur*>& tab_joueurs, unsigned int joueur_actuel);
};

#endif //MACHI_KORO_FLEURISTE_H
