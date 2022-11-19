#ifndef MACHI_KORO_CHAINETELEVISION_H
#define MACHI_KORO_CHAINETELEVISION_H

#include <vector>
#include "../Batiment.h"
#include "././Joueur.h"

class ChaineTelevision : public Batiment {
public:
    ChaineTelevision(const string& path_image);
    virtual void declencher_effet(vector<Joueur*>& tab_joueurs, unsigned int joueur_actuel);
};

#endif //MACHI_KORO_CHAINETELEVISION_H
