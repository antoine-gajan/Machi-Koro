#ifndef MACHI_KORO_CENTREAFFAIRES_H
#define MACHI_KORO_CENTREAFFAIRES_H

#include "../Batiment.h"
#include "Joueur.h"
#include <list>
#include <vector>

class CentreAffaires : public Batiment {
public:
    CentreAffaires(const string& path_image);
    virtual void declencher_effet(vector<Joueur*>& tab_joueurs, unsigned int joueur_actuel);
};

#endif //MACHI_KORO_CENTREAFFAIRES_H
