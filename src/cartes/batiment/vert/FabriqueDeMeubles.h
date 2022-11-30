#ifndef MACHI_KORO_FABRIQUE_DE_MEUBLES_H
#define MACHI_KORO_FABRIQUE_DE_MEUBLES_H

#include "../Batiment.h"
#include "Joueur.h"
#include "../controleur/utils.h"
#include <list>
#include <vector>

class FabriqueDeMeubles : public Batiment {
public:
    FabriqueDeMeubles();
    void declencher_effet() const;
};

#endif //MACHI_KORO_FABRIQUE_DE_MEUBLES_H
