#ifndef MACHI_KORO_BANQUE_DE_MINIVILLES_H
#define MACHI_KORO_BANQUE_DE_MINIVILLES_H

#include "../Batiment.h"
#include "Joueur.h"
#include "../controleur/utils.h"
#include <list>
#include <vector>

class BanqueDeMinivilles : public Batiment {
public:
    BanqueDeMinivilles();
    void declencher_effet();

};

#endif //MACHI_KORO_BANQUE_DE_MINIVILLES_H
