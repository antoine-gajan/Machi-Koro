#ifndef MACHI_KORO_ENTREPRISE_DE_TRAVAUX_PUBLICS_H
#define MACHI_KORO_ENTREPRISE_DE_TRAVAUX_PUBLICS_H

#include "../Batiment.h"
#include "Joueur.h"
#include "../controleur/utils.h"
#include <list>
#include <vector>

class EntrepriseDeTravauxPublics : public Batiment {
public:
    EntrepriseDeTravauxPublics(const string& path_image);
    virtual void declencher_effet(vector<Joueur*>& tab_joueurs, unsigned int joueur_actuel);
};

#endif //MACHI_KORO_ENTREPRISE_DE_TRAVAUX_PUBLICS_H
