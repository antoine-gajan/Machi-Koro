#ifndef MACHI_KORO_FABRIQUE_DE_MEUBLES_H
#define MACHI_KORO_FABRIQUE_DE_MEUBLES_H

#include "../Batiment.h"
#include "Joueur.h"
#include "../controleur/utils.h"
#include <list>
#include <vector>

class FabriqueDeMeubles : public Batiment {
public:
    FabriqueDeMeubles(string path_image);
    virtual void declencher_effet(vector<Joueur*>& tab_joueurs, unsigned int joueur_actuel);
};

#endif //MACHI_KORO_FABRIQUE_DE_MEUBLES_H
