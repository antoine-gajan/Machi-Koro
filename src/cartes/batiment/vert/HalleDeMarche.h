#ifndef MACHI_KORO_HALLE_DE_MARCHE_H
#define MACHI_KORO_HALLE_DE_MARCHE_H

#include "../Batiment.h"

class HalleDeMarche : public Batiment {
public:
    HalleDeMarche(string path_image);
    /* A faire plus tard
    virtual void declencher_effet(*Joueur[] tab_joueurs);
     */
};

#endif //MACHI_KORO_HALLE_DE_MARCHE_H
