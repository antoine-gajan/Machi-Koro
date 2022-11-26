#ifndef MACHI_KORO_ENTREPRISE_DE_TRAVAUX_PUBLICS_H
#define MACHI_KORO_ENTREPRISE_DE_TRAVAUX_PUBLICS_H

#include "../Batiment.h"

class EntrepriseDeTravauxPublics : public Batiment {
public:
    EntrepriseDeTravauxPublics(string path_image);
    /* A faire plus tard
    virtual void declencher_effet(*Joueur[] tab_joueurs);
     */
};

#endif //MACHI_KORO_ENTREPRISE_DE_TRAVAUX_PUBLICS_H
