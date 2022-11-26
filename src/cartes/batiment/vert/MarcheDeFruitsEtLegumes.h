#ifndef MACHI_KORO_MARCHE_DE_FRUITS_ET_LEGUMES_H
#define MACHI_KORO_MARCHE_DE_FRUITS_ET_LEGUMES_H

#include "../Batiment.h"
#include "Joueur.h"
#include "../controleur/utils.h"
#include <list>
#include <vector>

class MarcheDeFruitsEtLegumes : public Batiment {
public:
    MarcheDeFruitsEtLegumes(const string& path_image);
    virtual void declencher_effet(vector<Joueur*>& tab_joueurs, unsigned int joueur_actuel);
};

#endif //MACHI_KORO_MARCHE_DE_FRUITS_ET_LEGUMES_H
