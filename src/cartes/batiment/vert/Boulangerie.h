#ifndef MACHI_KORO_BOULANGERIE_H
#define MACHI_KORO_BOULANGERIE_H

#include "../Batiment.h"

class Boulangerie : public Batiment {
public:
    Boulangerie(string path_image);
    /* A faire plus tard
    virtual void declencher_effet(*Joueur[] tab_joueurs);
     */
};

#endif //MACHI_KORO_BOULANGERIE_H
