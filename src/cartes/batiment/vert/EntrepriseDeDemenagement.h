#ifndef MACHI_KORO_ENTREPRISE_DE_DEMENAGEMENT_H
#define MACHI_KORO_ENTREPRISE_DE_DEMENAGEMENT_H

#include "../Batiment.h"

class EntrepriseDeDemenagement : public Batiment {
public:
    EntrepriseDeDemenagement(string path_image);
    /* A faire plus tard
    virtual void declencher_effet(*Joueur[] tab_joueurs);
     */
};

#endif //MACHI_KORO_ENTREPRISE_DE_DEMENAGEMENT_H
