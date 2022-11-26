#ifndef MACHI_KORO_ENTREPRISE_DE_DEMENAGEMENT_H
#define MACHI_KORO_ENTREPRISE_DE_DEMENAGEMENT_H

#include "../Batiment.h"
#include "Joueur.h"
#include "../controleur/utils.h"
#include <list>
#include <vector>

class EntrepriseDeDemenagement : public Batiment {
public:
    EntrepriseDeDemenagement(string path_image);
    virtual void declencher_effet(vector<Joueur*>& tab_joueurs, unsigned int joueur_actuel);
};

#endif //MACHI_KORO_ENTREPRISE_DE_DEMENAGEMENT_H
