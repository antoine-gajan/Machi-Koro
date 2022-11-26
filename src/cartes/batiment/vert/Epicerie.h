#ifndef MACHI_KORO_EPICERIE_H
#define MACHI_KORO_EPICERIE_H

#include "../Batiment.h"

class Epicerie : public Batiment {
public:
    Epicerie(string path_image);
    /* A faire plus tard
    virtual void declencher_effet(*Joueur[] tab_joueurs);
     */
};

#endif //MACHI_KORO_EPICERIE_H
