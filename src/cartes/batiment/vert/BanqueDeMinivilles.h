#ifndef MACHI_KORO_BANQUE_DE_MINIVILLES_H
#define MACHI_KORO_BANQUE_DE_MINIVILLES_H

#include "../Batiment.h"

class BanqueDeMinivilles : public Batiment {
public:
    BanqueDeMinivilles(string path_image);
    /* A faire plus tard
    virtual void declencher_effet(*Joueur[] tab_joueurs);
     */
};

#endif //MACHI_KORO_BANQUE_DE_MINIVILLES_H
