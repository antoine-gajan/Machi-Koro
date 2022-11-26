#ifndef MACHI_KORO_HALLE_DE_MARCHE_H
#define MACHI_KORO_HALLE_DE_MARCHE_H

#include "../Batiment.h"
#include "Joueur.h"
#include "../controleur/utils.h"
#include <list>
#include <vector>

class HalleDeMarche : public Batiment {
public:
    HalleDeMarche(const string& path_image);
    virtual void declencher_effet(vector<Joueur*>& tab_joueurs, unsigned int joueur_actuel);
};

#endif //MACHI_KORO_HALLE_DE_MARCHE_H
